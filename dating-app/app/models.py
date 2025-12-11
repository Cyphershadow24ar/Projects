from app import db
from datetime import datetime

class User(db.Model):
    __tablename__ = 'users'
    
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(80), unique=True, nullable=False)
    email = db.Column(db.String(120), unique=True, nullable=False)
    age = db.Column(db.Integer)
    location = db.Column(db.String(100))
    interests = db.Column(db.JSON)  # Store as JSON list
    personality_traits = db.Column(db.JSON)  # Store traits as JSON
    created_at = db.Column(db.DateTime, default=datetime.utcnow)
    
    def to_dict(self):
        return {
            'id': self.id,
            'username': self.username,
            'age': self.age,
            'location': self.location,
            'interests': self.interests,
            'personality_traits': self.personality_traits
        }

class Interaction(db.Model):
    __tablename__ = 'interactions'
    
    id = db.Column(db.Integer, primary_key=True)
    user1_id = db.Column(db.Integer, db.ForeignKey('users.id'))
    user2_id = db.Column(db.Integer, db.ForeignKey('users.id'))
    interaction_type = db.Column(db.String(20))  # like, dislike, message
    rating = db.Column(db.Float)  # Optional rating 1-5
    timestamp = db.Column(db.DateTime, default=datetime.utcnow)