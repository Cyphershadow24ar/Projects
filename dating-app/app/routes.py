from flask import Blueprint, render_template, request, jsonify
from app.models import User, Interaction
from app import db
from ml_engine.recommendation_engine import DatingRecommendationEngine

main = Blueprint('main', __name__)
recommendation_engine = DatingRecommendationEngine()

@main.route('/')
def index():
    return render_template('index.html')

@main.route('/profile/<int:user_id>')
def profile(user_id):
    user = User.query.get_or_404(user_id)
    return render_template('profile.html', user=user)

@main.route('/api/recommendations/<int:user_id>')
def get_recommendations(user_id):
    limit = request.args.get('limit', 10, type=int)
    recommendations = recommendation_engine.get_recommendations(user_id, limit)
    return jsonify(recommendations)

@main.route('/api/interaction', methods=['POST'])
def record_interaction():
    data = request.json
    interaction = Interaction(
        user1_id=data['user1_id'],
        user2_id=data['user2_id'],
        interaction_type=data['interaction_type'],
        rating=data.get('rating')
    )
    db.session.add(interaction)
    db.session.commit()
    return jsonify({'status': 'success'})