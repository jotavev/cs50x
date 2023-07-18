from flask import Blueprint, render_template, flash, request, abort, redirect
from appetieats.ext.helpers import register_user, verify_user_register_data

main_bp = Blueprint('main', __name__)


@main_bp.route("/")
def index():
    """Show the landing page"""
    return render_template("landing.html")


@main_bp.route("/register", methods=["GET", "POST"])
def register():
    """Register a new restaurant"""
    if request.method == "POST":
        print("POST")
        username = request.form.get("username")
        password = request.form.get("password")
        confirm = request.form.get("confirm")

        a = verify_user_register_data(username, password, confirm)
        if a == "Registred!":
            # register_user(username, password)
            flash(f"{a}", "success")
            return redirect("/login")
        else:
            abort(403, f"{a}")
    else:
        print("GET")
        return render_template("register.html")


@main_bp.route("/login")
def login():
    """Login user"""
    return render_template("login.html")
