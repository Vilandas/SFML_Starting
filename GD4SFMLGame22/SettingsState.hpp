#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include "State.hpp"
#include "Container.hpp"

#include <SFML/Graphics/Text.hpp>

#include "Button.hpp"
#include "PlayerAction.hpp"

class SettingsState : public State
{
public:
	SettingsState(StateStack& stack, Context context);
	virtual void Draw();
	virtual bool Update(sf::Time dt);
	virtual bool HandleEvent(const sf::Event& event);

private:
	GUI::Container m_gui_container;
	sf::Sprite m_background_sprite;

	std::vector<std::shared_ptr<GUI::Button>> m_buttons;
	bool m_awaiting_input;
	std::shared_ptr<GUI::Button> m_input_button;
	PlayerAction m_player_action;
};

