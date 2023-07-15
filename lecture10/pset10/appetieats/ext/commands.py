from appetieats.ext.database import db
from appetieats.models import Users


def create_db():
    """create sql database"""
    db.create_all()


def drop_db():
    """drop sql database"""
    db.drop_all()


def populate_users():
    """populate db users with default acconts"""
    data = [
            Users(
                id=1,
                username="master",
                hash="123"
                )
            ]
    db.session.bulk_save_objects(data)
    db.session.commit()
    return Users.query.all()


def hello_commands():
    """says hello"""
    print("hello commands")


def init_app(app):
    """add multiple commands in a bulk"""
    for command in [create_db,
                    drop_db,
                    populate_users,
                    hello_commands]:
        app.cli.add_command(app.cli.command()(command))
    return app
