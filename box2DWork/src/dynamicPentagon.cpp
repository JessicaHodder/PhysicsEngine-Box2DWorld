#include "dynamicPentagon.h"
#include "scene.h"

DynamicPentagon::DynamicPentagon(sf::Vector2f position, float radius, float orientationDegrees, float restitution, float dencity)
{
	float orientationRadians = orientationDegrees * b2_pi / 180.f;

	auto world = Scene::getWorld();

	b2BodyDef dynamicBodyDef;
	dynamicBodyDef.type = b2_dynamicBody;
	dynamicBodyDef.position = b2Vec2(position.x, position.y);
	dynamicBodyDef.angle = orientationRadians;
	m_body = world->CreateBody(&dynamicBodyDef);

	//sf::Vector2f sfposition(position.x, position.y);

	//pentagon.m_radius = radius;




	b2Vec2 points[5];
	float angle;
	angle = (2.f * b2_pi / 5.f) * 0.f;
	points[0] = b2Vec2(cosf(angle) * radius, sinf(angle) * radius);
	angle = (2.f * b2_pi / 5.f) * 1.f;
	points[1] = b2Vec2(cosf(angle) * radius, sinf(angle) * radius);
	angle = (2.f * b2_pi / 5.f) * 2.f;
	points[2] = b2Vec2(cosf(angle) * radius, sinf(angle) * radius);
	angle = (2.f * b2_pi / 5.f) * 3.f;
	points[3] = b2Vec2(cosf(angle) * radius, sinf(angle) * radius);
	angle = (2.f * b2_pi / 5.f) * 4.f;
	points[4] = b2Vec2(cosf(angle) * radius, sinf(angle) * radius);

	b2PolygonShape pentagon;
	pentagon.Set(points, 5);

	b2FixtureDef colliderDef;
	colliderDef.restitution = restitution;
	colliderDef.shape = &pentagon;
	colliderDef.density = dencity;

	m_body->CreateFixture(&colliderDef);

	//m_pentagon.setOrigin(radius, radius);
	m_pentagon.setPosition(position);
	m_pentagon.setFillColor(sf::Color::Yellow);
	m_pentagon.setRotation(orientationDegrees);
	m_pentagon.setPointCount(5);
	m_pentagon.setPoint(0, sf::Vector2f(points[0].x, points[0].y));
	m_pentagon.setPoint(1, sf::Vector2f(points[1].x, points[1].y));
	m_pentagon.setPoint(2, sf::Vector2f(points[2].x, points[2].y));
	m_pentagon.setPoint(3, sf::Vector2f(points[3].x, points[3].y));
	m_pentagon.setPoint(4, sf::Vector2f(points[4].x, points[4].y));
	//m_circle.setRadius(radius);



	/*line[0].color = sf::Color::Red;
	line[1].color = sf::Color::Red;
	line[0].position = position;
	line[1].position = position + sf::Vector2f(cos(orientationRadians) * m_pentagon.getRadius(), sin(orientationRadians) * m_circle.getRadius());*/

}

void DynamicPentagon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_pentagon);
	//target.draw(line, 2, sf::Lines);
}


void DynamicPentagon::onUpdate(float timestep)
{
	b2Vec2 position = m_body->GetPosition();
	float orientationRadians = m_body->GetAngle();
	float orientationDegrees = orientationRadians * 180.f / b2_pi;

	sf::Vector2f sfPosition(position.x, position.y);

	m_pentagon.setPosition(sfPosition);
	m_pentagon.setRotation(orientationDegrees);

	m_lifeTimeRemaning -= timestep;
	if (m_lifeTimeRemaning < 0)
	{
		registerForDeletion();
	}

	//line[0].position = sfPosition;
	//line[1].position = sfPosition + sf::Vector2f(cos(orientationRadians) * m_circle.getRadius(), sin(orientationRadians) * m_circle.getRadius());


}