#include "GameObject.h"

//--------------- GameObject Constructor ---------------
GameObject::GameObject(sf::Vector2f location,
	const sf::Texture& texture)
{
	m_objectSprite.setTexture(texture);
	m_location.x = location.y * 100;
	m_location.y = location.x * 100;
	m_objectSprite.setPosition(sf::Vector2f(m_location.x, m_location.y));	
	m_spriteSource = sf::Vector2f(0, 0);
}
//--------------- getObjectPosition Constructor ---------------
sf::Vector2f GameObject::getObjectPosition() const
{
	return m_objectSprite.getPosition();
}
//--------------- getSprite Constructor ---------------
sf::Sprite& GameObject::getSprite()
{
	return m_objectSprite;
}
//--------------- draw Constructor ---------------
void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_objectSprite);
}
//--------------- getDeleteStatus Constructor ---------------
bool GameObject::getDeleteStatus() const
{
	return m_toDelete;
}
//--------------- setDelete Constructor ---------------
void GameObject::setDelete()
{
	m_toDelete = true;
}



