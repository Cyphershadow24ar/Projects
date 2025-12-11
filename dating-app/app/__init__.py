from flask import Flask
from flask_sqlalchemy import SQLAlchemy

db = SQLAlchemy()

def create_app():
    app = Flask(__name__)
    app.config.from_object('config.config.Config')
    
    db.init_app(app)
    
    from app.routes import main
    app.register_blueprint(main)
    
    return app