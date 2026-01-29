#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <random>

class Food
{
private:
	sf::CircleShape m_sprite;
	int m_value = 1;
	int m_margin = 32;

public:
	// technical
	Food();
	sf::CircleShape getDraw();

	// setters
	void setPosition(const sf::Vector2f&);
	void randomizePosition(const sf::Vector2u&);

	// mechanical
	void eat(const sf::Vector2u&, Player&);
};

