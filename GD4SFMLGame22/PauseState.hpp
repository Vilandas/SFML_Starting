#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.hpp"

class PauseState : public State
{
public:
	PauseState(StateStack& stack, Context context);
	virtual void Draw();
	virtual bool Update(sf::Time dt);
	virtual bool HandleEvent(const sf::Event& event);
	void UpdateOptionText();

private:
	enum class Options
	{
		Play,
		Exit
	};

private:
	std::vector<sf::Text> m_options;
	std::size_t m_option_index;
	sf::RectangleShape m_dark_rectangle_background;
};