#pragma once
#include <string>
#include <SFML/Window/Keyboard.hpp>

#include "PlayerAction.hpp"

class EnumToString
{
public:
	static std::string KeyToString(const sf::Keyboard::Key& key);
	static std::string PlayerActionToString(const PlayerAction& action);
};
