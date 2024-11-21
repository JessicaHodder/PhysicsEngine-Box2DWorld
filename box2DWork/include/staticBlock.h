#pragma once

#include "physicalObject.h"
//#include "scene.h"

class StaticBlock : public PhysicalObject
{
public:
	StaticBlock() { m_body = nullptr; }
	StaticBlock(sf::Vector2f position, sf::Vector2f size, float orientation = 0.f, float restitution = 0.f);
	void draw(sf::RenderTarget& target, sf::RenderStates stated) const override;

private:

	sf::RectangleShape m_shape;
};