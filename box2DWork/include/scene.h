#pragma once

#include "layer.h"
#include "staticBlock.h"
#include "dynamicCircle.h"
#include "dynamicPentagon.h"
#include "SFMLDebugDraw.h"
//#include <box2d/box2d.h>
#include <vector>

class Scene : public Layer
{
public:
	Scene(const sf::Vector2f& viewSize, sf::Vector2i& parebtSize);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void onMouseMoved(const sf::Vector2i& pixelCoords) override;
	void onMouseButtonPress(const sf::Vector2i& pixelCoords, const sf::Mouse::Button& button);
	void onMouseButtonReleased(const sf::Vector2i& pixelCoords, const sf::Mouse::Button& button);
	void onKeyPress(const sf::Keyboard::Key& key);
	void onKeyRelease(const sf::Keyboard::Key& key);
	void onUpdate(float timestep) override;
	//const sf::Mouse::Button& button
	static inline std::shared_ptr<b2World> getWorld() { return m_world; }
private:

	bool m_debugMode = false;
	SFMLDebugDraw m_debugDraw;
	static std::shared_ptr<b2World> m_world;

	sf::RectangleShape m_mouseArea;


	std::vector<StaticBlock> m_blocks;
	std::vector<DynamicCircle> m_circles;
	std::vector<DynamicPentagon> m_pentagons;
};