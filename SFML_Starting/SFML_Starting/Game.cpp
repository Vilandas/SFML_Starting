#include "Game.hpp"

const float kPlayerSpeed = 300;
const sf::Time kTimePerFrame = sf::seconds(1.f / 60.f);

Game::Game() :
	m_window(sf::VideoMode(640, 480), "Getting Started"),
	m_player(),
	m_texture(),
	m_is_moving_up(false),
	m_is_moving_down(false),
	m_is_moving_left(false),
	m_is_moving_right(false)
{
	if (!m_texture.loadFromFile("./Media/Textures/smiley.png"))
	{
	}

	m_player.setTexture(m_texture);
	m_player.setPosition(100.f, 100.f);
}

void Game::HandlePlayerInput(sf::Keyboard::Key key, bool is_pressed)
{
	if (key == sf::Keyboard::W)
	{
		m_is_moving_up = is_pressed;
	}
	else if (key == sf::Keyboard::S)
	{
		m_is_moving_down = is_pressed;
	}
	else if (key == sf::Keyboard::A)
	{
		m_is_moving_left = is_pressed;
	}
	else if (key == sf::Keyboard::D)
	{
		m_is_moving_right = is_pressed;
	}
}

float Game::Length(sf::Vector2f input_vector) const
{
	return sqrt(input_vector.x * input_vector.x + input_vector.y * input_vector.y);
}

sf::Vector2f Game::Normalize(sf::Vector2f input_vector) const
{
	const float length = Length(input_vector);
	if (length > 0)
	{
		return input_vector / length;
	}

	return input_vector;
}



void Game::ProcessEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch(event.type)
		{
		case sf::Event::KeyPressed:
			HandlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			HandlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			m_window.close();
			break;
		default: ;
		}
	}
}


void Game::Render()
{
	m_window.clear();
	m_window.draw(m_player);
	m_window.display();
}


void Game::Run()
{
	//sf::Text
	//fps____
	//time per frame
	sf::Clock clock;
	sf::Time time_since_last_update = sf::Time::Zero;

	while(m_window.isOpen())
	{
		ProcessEvents();
		time_since_last_update += clock.restart();

		while (time_since_last_update >= kTimePerFrame)
		{
			time_since_last_update -= kTimePerFrame;
			ProcessEvents();
			Update(kTimePerFrame);
		}

		Render();
	}
}

void Game::Update(sf::Time delta_time)
{
	sf::Vector2f movement(0.f, 0.f);

	if (m_is_moving_up)
	{
		movement.y -= 1;
	}
	if (m_is_moving_down)
	{
		movement.y += 1;
	}
	if (m_is_moving_left)
	{
		movement.x -= 1;
	}
	if (m_is_moving_right)
	{
		movement.x += 1;
	}

	movement = Normalize(movement);

	m_player.move(movement * delta_time.asSeconds() * kPlayerSpeed);
}
