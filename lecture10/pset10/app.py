from flask import Flask, render_template

app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/<restaurant-name>")
def menu():
    return render_template("restaurant-menu.html")
