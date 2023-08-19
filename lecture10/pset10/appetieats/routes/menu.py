from flask import Blueprint, render_template
from appetieats.models import RestaurantsData, Users

menu_bp = Blueprint('menu', __name__)


@menu_bp.route("/<restaurant_user>")
def index(restaurant_user):
    """Show the restaurant menu's page"""

    restaurant_info = RestaurantsData.query.join(
            Users, RestaurantsData.user_id == Users.id
            ).filter(Users.username == restaurant_user).first()

    print(restaurant_info)

    restaurant_dict = vars(restaurant_info)
    for attribute, value in restaurant_dict.items():
        print(attribute, ":", value)

    return render_template("menu/menu.html",
                           restaurant_info=restaurant_info)
