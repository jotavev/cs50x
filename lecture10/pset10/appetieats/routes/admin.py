from flask import Blueprint, render_template, request, redirect
from appetieats.models import Categories
from appetieats.ext.database import db

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


@admin_bp.route("/admin/settings/manage-categories", methods=["GET", "POST"])
@login_required
def manage_categories():
    """Manage categories"""
    if request.method == "POST":
        category = request.form.get("category", type=str)
        print(category)
        print("POST")
        new_category = Categories(category_name=category)
        db.session.add(new_category)
        db.session.commit()
        return redirect("/admin/settings/manage-categories")
    else:
        categories = Categories.query.all()
        print(categories)
    return render_template("admin/settings/manage-categories.html", categories=categories)


@admin_bp.route("/admin/settings/manage-categories/delete", methods=["POST"])
@login_required
def delete_category():
    """Delete a category"""
    id = request.form.get("id")
    category = Categories.query.filter_by(id=id).first()
    print(category)
    db.session.delete(category)
    db.session.commit()
    return redirect("/admin/settings/manage-categories")
