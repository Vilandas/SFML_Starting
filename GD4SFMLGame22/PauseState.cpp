#include "PauseState.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "ResourceHolder.hpp"
#include "Utility.hpp"

PauseState::PauseState(StateStack& stack, Context context)
: State(stack, context)
, m_option_index(0)
, m_dark_rectangle_background(context.window->getView().getSize())
{
	m_dark_rectangle_background.setFillColor(sf::Color(30, 30, 30, 190));

	sf::Font& font = context.fonts->Get(Fonts::kMain);

	sf::Text play_option = sf::Text("Play", font);
	sf::Text exit_option = sf::Text("Exit", font);

	Utility::CentreOrigin(play_option);
	Utility::CentreOrigin(exit_option);

	play_option.setPosition(context.window->getView().getSize() / 2.f);
	exit_option.setPosition(play_option.getPosition() + sf::Vector2f(0, 30));

	m_options.emplace_back(play_option);
	m_options.emplace_back(exit_option);

	UpdateOptionText();
}

void PauseState::Draw()
{
	sf::RenderWindow& window = *GetContext().window;
	window.setView(window.getDefaultView());
	window.draw(m_dark_rectangle_background);

	for (const sf::Text text : m_options)
	{
		window.draw(text);
	}
}

bool PauseState::Update(sf::Time dt)
{
	return true;
}

bool PauseState::HandleEvent(const sf::Event& event)
{
	if (event.type != sf::Event::KeyPressed)
	{
		return false;
	}

	if (event.key.code == sf::Keyboard::Return)
	{
		switch (static_cast<Options>(m_option_index))
		{
		case Options::Play:
			RequestStackPop();
			SetPaused(false);
			break;
		case Options::Exit:
			RequestStackClear();
			SetPaused(false);
			RequestStackPush(StateID::kTitle);
		}
	}
	else if (event.key.code == sf::Keyboard::Up)
	{
		m_option_index > 0
			? m_option_index--
			: m_option_index = m_options.size() - 1;

		UpdateOptionText();
	}
	else if (event.key.code == sf::Keyboard::Down)
	{
		m_option_index < m_options.size() - 1
			? m_option_index++
			: m_option_index = 0;

		UpdateOptionText();
	}

	return true;
}

void PauseState::UpdateOptionText()
{
	if (m_options.empty())
	{
		return;
	}

	for (sf::Text& text : m_options)
	{
		text.setFillColor(sf::Color::White);
	}

	m_options[m_option_index].setFillColor(sf::Color::Red);
}
