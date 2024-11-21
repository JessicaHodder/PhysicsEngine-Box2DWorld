#include "staticBlock.h"
#include "scene.h"

StaticBlock::StaticBlock(sf::Vector2f position, sf::Vector2f size, float orientationDegrees, float restitution)
{
	float halfExtentX = size.x * 0.5f;
	float halfExtentY = size.y * 0.5f;
	float orientationRadians = orientationDegrees * b2_pi / 180.f;

	auto world = Scene::getWorld();

	b2BodyDef rigidBodyDef;
	rigidBodyDef.type = b2_staticBody;
	rigidBodyDef.position = b2Vec2(position.x, position.y);
	rigidBodyDef.angle = orientationRadians;
	m_body = world->CreateBody(&rigidBodyDef);

	b2PolygonShape box;
	box.SetAsBox(halfExtentX, halfExtentY);

	b2FixtureDef colliderDef;
	colliderDef.restitution = restitution;
	colliderDef.shape = &box;
	m_body->CreateFixture(&colliderDef);

	m_shape.setFillColor(sf::Color::Green);
	m_shape.setOrigin(halfExtentX, halfExtentY);
	m_shape.setPosition(position);
	m_shape.setRotation(orientationDegrees);
	m_shape.setSize(size);
}

void StaticBlock::draw(sf::RenderTarget& target, sf::RenderStates stated) const
{
	target.draw(m_shape);
}
