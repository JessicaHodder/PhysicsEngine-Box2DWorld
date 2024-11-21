/*!
\file main.cpp
\brief Contains the entry point for the application
*/

#include <SFML/Graphics.hpp>
#include "ui.h"
#include "scene.h"


void main() /** Entry point for the application */
{
	sf::Vector2i windowSize(1024,800);
	sf::ContextSettings settings(0,0,16,4,4,0,false);
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "IMAT2912 Starter Code", 7U, settings); // Open main window

	Scene scene({ 8.f, 6.f }, windowSize);
	UI ui({ 1024.f, 800.f }, windowSize);
	ui.setTextString("Hello");
	//StaticBlock block({ 200.f, 200.f }, { 50.f, 50.f }, 0, 0);



	sf::Clock clock;

	// Run a game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// window closed button pressed
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseMoved)
			{
				sf::Vector2i pixelCoords(event.mouseMove.x, event.mouseMove.y);
				ui.onMouseMoved(pixelCoords);
				scene.onMouseMoved(pixelCoords);
				
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i pixelCoords(event.mouseButton.x, event.mouseButton.y);
				scene.onMouseButtonPress(pixelCoords, event.mouseButton.button);
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				//scene.onMouseButtonReleased();
			}
	
			if (event.type == sf::Event::Resized)
				windowSize = { static_cast<int>(event.size.width), static_cast<int>(event.size.height) };

			if (event.type == sf::Event::KeyPressed)
				scene.onKeyPress(event.key.code);
		}
		

		float fElapsedTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		scene.onUpdate(fElapsedTime);

		window.clear(sf::Color::White);

		window.draw(scene);
		window.draw(ui);
		//window.draw(block);

		window.display();
	}
}