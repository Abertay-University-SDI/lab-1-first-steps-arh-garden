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
	m_player.changeDirection(m_inputDirection);
	m_player.travel(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	m_window.draw(m_player.getDraw());

	endDraw();
}

