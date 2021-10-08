#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void Run();

private:
	void HandlePlayerInput(sf::Keyboard::Key key, bool is_pressed);
	float Length(sf::Vector2f input_vector) const;
	sf::Vector2f Normalize(sf::Vector2f input_vector) const;
	void ProcessEvents();
	void Update(sf::Time delta_time);
	void Render();

private:
	sf::RenderWindow m_window;
	sf::Sprite m_player;
	sf::Texture m_texture;
	bool m_is_moving_down;
	bool m_is_moving_left;
	bool m_is_moving_right;
	bool m_is_moving_up;
};
