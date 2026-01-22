#pragma once

#include "Framework/BaseLevel.h"
#include "Player.h"

class Level : BaseLevel{
public:
	Level(sf::RenderWindow& window, Input& input);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.

	// Default variables for level class.
	sf::Vector2f m_inputDirection;
	Player m_player;
};