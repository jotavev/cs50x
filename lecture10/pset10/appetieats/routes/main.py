from flask import render_template
from flask import Blueprint

main_bp = Blueprint('main', __name__)


@main_bp.route("/")
def index():
    """Show the landing page"""
    return render_template("landing.html")
