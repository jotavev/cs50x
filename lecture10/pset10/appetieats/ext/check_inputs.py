from flask import abort
from appetieats.models import Categories


def check_add_inputs(name, price, barcode, category, image):
    if not name:
        return abort(403, "You must provide a product name")

    elif not price:
        return abort(403, "You must provide a price")

    elif not barcode:
        return abort(403, "You must provide a barcode")

    elif not category:
        return abort(403, "The must provide a category")

    elif not image:
        return abort(403, "The must provide a image")

    elif Categories.query.filter_by(category=category).first() is None:
        return abort(403, "category dont exists")

    else:
        return
