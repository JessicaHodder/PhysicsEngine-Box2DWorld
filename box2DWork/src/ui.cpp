#include "ui.h"

#include <iostream>

UI::UI(const sf::Vector2f& viewSize, sf::Vector2i& parentSize) : Layer(viewSize, parentSize)
{
	const char* fontFile = "./assets/fonts/consola.ttf";
	if (!m_font.loadFromFile(fontFile))
	{
		char ch;
		std::cout << "Could not load font from file: " << fontFile << "\n";
		std::cin >> ch;
		exit(1);
	}

	m_text.setFont(m_font);
	m_text.setCharacterSize(16);
	m_text.setFillColor(sf::Color::Green);
}

void UI::onMouseMoved(const sf::Vector2i& pixelCoords)
{
}

void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.setView(m_view);
	target.draw(m_text);
}

void UI::setTextString(const std::string& text)
{
	m_text.setString(text);
}