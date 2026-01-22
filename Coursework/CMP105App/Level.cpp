#include "Level.h"


sf::Vector2f m_inputDirection;
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
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::S)) {
		m_inputDirection += {0, 1};
	}
	// y
	if (m_input.isKeyDown(sf::Keyboard::Scancode::D)) {
		m_inputDirection += {1, 0};
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::A)) {
		m_inputDirection += {-1, 0};
	}
}

// Update game objects
void Level::update(float dt)
{
}

// Render level
void Level::render()
{
	beginDraw();

	endDraw();
}

