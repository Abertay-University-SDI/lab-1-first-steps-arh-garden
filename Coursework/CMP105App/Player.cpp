#include "Player.h"

// technical
Player::Player() {
	m_body.setFillColor(sf::Color::Red);
	m_body.setRadius(10);
	setPosition({ 400, 300 });
}

sf::CircleShape Player::getDraw() {
	return m_body;
}

// setters
void Player::setSpeed(float& value) {
	m_speed = value;
}

void Player::setPosition(const sf::Vector2f& position) {
	m_body.setPosition(position);
}

void Player::changeDirection(sf::Vector2f& input) {
	if (std::abs(input.x) < m_deadZone && std::abs(input.y) < m_deadZone) {
		return;
	}

	if (input.x > 0 && m_prevDirection != LEFT) {
		m_prevDirection = RIGHT;
	}
	else if (input.x < 0 && m_prevDirection != RIGHT) {
		m_prevDirection = LEFT;
	}
	else if (input.y > 0 && m_prevDirection != UP) {
		m_prevDirection = DOWN;
	}
	else if (input.y < 0 && m_prevDirection != DOWN) {
		m_prevDirection = UP;
	}
}

// gameplay
void Player::travel(float& dt) {
	sf::Vector2f direction;

	switch (m_prevDirection) {
	case UP:
		direction = { 0, -1 };
		break;
	case DOWN:
		direction = { 0, 1 };
		break;
	case LEFT:
		direction = { -1, 0 };
		break;
	case RIGHT:
		direction = { 1,0 };
		break;
	}
	
	m_body.move(direction * m_speed * dt);
}

void Player::wrapAround(const sf::Vector2u& windowSize) {
	sf::Vector2f position = m_body.getPosition();
	float radius = m_body.getRadius();

	// x
	// 0 is the top left corner of the circle so a greater margin is needed
	if (position.x < -radius * 2) {
		m_body.setPosition({ windowSize.x + radius, position.y });
	}
	else if (position.x > windowSize.x + radius) {
		m_body.setPosition({ -radius, position.y });
	}
	// y
	if (position.y < -radius * 2) {
		m_body.setPosition({ position.x, windowSize.y + radius });
	}
	else if (position.y > windowSize.y + radius) {
		m_body.setPosition({ position.x, -radius });
	}
}