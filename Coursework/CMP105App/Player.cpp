#include "Player.h"
#include <math.h>
#include <iostream>

// technical
Player::Player() {
	m_body.setFillColor(sf::Color::Red);
	m_body.setRadius(10);
	m_body.setPosition({ 400, 300 });
}

sf::CircleShape Player::getDraw() {
	return m_body;
}

// setters
void Player::setSpeed(float value) {
	m_speed = value;
}

// gameplay
void Player::changeDirection(sf::Vector2f input) {
	if (std::abs(input.x) < m_deadZone && std::abs(input.y) < m_deadZone) {
		return;
	}
	
	if (input.x > 0) {
		m_prevDirection = RIGHT;
	}
	else if (input.x < 0) {
		m_prevDirection = LEFT;
	}
	else if (input.y > 0) {
		m_prevDirection = DOWN;
	}
	else if (input.y < 0) {
		m_prevDirection = UP;
	}
}

void Player::travel(float dt) {
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