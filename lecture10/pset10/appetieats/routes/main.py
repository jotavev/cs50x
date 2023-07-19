from flask import (Blueprint, render_template, flash, request, abort, redirect,
                   session)
from appetieats.ext.helpers import (login_required, verify_user_register_data,
                                    check_credentials, register_user, log_user)

main_bp = Blueprint('main', __name__)


@main_bp.route("/")
def index():
    """Show the landing page"""
    return render_template("landing.html")


@main_bp.route("/register", methods=["GET", "POST"])
def register():
    """Register a new restaurant"""
    if request.method == "POST":
        username, password, confirm = (
                request.form.get("username", type=str),
                request.form.get("password", type=str),
                request.form.get("confirm", type=str)
        )

        verify_user_register_data(username, password, confirm)
        register_user(username, password)

        # TODO: redirect to admin page of restaurant
        return redirect("/restaurant-setup")
    else:
        return render_template("register.html")


@main_bp.route("/login", methods=["GET", "POST"])
def login():
    """Login user"""
    session.clear()

    if request.method == "POST":
        username, password = (
                request.form.get("username", type=str),
                request.form.get("password", type=str)
        )
        check_credentials(username, password)
        log_user(username)
        print(session.get("user_id"))
        return redirect("/restaurant-setup")
    else:
        return render_template("login.html")


@main_bp.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to /
    return redirect("/")


@main_bp.route("/restaurant-setup")
@login_required
def restaurant_setup():
    return render_template("restaurant-setup.html")


@main_bp.route("/error")
def error():
    """Error message page"""
    a = None
    if not a:
        abort(404, "Error page is working! :)")
    return render_template("error.html")
