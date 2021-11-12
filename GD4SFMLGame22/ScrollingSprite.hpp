#pragma once
#include "SpriteNode.hpp"

class ScrollingSprite : public SpriteNode
{
public:
	explicit ScrollingSprite(const sf::Texture& texture, float scrollspeed);
	ScrollingSprite(const sf::Texture& texture, const sf::IntRect& textureRect, float scrollspeed);

private:
	void UpdateCurrent(sf::Time dt) override;
	void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	void ResetScrolling(sf::Time dt);

private:
	float m_scrollspeed;
};