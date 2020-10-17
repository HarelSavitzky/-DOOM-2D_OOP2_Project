#pragma once
//--------------------include Section --------------------
#include "GameObject.h"
//--------------------StaticObject Class definition -------------------- 
class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	StaticObject();
	StaticObject(sf::Vector2f location,
		const sf::Texture& texture);
	virtual ~StaticObject() = default;

	virtual void setSpriteSheet(sf::Time deltaTime) {};

private:
};