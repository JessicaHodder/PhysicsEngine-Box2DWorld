#include "scene.h"


#include <iostream>

using namespace std;

std::shared_ptr<b2World> Scene::m_world = std::make_shared<b2World>(b2Vec2(0.f, 9.81f));

Scene::Scene(const sf::Vector2f& viewSize, sf::Vector2i& parentSize) : Layer(viewSize, parentSize)
{
	const float bw = 0.25;
	const float halfBw = 0.125;
	/*const float halfViewSizeX = viewSize.x * 0.5;
	const float halfViewSizeY = viewSize.y * 0.5;

	const float halfR2 = sqrt(2.f) * 0.5f;

	m_blocks.push_back(StaticBlock(sf::Vector2f(halfBw, halfViewSizeY), sf::Vector2f(bw, viewSize.y), (0.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x - halfBw, halfViewSizeY), sf::Vector2f(bw, viewSize.y), (0.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.25f, viewSize.y * 0.1f), sf::Vector2f(bw, viewSize.y * 0.2), (0.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.1f), sf::Vector2f(bw, viewSize.y * 0.2), (0.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.75f, viewSize.y * 0.1f), sf::Vector2f(bw, viewSize.y * 0.2), (0.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.25f, viewSize.y * 0.2f), sf::Vector2f(bw * halfR2, bw * halfR2), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.2f), sf::Vector2f(bw * halfR2, bw * halfR2), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.75f, viewSize.y * 0.2f), sf::Vector2f(bw * halfR2, bw * halfR2), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(halfViewSizeX, viewSize.y * 0.7f), sf::Vector2f(bw, bw), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.4f, viewSize.y * 0.575f), sf::Vector2f(bw, bw), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.6f, viewSize.y * 0.575f), sf::Vector2f(bw, bw), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.3f, viewSize.y * 0.45f), sf::Vector2f(bw, bw), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(halfViewSizeX, viewSize.y * 0.45f), sf::Vector2f(bw, bw), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.7f, viewSize.y * 0.45f), sf::Vector2f(bw, bw), (45.f), (0.f)));*/



	const float halfViewSizeX = viewSize.x * 0.5;
	const float halfViewSizeY = viewSize.y - viewSize.y * 0.5;

	const float halfR2 = sqrt(2.f) * 0.5f;

	m_blocks.push_back(StaticBlock(sf::Vector2f(halfBw, halfViewSizeY), sf::Vector2f(bw, viewSize.y), (180.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x - halfBw, halfViewSizeY), sf::Vector2f(bw, viewSize.y), (180.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.25f, viewSize.y - viewSize.y * 0.1f), sf::Vector2f(bw, viewSize.y * 0.2), (180.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.5f, viewSize.y - viewSize.y * 0.1f), sf::Vector2f(bw, viewSize.y * 0.2), (180.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.75f, viewSize.y - viewSize.y * 0.1f), sf::Vector2f(bw, viewSize.y * 0.2), (180.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.25f, viewSize.y - viewSize.y * 0.2f), sf::Vector2f(bw * halfR2, bw * halfR2), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.5f, viewSize.y - viewSize.y * 0.2f), sf::Vector2f(bw * halfR2, bw * halfR2), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.75f, viewSize.y - viewSize.y * 0.2f), sf::Vector2f(bw * halfR2, bw * halfR2), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(halfViewSizeX, viewSize.y - viewSize.y * 0.7f), sf::Vector2f(bw, bw), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.4f, viewSize.y - viewSize.y * 0.575f), sf::Vector2f(bw, bw), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.6f, viewSize.y - viewSize.y * 0.575f), sf::Vector2f(bw, bw), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.3f, viewSize.y - viewSize.y * 0.45f), sf::Vector2f(bw, bw), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(halfViewSizeX, viewSize.y - viewSize.y * 0.45f), sf::Vector2f(bw, bw), (45.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(viewSize.x * 0.7f, viewSize.y - viewSize.y * 0.45f), sf::Vector2f(bw, bw), (45.f), (0.f)));





	//m_blocks.push_back(StaticBlock(sf::Vector2f(4.f, 0.5f), sf::Vector2f(7.f, 0.5f), (0.f), (0.f)));
	m_blocks.push_back(StaticBlock(sf::Vector2f(4.f, 5.75f), sf::Vector2f(8.f, 0.5f), (0.f), (0.f)));

	//m_circles.push_back(DynamicCircle(sf::Vector2f(4.f, 3.f), (0.5f), (0.f), (1.f), (1.f)));
	//m_pentagons.push_back(DynamicPentagon(sf::Vector2f(3.f, 3.f), (0.5f), (0.f), (1.f), (1.f)));

	//sf::RectangleShape m_mouseArea;
	m_mouseArea.setSize(sf::Vector2f(viewSize.x * 0.85f, viewSize.y * 0.2));
	m_mouseArea.setPosition(sf::Vector2f(viewSize.x * 0.075, viewSize.y - viewSize.y));
	m_mouseArea.setFillColor(sf::Color::Red);
	//m_mouseArea.setOrigin(m_mouseArea.getSize().x * 0.5, m_mouseArea.getSize().x * 0.5);



	m_debugDraw.setWorld(m_world);

}


