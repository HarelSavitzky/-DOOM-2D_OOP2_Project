#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Const.h"
#include "SingleTone.h"

//--------------------GameObject Class definition --------------------
class GameObject
{
public:
	GameObject(sf::Vector2f location, const sf::Texture& texture);
	GameObject() {};
	virtual ~GameObject() = default;

	void setDelete();
	void setSpriteSource(sf::Vector2f source) { m_spriteSource = source; };

	bool getDeleteStatus() const;

	sf::Sprite& getSprite();
	sf::Vector2f getObjectPosition() const;
	sf::Vector2f getSpriteSource() const { return m_spriteSource; };

	virtual void setSpriteSheet(sf::Time deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window);

private:
	bool m_toDelete = false;

	sf::Vector2f m_location;
	sf::Vector2f m_spriteSource;

	sf::Sprite m_objectSprite;
};