#include "SettingsState.hpp"

#include "ResourceHolder.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

#include "Button.hpp"
#include "EnumToString.hpp"
#include "Label.hpp"
#include "Player.hpp"

class FunctionHolder
{
public:
	FunctionHolder(int index) : m_index(index) {};
	int GetIndex() { return m_index; }

private:
	const int m_index;
};


SettingsState::SettingsState(StateStack& stack, Context context)
	: State(stack, context)
	, m_buttons()
	, m_awaiting_input(false)
	, m_input_button(nullptr)
{
	sf::Texture& texture = context.textures->Get(Textures::kTitleScreen);
	m_background_sprite.setTexture(texture);

	sf::Font& font = context.fonts->Get(Fonts::Main);
	sf::Vector2f viewSize = context.window->getView().getSize();

	for (int i = 0; i < static_cast<int>(PlayerAction::kActionCount); i++)
	{
		auto button = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
		button->setPosition(100, 0.4f * viewSize.y + i * 50.f);

		auto player_action = static_cast<PlayerAction>(i);
		button->SetText(EnumToString::KeyToString(context.player->GetAssignedKey(player_action)));

		auto label = std::make_shared<GUI::Label>(EnumToString::PlayerActionToString(player_action), * context.fonts);
		label->setPosition(320, 0.4f * viewSize.y + 20 + i * 50.f);

		m_buttons.emplace_back(button);

		//IN PROGRESS
		button->SetCallback(std::bind(&FunctionHolder::GetIndex, ({
			m_player_action = player_action;
			m_awaiting_input = true;
		})));

		button->SetCallback([&]()
			{
				m_player_action = player_action;
				button->SetText("");
				m_awaiting_input = true;
			});

		m_gui_container.Pack(button);
		m_gui_container.Pack(label);
	}
}

void SettingsState::Draw()
{
	sf::RenderWindow& window = *GetContext().window;
	window.setView(window.getDefaultView());

	window.draw(m_background_sprite);
	window.draw(m_gui_container);
}

bool SettingsState::Update(sf::Time)
{
	return false;
}

bool SettingsState::HandleEvent(const sf::Event& event)
{
	if (m_awaiting_input)
	{
		if (event.key.code == sf::Keyboard::Escape)
			return false;

		m_input_button->SetText("");

		GetContext().player->AssignKey(m_player_action, event.key.code);
		m_input_button->SetText(EnumToString::KeyToString(event.key.code));
		m_awaiting_input = false;
		m_input_button = nullptr;
		return false;
	}

	if (event.key.code == sf::Keyboard::Escape)
	{
		// Escape pressed, remove itself to previous menu
		RequestStackPop();
	}

	m_gui_container.HandleEvent(event);

	return false;
}