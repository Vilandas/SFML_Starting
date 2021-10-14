#include "Game.hpp"
#include <sstream>

const float kPlayerSpeed = 300;
const float kWindowHeight = 480;
const float kWindowWidth = 640;
const sf::Time kTimePerFrame = sf::seconds(1.f / 60.f);

Game::Game() :
	m_window(sf::VideoMode(kWindowWidth, kWindowHeight), "Getting Started"),
	m_player(),
	m_player_velocity(3, 3),
	m_texture(),
	m_is_moving_up(false),
	m_is_moving_down(false),
	m_is_moving_left(false),
	m_is_moving_right(false)
{
	if (!m_texture.loadFromFile("./Media/Textures/smiley.png"))
	{
		return;
	}

	m_player.setTexture(m_texture);
	m_player.setPosition(100.f, 100.f);
}

void Game::Bounce()
{
	m_player.move(m_player_velocity);

	sf::FloatRect bounds = m_player.getGlobalBounds();

	if (bounds.left + bounds.width >= kWindowWidth
		|| bounds.left <= 0)
	{
		m_player_velocity.x *= -1;
	}

	if (bounds.top + bounds.height >= kWindowHeight
		|| bounds.top <= 0)
	{
		m_player_velocity.y *= -1;
	}
}

void Game::DebugInfo(sf::Time delta_time)
{
	std::stringstream temp_stream;
	sf::Font font = sf::Font();

	if (!font.loadFromFile("./Media/Fonts/arial.ttf"))
	{
		return;
	}

	temp_stream << "FPS: " << (1.0f / delta_time.asSeconds());
	sf::Text text_fps = sf::Text(temp_stream.str(), font);

	temp_stream.str("");

	temp_stream << "Time Per Frame: " << delta_time.asSeconds();
	sf::Text text_time_per_frame = sf::Text(temp_stream.str(), font);

	text_time_per_frame.setPosition(0, 40);
	temp_stream.str("");

	temp_stream << "Position: ("
		<< m_player.getPosition().x
		<< ", "
		<< m_player.getPosition().y
		<< ")";

	sf::Text text_player_position = sf::Text(temp_stream.str(), font);
	
	text_player_position.setPosition(0, 80);
	temp_stream.str("");

	m_window.draw(text_fps);
	m_window.draw(text_time_per_frame);
	m_window.draw(text_player_position);
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


void Game::Render(sf::Time delta_time)
{
	m_window.clear();
	m_window.draw(m_player);
	DebugInfo(delta_time);
	m_window.display();
}


void Game::Run()
{
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
			Render(kTimePerFrame);
		}

		//Render(time_since_last_update);
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

	Bounce();

	movement = Normalize(movement);

	m_player.move(movement * delta_time.asSeconds() * kPlayerSpeed);
}