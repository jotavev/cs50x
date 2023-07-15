from flask import Flask, render_template
from appetieats.ext import sesssion

from appetieats.ext import database
from appetieats.ext import commands
from appetieats.ext import configuration

app = Flask(__name__)

commands.init_app(app)
sesssion.init_app(app)
configuration.init_app(app)
database.init_app(app)


@app.route("/")
def index():
    return render_template("landing.html")


@app.route("/test")
def test():
    return render_template("index.html")


"""
@app.route("/<restaurant-name>")
def menu():
"""
