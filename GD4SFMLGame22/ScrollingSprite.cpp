#include "ScrollingSprite.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

ScrollingSprite::ScrollingSprite(const sf::Texture& texture, float scrollspeed, bool horizontal)
: SpriteNode(texture)
, m_scrollspeed(scrollspeed)
, m_horizontal(horizontal)
{
}

ScrollingSprite::ScrollingSprite(const sf::Texture& texture, const sf::IntRect& textureRect, float scrollspeed, bool horizontal)
: SpriteNode(texture, textureRect)
, m_scrollspeed(scrollspeed)
, m_horizontal(horizontal)
{
}

void ScrollingSprite::UpdateCurrent(sf::Time dt)
{
    const sf::Vector2f velocity = m_horizontal
        ? sf::Vector2f(m_scrollspeed, 0)
        : sf::Vector2f(0, m_scrollspeed);

    move(velocity * dt.asSeconds());
	ResetScrolling(dt);
}

void ScrollingSprite::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    //opposite direction of scrolling
    const float direction = CalculateDirection();

    target.draw(GetSprite(), states);

    if (m_horizontal)
    {
        states.transform.translate(GetSprite().getLocalBounds().width * -direction, 0);

        target.draw(GetSprite(), states);
        states.transform.translate(GetSprite().getLocalBounds().width * direction, 0);
    }
    else
    {
        states.transform.translate(0, GetSprite().getLocalBounds().height * -direction);

        target.draw(GetSprite(), states);
        states.transform.translate(0, GetSprite().getLocalBounds().height * direction);
    }
}

void ScrollingSprite::ResetScrolling(sf::Time dt)
{
    if (m_horizontal)
    {
        float translation_offset_x = abs(GetWorldPosition().x);
        float reset_screen_width = ceil(GetSprite().getLocalBounds().width * getScale().x);

        if (translation_offset_x >= reset_screen_width)
        {
            setPosition(0, 0);
        }
    }
    else
    {
        float translation_offset_y = abs(GetWorldPosition().y);
        float reset_screen_height = ceil(GetSprite().getLocalBounds().height * getScale().y);

        if (translation_offset_y >= reset_screen_height)
        {
            setPosition(0, 0);
        }
    }
}

float ScrollingSprite::CalculateDirection() const
{
    return m_scrollspeed >= 0
        ? 1
        : -1;
}

