#pragma once

#include <SFML/Graphics.hpp>

#include "layer.h"

class UI : public Layer
{
public:
	UI(const sf::Vector2f& viewSize, sf::Vector2i& parentSize);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setTextString(const std::string& text);
	void onMouseMoved(const sf::Vector2i& pixelCoords) override;

private:
	sf::Font m_font;
	sf::Text m_text;
};