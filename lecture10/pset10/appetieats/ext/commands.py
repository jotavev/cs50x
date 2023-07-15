from appetieats.ext.database import db


def hello():
    """says hello"""
    print("hello commands")


def create_db():
    """create sql database"""
    db.create_all()


def drop_db():
    """drop sql database"""
    db.drop_all()


def init_app(app):
    """add multiple commands in a bulk"""
    for command in [hello, create_db, drop_db]:
        app.cli.add_command(app.cli.command()(command))

    return app
