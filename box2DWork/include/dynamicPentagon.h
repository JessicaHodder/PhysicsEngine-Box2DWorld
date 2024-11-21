#pragma once
#include "physicalObject.h"

class DynamicPentagon :public PhysicalObject
{
public:
	DynamicPentagon() { m_body = nullptr; }
	DynamicPentagon(sf::Vector2f position, float radius, float orientationDegrees = 0.f, float restitution = 0.f, float dencity = 1.f);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void onUpdate(float timestep);

private:
	sf::ConvexShape m_pentagon;
	//sf::Vertex line[4];

	float m_lifeTimeRemaning = 10.f;
};