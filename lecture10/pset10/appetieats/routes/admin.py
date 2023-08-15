from flask import Blueprint, render_template, request, redirect, flash
from appetieats.models import Categories, Products
from appetieats.ext.database import db

from appetieats.ext.helpers import login_required
from appetieats.ext.helper.get_inputs import get_product_data_from_request, get_product_image
from appetieats.ext.helper.validate_inputs import validate_product_data, validate_product_image
from appetieats.ext.helper.db_tools import add_new_product

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
        product_data = get_product_data_from_request()
        product_image = get_product_image("image")

        validate_product_data(product_data)
        validate_product_image(product_image)

        add_new_product(product_data, product_image)

        # db.session.add(new_product)
        # db.session.commit()

        flash("Added", "success")
        return redirect("/admin/settings/add")
    else:
        categories = Categories.query.all()
        return render_template("admin/settings/add.html", categories=categories)


@admin_bp.route("/admin/settings/manage-categories", methods=["GET", "POST"])
@login_required
def manage_categories():
    """Manage categories"""
    if request.method == "POST":
        category = request.form.get("category", type=str)
        new_category = Categories(category_name=category)

        db.session.add(new_category)
        db.session.commit()

        return redirect("/admin/settings/manage-categories")
    else:
        categories = Categories.query.all()
    return render_template("admin/settings/manage-categories.html", categories=categories)


@admin_bp.route("/admin/settings/manage-categories/delete", methods=["POST"])
@login_required
def delete_category():
    """Delete a category"""
    id = request.form.get("id")
    category = Categories.query.filter_by(id=id).first()

    db.session.delete(category)
    db.session.commit()

    return redirect("/admin/settings/manage-categories")
