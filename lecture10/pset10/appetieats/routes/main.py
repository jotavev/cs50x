from flask import render_template
from flask import Blueprint

main_bp = Blueprint('main', __name__)


@main_bp.route("/")
def index():
    """Show the landing page"""
    return render_template("landing.html")


@main_bp.route("/register")
def register():
    """Register a new restaurant"""
    return render_template("register.html")


@main_bp.route("/login")
def login():
    """Login user"""
    return render_template("login.html")
