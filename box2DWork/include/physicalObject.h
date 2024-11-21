#pragma once

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

class PhysicalObject : public sf::Drawable {
public:
	virtual void onUpdate(float timestep) {};
	inline void registerForDeletion() { m_registeredForDeletion = true; }
	inline bool isRegisteredForDeletion() { return m_registeredForDeletion; }
	inline b2Body* getBody() { return m_body; }

protected:
	b2Body* m_body;
	bool m_registeredForDeletion = false;
};