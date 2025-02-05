import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime
from flask import jsonify

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]
    portifolio_data = db.execute("SELECT * FROM users_stocks "
                                 " WHERE user_id = ?", user_id)
    cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    cash = usd(cash[0]["cash"])
    return render_template("index.html",
                           portifolio_data=portifolio_data, cash=cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":

        query = request.form.get("query")
        quantity = request.form.get("qty")

        if not query:
            return apology("must provide a stock symbol", 400)

        elif not quantity:
            return apology("must provide a stock quantity", 400)

        elif int(quantity) < 1:
            return apology("quantity cannot be lowwer than one", 400)

        reply = lookup(query)

        if not reply:
            return apology("check the symbol stocks", 400)

        else:
            user_id = session["user_id"]
            stock_name = reply["name"]
            stock_price = reply["price"]
            stock_symbol = reply["symbol"]
            transaction_type = "BUY"

            total_stock_price = stock_price * int(quantity)
            date_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

            user_balance = db.execute(
                    "SELECT cash FROM users WHERE id = ?",
                    session["user_id"])

            user_balance = user_balance[0]["cash"]

            if user_balance < total_stock_price:
                return apology("You have no funds available "
                               "to support this request", 403)
            else:
                # insert the transaction in table transactions
                db.execute("INSERT INTO transactions "
                           "(user_id, date, stock_symbol, stock_name, "
                           "price_per_share, quantity, type) "
                           "VALUES(?, ?, ?, ?, ?, ?, ?)",
                           user_id, date_time, stock_symbol, stock_name,
                           stock_price, quantity, transaction_type)

                check_user_stock = db.execute("SELECT * FROM users_stocks "
                                              "WHERE user_id = ? "
                                              "AND stock_symbol = ?",
                                              user_id, stock_symbol)

                db.execute("UPDATE users "
                           "SET cash = cash - ? "
                           "WHERE id = ?",
                           total_stock_price, user_id)

                if check_user_stock:
                    db.execute("UPDATE users_stocks "
                               "SET quantity = quantity + ? "
                               "WHERE user_id = ? "
                               "AND stock_symbol = ?",
                               quantity, user_id, stock_symbol)
                else:
                    db.execute("INSERT INTO users_stocks "
                               "(user_id, stock_symbol, stock_name, quantity) "
                               "VALUES(?, ?, ?, ?)",
                               user_id, stock_symbol, stock_name, quantity)
                flash("Bought!")
                return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]
    history_data = db.execute("SELECT * FROM transactions "
                              "WHERE user_id = ?", user_id)

    for stock in history_data:
        stock["stock_sum"] = usd(float(
            stock["price_per_share"]) * int(stock["quantity"]))
        stock["price_per_share"] = usd(stock["price_per_share"])
    return render_template("history.html", history_data=history_data)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        query = request.form.get("query")
        reply = lookup(query)
        if reply:
            reply["price"] = usd(reply["price"])
            return render_template("quoted.html", reply=reply)
        else:
            return apology("Stock symbol not found", 400)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    def register_new_user(username, password):
        psw_hash = generate_password_hash(password)
        db.execute(
                "INSERT INTO users (username, hash) VALUES(?, ?)",
                username, psw_hash)

    if request.method == "POST":
        # take the user fields
        user = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # verify the user data
        if not user:
            return apology("Insert a username", 400)
        elif password != confirmation:
            return apology("Passwords do not match", 400)
        elif user:
            search_user = db.execute(
                    "SELECT * FROM users WHERE username = ?", (user,))
            if search_user:
                return apology("The username already exists", 400)
            # register a new user
            else:
                register_new_user(user, password)
                flash("Registered!")
                return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":

        select = request.form.get("select")
        quantity = request.form.get("qty")

        if not select:
            return apology("must provide a stock symbol", 400)

        elif not quantity:
            return apology("must provide a stock quantity", 400)

        elif (int(quantity) < 1):
            return apology("quantity cannot be lowwer than one", 400)

        reply = lookup(select)

        if not reply:
            return apology("check the symbol stocks", 400)

        else:
            user_id = session["user_id"]
            stock_name = reply["name"]
            stock_price = reply["price"]
            stock_symbol = reply["symbol"]
            transaction_type = "SELL"

            total_stock_price = stock_price * int(quantity)
            date_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

            total_stock_user = db.execute(
                    "SELECT quantity FROM users_stocks "
                    "WHERE stock_symbol = ? "
                    "AND user_id = ?",
                    stock_symbol,
                    user_id)
            total_stock_user = total_stock_user[0]["quantity"]

            if not total_stock_user or int(quantity) > total_stock_user:
                return apology("You have no enough stocks "
                               "to support this request", 400)
            else:
                # insert the transaction in table transactions
                db.execute("INSERT INTO transactions "
                           "(user_id, date, stock_symbol, stock_name, "
                           "price_per_share, quantity, type) "
                           "VALUES(?, ?, ?, ?, ?, ?, ?)",
                           user_id, date_time, stock_symbol, stock_name,
                           stock_price, quantity, transaction_type)

                # update the cash of user
                db.execute("UPDATE users "
                           "SET cash = cash + ? "
                           "WHERE id = ?",
                           total_stock_price, user_id)

                # update the stocks remaining of user
                db.execute("UPDATE users_stocks "
                           "SET quantity = quantity - ? "
                           "WHERE user_id = ? "
                           "AND stock_symbol = ?",
                           quantity, user_id, stock_symbol)

                # checking the remaining amount of the stock sold
                stock_qty = db.execute("SELECT quantity FROM users_stocks "
                                       "WHERE user_id = ? "
                                       "AND stock_symbol = ?",
                                       user_id, stock_symbol)
                stock_qty = stock_qty[0]["quantity"]

                # removing from table users_stocks if equal to 0
                if stock_qty == 0:
                    db.execute("DELETE FROM users_stocks WHERE user_id = ? "
                               "AND stock_symbol = ?", user_id, stock_symbol)
                flash("Sold!")
                return redirect("/")
    else:
        user_id = session["user_id"]
        stocks = db.execute("SELECT stock_symbol "
                            "FROM users_stocks "
                            "WHERE user_id = ?",
                            user_id)
        return render_template("sell.html", stocks=stocks)


@app.route("/stock_price", methods=["GET", "POST"])
@login_required
def stock_price():
    """Take the stocks price in API"""
    user_id = session["user_id"]
    stock_symbols = db.execute("SELECT stock_symbol "
                               "FROM users_stocks WHERE user_id = ?", user_id)
    prices = {}

    for stock in stock_symbols:
        symbol = stock["stock_symbol"]
        request_data = lookup(symbol)
        prices[symbol] = request_data["price"]
    return jsonify(prices)
