#pragma once
#include "physicalObject.h"

class DynamicCircle :public PhysicalObject
{
public:
	DynamicCircle() { m_body = nullptr; }
	DynamicCircle(sf::Vector2f position, float radius, float orientationDegrees = 0.f, float restitution = 0.f, float dencity = 1.f);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void onUpdate(float timestep);

private:
	sf::CircleShape m_circle;
	sf::Vertex line[2];

	float m_lifeTimeRemaning = 10.f;
};