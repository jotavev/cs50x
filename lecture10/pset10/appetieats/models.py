from appetieats.ext.database import db
from sqlalchemy_serializer import SerializerMixin


class Users(db.Model, SerializerMixin):
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    username = db.Column(db.String(200), nullable=False, unique=True)
    hash = db.Column(db.String(120), nullable=False)


class Product(db.Model, SerializerMixin):
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    name = db.Column(db.String(200), nullable=False)
    description = db.Column(db.Text)
    price = db.Column(db.Float, nullable=False)
    available = db.Column(db.String(5), nullable=False)
    category_id = db.Column(db.Integer, db.ForeignKey('categories.id'))
    image_id = db.Column(db.Integer, db.ForeignKey(
        'product_images.id', use_alter=True))


class Categories(db.Model, SerializerMixin):
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    category_name = db.Column(db.String(200), nullable=False)


class ProductImages(db.Model):
    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    product_id = db.Column(db.Integer, db.ForeignKey(
        'products.id', use_alter=True))
    image_path = db.Column(db.String(200), nullable=False)
    image_data = db.Column(db.LargeBinary, nullable=False)
