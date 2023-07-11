from dynaconf import FlaskDynaconf
from flask import Flask, render_template
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
FlaskDynaconf(app)
db = SQLAlchemy(app)


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/<restaurant-name>")
def menu():
    return render_template("restaurant-menu.html")
