#include "MenuState.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include "ResourceHolder.hpp"
#include "Utility.hpp"

MenuState::MenuState(StateStack& stack, Context context)
: State(stack, context)
, m_option_index(0)
{
	sf::Texture& texture = context.textures->Get(Textures::kTitleScreen);
	sf::Font& font = context.fonts->Get(Fonts::kMain);

	m_background_sprite = sf::Sprite(texture);

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

void MenuState::Draw()
{
	sf::RenderWindow& window = *GetContext().window;
	window.setView(window.getDefaultView());
	window.draw(m_background_sprite);

	for(const sf::Text text : m_options)
	{
		window.draw(text);
	}
}

bool MenuState::Update(sf::Time dt)
{
	return true;
}

bool MenuState::HandleEvent(const sf::Event& event)
{
	if(event.type != sf::Event::KeyPressed)
	{
		return false;
	}

	if(event.key.code == sf::Keyboard::Return)
	{
		switch(static_cast<Options>(m_option_index))
		{
		case Options::Play:
			RequestStackPop();
			RequestStackPush(StateID::kGame);
			break;
		case Options::Exit:
			RequestStackPop();
		}
	}
	else if(event.key.code == sf::Keyboard::Up)
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

void MenuState::UpdateOptionText()
{
	if(m_options.empty())
	{
		return;
	}

	for(sf::Text& text : m_options)
	{
		text.setFillColor(sf::Color::White);
	}

	m_options[m_option_index].setFillColor(sf::Color::Red);
}
