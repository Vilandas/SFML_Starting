#pragma once
#include "SpriteNode.hpp"

class ScrollingSprite : public SpriteNode
{
public:
	explicit ScrollingSprite(const sf::Texture& texture, float scrollspeed, bool horizontal = false);
	ScrollingSprite(const sf::Texture& texture, const sf::IntRect& textureRect, float scrollspeed, bool horizontal = false);

private:
	void UpdateCurrent(sf::Time dt) override;
	void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	void ResetScrolling(sf::Time dt);
	float CalculateDirection() const;

private:
	float m_scrollspeed;
	bool m_horizontal;
};