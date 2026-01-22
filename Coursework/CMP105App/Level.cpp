#include "Level.h"


sf::Vector2f m_inputDirection;

// anonymous player class
class {
private:
	sf::CircleShape body;
	float m_speed = 150.f;
	enum {
		UP,
		DOWN,
		LEFT,
		RIGHT
	} prevDirection;
	
public:
	// technical
	void start() {
		body.setFillColor(sf::Color::Red);
		body.setRadius(10);
		body.setPosition({ 400, 300 });
	}

	sf::CircleShape getDraw() {
		return body;
	}
	
	// gameplay
	void travel(sf::Vector2f direction, float dt) {
		body.move(direction * m_speed * dt);
	}

	void setSpeed(float value) {
		m_speed = value;
	}

} m_player;

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects
	m_player.start();
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
	m_player.travel(m_inputDirection, dt);
}

// Render level
void Level::render()
{
	beginDraw();

	m_window.draw(m_player.getDraw());

	endDraw();
}

