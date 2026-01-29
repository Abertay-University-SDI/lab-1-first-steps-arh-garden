#pragma once
#include <SFML/Graphics.hpp>

class Player {
private:
	// internal
	float m_deadZone = 0.5f;
	float m_speed = 150.f;
	enum {
		UP,
		RIGHT,
		DOWN,
		LEFT
	} m_prevDirection;

	// external
	sf::CircleShape m_body;
	int m_score = 0;

public:
	// technical
	Player();

	sf::CircleShape getBody();

	// setters
	void setSpeed(const float&);
	void setPosition(const sf::Vector2f&);
	void changeDirection(const sf::Vector2f&);
	void addScore(const int&);

	// mechanical
	void travel(const float&);
	void wrapAround(const sf::Vector2u&);
};

