from functools import wraps
from flask import redirect, session
from appetieats.models import Users
from appetieats.ext.database import db
from werkzeug.security import generate_password_hash


def login_required(f):
    """
    Decorate routes to require login.

    https://flask.palletsprojects.com/en/1.1.x/patterns/viewdecorators/
    """
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)
    return decorated_function


def register_user(username, password):
    psw_hash = generate_password_hash(password)
    new_user = Users(username=username, hash=psw_hash)
    db.session.add(new_user)
    db.session.commit()


def verify_user_register_data(username, password, confirm):
    if not username:
        return "Insert a username"
    elif not password:
        return "Insert a username"
    elif not confirm:
        return "Insert a username"
    elif password != confirm:
        return "Insert a username"
    else:
        return "Registred!"
