from appetieats.models import Products, ProductImages
from appetieats.ext.database import db


def add_new_product(product_data, product_image):
    new_product = Products(
            name=product_data['name'],
            description=product_data['description'],
            price=product_data['price'],
            available="true",
            category_id=product_data['category'],
            image_id=1
    )
    db.session.add(new_product)
    db.session.commit()
    product_id = new_product.id
    image_name = f'product{product_id}';
    new_image = ProductImages(
            product_id=product_id,
            image_path=image_name,
            image_data=image_data
    )
    return
