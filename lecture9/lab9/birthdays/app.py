from cs50 import SQL
from flask import Flask, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # Add the user's entry into the database
        name = request.form.get("name")
        date = request.form.get("date")

        if name and date:
            month, day = date.split('-')[1:]
            db.execute(
                "INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)",
                name, month, day)
        return redirect("/")

    else:
        # Display the entries in the database on index.html

        birthdays_data = db.execute("SELECT * FROM birthdays;")

        return render_template("index.html", birthdays_data=birthdays_data)


@app.route("/delete", methods=["POST"])
def delete():
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM birthdays WHERE id = ?", id)
    return redirect("/")
