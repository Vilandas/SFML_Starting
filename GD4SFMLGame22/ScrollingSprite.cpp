#include "ScrollingSprite.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

ScrollingSprite::ScrollingSprite(const sf::Texture& texture, float scrollspeed)
	:SpriteNode(texture)
	,m_scrollspeed(scrollspeed)
{
}

ScrollingSprite::ScrollingSprite(const sf::Texture& texture, const sf::IntRect& textureRect, float scrollspeed)
	:SpriteNode(texture, textureRect)
	,m_scrollspeed(scrollspeed)
{
}

void ScrollingSprite::UpdateCurrent(sf::Time dt)
{
    //move sprite down
    move(sf::Vector2f(0, m_scrollspeed) * dt.asSeconds());
	ResetScrolling(dt);
}

void ScrollingSprite::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    //opposite direction of scrolling
    const float direction = CalculateDirection();

    target.draw(m_sprite, states);
    states.transform.translate(0, m_sprite.getLocalBounds().height * -direction);

    float xx = m_sprite.getLocalBounds().height * direction;
    float xx2 = m_sprite.getLocalBounds().height * -direction;

    target.draw(m_sprite, states);
    states.transform.translate(0, m_sprite.getLocalBounds().height * direction);
}

void ScrollingSprite::ResetScrolling(sf::Time dt)
{
    float translation_offset_y = abs(GetWorldPosition().y);
    float reset_screen_height = ceil(m_sprite.getLocalBounds().height * getScale().y);

    if (translation_offset_y >= reset_screen_height)
    {
        setPosition(0,0);
    }
}

int ScrollingSprite::CalculateDirection() const
{
    return m_scrollspeed >= 0
        ? 1
        : -1;
}

