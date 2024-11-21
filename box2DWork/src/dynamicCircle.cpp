#include "dynamicCircle.h"
#include "scene.h"

#include <iostream>

DynamicCircle::DynamicCircle(sf::Vector2f position, float radius, float orientationDegrees, float restitution, float dencity)
{
	float orientationRadians = orientationDegrees * b2_pi / 180.f;

	auto world = Scene::getWorld();

	b2BodyDef rigidBodyDef;
	rigidBodyDef.type = b2_dynamicBody;
	rigidBodyDef.position = b2Vec2(position.x, position.y);
	rigidBodyDef.angle = orientationRadians;
	m_body = world->CreateBody(&rigidBodyDef);

	//sf::Vector2f sfposition(position.x, position.y);

	b2CircleShape circle;
	circle.m_radius =radius;

	b2FixtureDef colliderDef;
	colliderDef.restitution = restitution;
	colliderDef.shape = &circle;
	colliderDef.density = dencity;

	m_body->CreateFixture(&colliderDef);

	m_circle.setOrigin(radius, radius);
	m_circle.setPosition(position);
	m_circle.setFillColor(sf::Color::Blue);
	m_circle.setRotation(orientationDegrees);
	m_circle.setRadius(radius);



	line[0].color = sf::Color::Red;
	line[1].color = sf::Color::Red;
	line[0].position = position;
	line[1].position = position + sf::Vector2f(cos(orientationRadians) * m_circle.getRadius(), sin(orientationRadians) * m_circle.getRadius());

}

void DynamicCircle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_circle);
	target.draw(line, 2, sf::Lines);
}


void DynamicCircle::onUpdate(float timestep)
{
	b2Vec2 position = m_body->GetPosition();
	float orientationRadians = m_body->GetAngle();
	float orientationDegrees = orientationRadians * 180.f / b2_pi;

	sf::Vector2f sfPosition(position.x, position.y);

	m_circle.setPosition(sfPosition);
	m_circle.setRotation(orientationDegrees);

	line[0].position = sfPosition;
	line[1].position = sfPosition + sf::Vector2f(cos(orientationRadians) * m_circle.getRadius(), sin(orientationRadians) * m_circle.getRadius());

	m_lifeTimeRemaning -= timestep;
	if (m_lifeTimeRemaning < 0)
	{
		registerForDeletion();
	}


}
