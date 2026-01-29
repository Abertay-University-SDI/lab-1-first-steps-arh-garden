#include "Food.h"

// technical
Food::Food() {
	m_sprite.setFillColor(sf::Color::Green);
	m_sprite.setRadius(5);

	setPosition({ 100, 100 });
	std::srand(time(0));
}

sf::CircleShape Food::getDraw() {
	return m_sprite;
}

// setters
void Food::setPosition(const sf::Vector2f& pos) {
	m_sprite.setPosition(pos);
}

void Food::randomizePosition(const sf::Vector2u& windowSize) {
	sf::Vector2f pos = {
		static_cast<float>(std::rand() % (windowSize.x - m_margin)) + m_margin,
		static_cast<float>(std::rand() % (windowSize.y - m_margin)) + m_margin
	};

	setPosition(pos);
}

// mechanical
void Food::eat(const sf::Vector2u& windowSize, Player& player) {
	player.addScore(m_value);
	randomizePosition(windowSize);
}