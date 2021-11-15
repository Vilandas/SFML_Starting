#include "State.hpp"

#include "StateStack.hpp"

State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player, bool& paused)
: window(&window)
, textures(&textures)
, fonts(&fonts)
, player(&player)
, paused(&paused)
{
}

State::State(StateStack& stack, Context context)
: m_stack(&stack)
, m_context(context)
{
}

State::~State()
{
}

void State::Draw()
{
}

void State::RequestStackPush(StateID state_id)
{
	m_stack->PushState(state_id);
}

void State::RequestStackPop()
{
	m_stack->PopState();
}

void State::RequestStackClear()
{
	m_stack->ClearStates();
}

State::Context State::GetContext() const
{
	return m_context;
}

bool State::GetPaused() const
{
	return *m_context.paused;
}

void State::SetPaused(bool paused)
{
	*m_context.paused = paused;
}