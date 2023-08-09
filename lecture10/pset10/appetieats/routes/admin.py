from flask import Blueprint, render_template, request

from appetieats.ext.helpers import login_required

admin_bp = Blueprint('admin', __name__)


@admin_bp.route("/admin")
@login_required
def admin():
    return render_template("admin/admin.html")


@admin_bp.route("/admin/dashboard")
@login_required
def dashboard():
    return render_template("admin/dashboard.html")


@admin_bp.route("/admin/edit-menu")
@login_required
def edit_menu():
    return render_template("admin/edit-menu.html")


@admin_bp.route("/admin/settings")
@login_required
def settings():
    return render_template("admin/settings.html")


@admin_bp.route("/admin/settings/add", methods=["GET", "POST"])
@login_required
def add():
    """Add new product"""
    if request.method == "POST":
        print("POST")
        return "POST"
        return redirect("/admin/add")
    return render_template("admin/settings/add.html")
