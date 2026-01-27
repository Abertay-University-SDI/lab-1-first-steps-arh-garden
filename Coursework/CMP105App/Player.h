#pragma once
#include <SFML/Graphics.hpp>

class Player {
private:
	float m_deadZone = 0.5f;
	float m_speed = 150.f;
	enum {
		UP,
		RIGHT,
		DOWN,
		LEFT
	} m_prevDirection;
	sf::CircleShape m_body;

public:
	// technical
	Player();

	sf::CircleShape getDraw();

	// setters
	void setSpeed(float&);
	void changeDirection(sf::Vector2f&);

	// gameplay
	void travel(float&);
};

