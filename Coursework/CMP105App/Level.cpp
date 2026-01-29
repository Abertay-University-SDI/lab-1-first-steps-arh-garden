#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects
}

// handle user input
void Level::handleInput(float dt)
{
	// move input
	m_inputDirection = { 0,0 };
	// x
	if (m_input.isKeyDown(sf::Keyboard::Scancode::W)) {
		m_inputDirection += {0, -1};
		//std::cout << "W\n";
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::S)) {
		m_inputDirection += {0, 1};
		//std::cout << "S\n";
	}
	// y
	if (m_input.isKeyDown(sf::Keyboard::Scancode::D)) {
		m_inputDirection += {1, 0};
		//std::cout << "D\n";
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::A)) {
		m_inputDirection += {-1, 0};
		//std::cout << "A\n";
	}
}

// Update game objects
void Level::update(float dt)
{
	bool areColliding(const sf::CircleShape&, const sf::CircleShape&);

	// player
	m_player.changeDirection(m_inputDirection);
	m_player.travel(dt);
	m_player.wrapAround(m_window.getSize());

	// food
	if (areColliding(m_player.getBody(), m_food.getDraw())) {
		m_food.eat(m_window.getSize(), m_player);
	}
}

// Render level
void Level::render()
{
	beginDraw();

	m_window.draw(m_player.getBody());
	m_window.draw(m_food.getDraw());

	endDraw();
}

bool areColliding(const sf::CircleShape& a, const sf::CircleShape& b) {
	sf::Vector2f relativeVector = a.getPosition() - b.getPosition();

	float radiusSum = a.getRadius() + b.getRadius();

	return relativeVector.lengthSquared() <= pow(radiusSum, 2);
}