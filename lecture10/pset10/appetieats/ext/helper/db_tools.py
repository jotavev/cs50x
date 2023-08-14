from appetieats.models import Products


def add_new_product(product_data, product_image):
    new_product = Products(
            product_data['name']
            )
    return