void Scene::onMouseMoved(const sf::Vector2i& pixelCoords)
{

}


void Scene::onMouseButtonPress(const sf::Vector2i& pixelCoords, const sf::Mouse::Button& button)
{
	//float tempFloatX = pixelCoords.x;
	//float tempFloatY = pixelCoords.y;
	//sf::Vector2f tempVector = (sf::Vector2f(tempFloatX, tempFloatY));
	sf::Vector2f viewCoords = mapPixelToView(pixelCoords);
	if (button == sf::Mouse::Button::Left)
	{
		if (m_mouseArea.getGlobalBounds().contains(viewCoords))
		{
			m_circles.push_back(DynamicCircle(sf::Vector2f(viewCoords), (0.125f), (0.f), (0.6f), (1.f)));
		}
		
		cout << pixelCoords.x << " " << pixelCoords.y << endl;
	}
	if (button == sf::Mouse::Button::Right)
	{
		if (m_mouseArea.getGlobalBounds().contains(viewCoords))
		{
			m_pentagons.push_back(DynamicPentagon(sf::Vector2f(viewCoords), (0.15f), (0.f), (0.6f), (1.f)));
		}
		
		cout << pixelCoords.x << " " << pixelCoords.y << endl;
	}

}

void Scene::onMouseButtonReleased(const sf::Vector2i& pixelCoords, const sf::Mouse::Button& button)
{
}

void Scene::onKeyPress(const sf::Keyboard::Key& key)
{
	if (key == sf::Keyboard::Key::Tab)
	{
		m_debugMode = !m_debugMode;
	}
}

void Scene::onKeyRelease(const sf::Keyboard::Key& key)
{
}

void Scene::onUpdate(float timestep)
{
	m_debugDraw.clear();

	m_world->Step(timestep, 7, 5);

	for (int i = 0; i < m_circles.size(); i++)
	{
		m_circles[i].onUpdate(timestep);
		if (m_circles[i].isRegisteredForDeletion())
		{
			m_world->DestroyBody(m_circles[i].getBody());
			m_circles.erase(m_circles.begin() + i);
		}
	}

	for (int i = 0; i < m_pentagons.size(); i++)
	{
		m_pentagons[i].onUpdate(timestep);
		if (m_pentagons[i].isRegisteredForDeletion())
		{
			m_world->DestroyBody(m_pentagons[i].getBody());
			m_pentagons.erase(m_pentagons.begin() + i);
		}
	}
}


void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.setView(m_view);

	target.draw(m_mouseArea);

	for (int i = 0; i < m_blocks.size(); i++)
	{
		target.draw(m_blocks[i]);
	}

	for (int i = 0; i < m_circles.size(); i++)
	{
		target.draw(m_circles[i]);
	}

	for (int i = 0; i < m_pentagons.size(); i++)
	{
		target.draw(m_pentagons[i]);
	}

	if (m_debugMode == true)
	{
		target.draw(m_debugDraw);
	}


}




