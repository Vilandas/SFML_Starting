#include "EnumToString.hpp"

std::string EnumToString::KeyToString(const sf::Keyboard::Key& key)
{
    switch(key)
	{
    case sf::Keyboard::Unknown:
        return "Unknown";
    case sf::Keyboard::A:
        return "A";
    case sf::Keyboard::B:
        return "B";
    case sf::Keyboard::C:
        return "C";
    case sf::Keyboard::D:
        return "D";
    case sf::Keyboard::E:
        return "E";
    case sf::Keyboard::F:
    	return "F";
    case sf::Keyboard::G:
    	return "G";
    case sf::Keyboard::H:
        return "H";
    case sf::Keyboard::I:
        return "I";
    case sf::Keyboard::J:
        return "J";
    case sf::Keyboard::K:
        return "K";
    case sf::Keyboard::L:
        return "L";
    case sf::Keyboard::M:
        return "M";
    case sf::Keyboard::N:
        return "N";
    case sf::Keyboard::O:
        return "O";
    case sf::Keyboard::P:
        return "P";
    case sf::Keyboard::Q:
        return "Q";
    case sf::Keyboard::R:
        return "R";
    case sf::Keyboard::S:
        return "S";
    case sf::Keyboard::T:
        return "T";
    case sf::Keyboard::U:
        return "U";
    case sf::Keyboard::V:
        return "V";
    case sf::Keyboard::W:
        return "W";
    case sf::Keyboard::X:
        return "X";
    case sf::Keyboard::Y:
        return "Y";
    case sf::Keyboard::Z:
        return "Z";
    case sf::Keyboard::Num0:
        return "0";
    case sf::Keyboard::Num1:
        return "1";
    case sf::Keyboard::Num2:
        return "2";
    case sf::Keyboard::Num3:
        return "3";
    case sf::Keyboard::Num4:
        return "4";
    case sf::Keyboard::Num5:
        return "5";
    case sf::Keyboard::Num6:
        return "6";
    case sf::Keyboard::Num7:
        return "7";
    case sf::Keyboard::Num8:
        return "8";
    case sf::Keyboard::Num9:
        return "9";
    case sf::Keyboard::Escape:
        return "Escape";
    case sf::Keyboard::LControl:
        return "LControl";
    case sf::Keyboard::LShift:
        return "LShift";
    case sf::Keyboard::LAlt:
        return "LAlt";
    case sf::Keyboard::LSystem:
        return "LSystem";
    case sf::Keyboard::RControl:
        return "RControl";
    case sf::Keyboard::RShift:
        return "RShift";
    case sf::Keyboard::RAlt:
        return "RAlt";
    case sf::Keyboard::RSystem:
        return "RSystem";
    case sf::Keyboard::Menu:
        return "Menu";
    case sf::Keyboard::LBracket:
        return "[";
    case sf::Keyboard::RBracket:
        return "]";
    case sf::Keyboard::Semicolon:
        return ";";
    case sf::Keyboard::Comma:
        return ",";
    case sf::Keyboard::Period:
        return ".";
    case sf::Keyboard::Quote:
        return "\"";
    case sf::Keyboard::Slash:
        return "/";
    case sf::Keyboard::Backslash:
        return "\\";
    case sf::Keyboard::Tilde:
        return "~";
    case sf::Keyboard::Equal:
        return "=";
    case sf::Keyboard::Hyphen:
        return "-";
    case sf::Keyboard::Space:
        return "Space";
    case sf::Keyboard::Enter:
        return "Enter";
    case sf::Keyboard::Backspace:
        return "BackSpace";
    case sf::Keyboard::Tab:
        return "Tab";
    case sf::Keyboard::PageUp:
        return "PageUp";
    case sf::Keyboard::PageDown:
        return "PageDown";
    case sf::Keyboard::End:
        return "End";
    case sf::Keyboard::Home:
        return "Home";
    case sf::Keyboard::Insert:
        return "Insert";
    case sf::Keyboard::Delete:
        return "Delete";
    case sf::Keyboard::Add:
        return "Add";
    case sf::Keyboard::Subtract:
        return "Subtract";
    case sf::Keyboard::Multiply:
        return "Multiply";
    case sf::Keyboard::Divide:
        return "Divide";
    case sf::Keyboard::Left:
        return "Left";
    case sf::Keyboard::Right:
        return "Right";
    case sf::Keyboard::Up:
        return "Up";
    case sf::Keyboard::Down:
        return "Down";
    case sf::Keyboard::Numpad0:
        return "NumPad0";
    case sf::Keyboard::Numpad1:
        return "NumPad1";
    case sf::Keyboard::Numpad2:
        return "NumPad2";
    case sf::Keyboard::Numpad3:
        return "NumPad3";
    case sf::Keyboard::Numpad4:
        return "NumPad4";
    case sf::Keyboard::Numpad5:
        return "NumPad5";
    case sf::Keyboard::Numpad6:
        return "NumPad6";
    case sf::Keyboard::Numpad7:
        return "NumPad7";
    case sf::Keyboard::Numpad8:
        return "NumPad8";
    case sf::Keyboard::Numpad9:
        return "NumPad9";
    case sf::Keyboard::F1:
        return "F1";
    case sf::Keyboard::F2:
        return "F2";
    case sf::Keyboard::F3:
        return "F3";
    case sf::Keyboard::F4:
        return "F4";
    case sf::Keyboard::F5:
        return "F5";
    case sf::Keyboard::F6:
        return "F6";
    case sf::Keyboard::F7:
        return "F7";
    case sf::Keyboard::F8:
        return "F8";
    case sf::Keyboard::F9:
        return "F9";
    case sf::Keyboard::F10:
        return "F10";
    case sf::Keyboard::F11:
        return "F11";
    case sf::Keyboard::F12:
        return "F12";
    case sf::Keyboard::F13:
        return "F13";
    case sf::Keyboard::F14:
        return "F14";
    case sf::Keyboard::F15:
        return "F15";
    case sf::Keyboard::Pause:
        return "Pause";
    case sf::Keyboard::KeyCount:
        return "KeyCount";
    }

    return "Error - Invalid";
}

std::string EnumToString::PlayerActionToString(const PlayerAction& action)
{
    switch(action)
    {
    case PlayerAction::kMoveDown:
        return "Move Down";
    case PlayerAction::kMoveLeft:
        return "Move Left";
    case PlayerAction::kMoveRight:
        return "Move Right";
    case PlayerAction::kMoveUp:
        return "Move Up";
    case PlayerAction::kActionCount:
        return "Action Count";
    }

    return "Error - Invalid";
}