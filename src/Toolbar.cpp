#include "Toolbar.h"

//---------------initializeToolBar function--------------------
//function to initialize the toolbar
void Toolbar::initializeToolBar(sf::RenderWindow& window)
{
	m_toolbarRec.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	m_toolbarRec.setTexture(&SingleTone::instance().texture(TOOLBAR_TEXTURE));
	
	m_weaponRec.setSize(sf::Vector2f(440, 920));
	m_weaponRec.setTexture(&SingleTone::instance().texture(WEAPONS_TEXTURE));
	m_weaponRec.setTextureRect(sf::IntRect(0, 1100, 650, 220));
	m_weaponRec.setPosition(sf::Vector2f(1180, 25));
	
	m_dashRec.setSize(sf::Vector2f(150, 600));
	m_dashRec.setTexture(&SingleTone::instance().texture(DASH_TEXTURE));
	m_dashRec.setPosition(sf::Vector2f(510, 50));


	m_font.loadFromFile("DoomFont.ttf");

	sf::Text tempText;
	tempText.setFont(m_font);
	tempText.setColor(DARK_RED_COLOR);
	tempText.setCharacterSize(200);
	tempText.setString("200");
	tempText.setPosition(sf::Vector2f(20, 20));
	tempText.setScale(1, 2);

	for (int i = 0; i < TOOLBAR_TEXTS; i++)			//function to define the bars of stats---- GIVE CONST
	{
		tempText.setPosition(sf::Vector2f(100, 25));
		m_stats[i] = tempText;

		if (i == AMMO_TEXT)
		{
			m_stats[i].setString("100");
			m_stats[i].setPosition(sf::Vector2f(20, 110));
		}
		if (i == HEALTH_TEXT)
		{
			m_stats[i].setString("100");
			m_stats[i].setPosition(sf::Vector2f(270, 110));
		}
		if (i == ARMOR_TEXT)
		{
			m_stats[i].setString("150");
			m_stats[i].setPosition(sf::Vector2f(880, 110));
		}
		if (i == DASH_TEXT)
		{
			m_stats[i].setString("4");
			m_stats[i].setPosition(sf::Vector2f(550, 110));
		}
	}
}
//---------------updateStats function--------------------
//update the toolbar stats 
void Toolbar::updateStats(int ammo, int health, int armor, int dash, Weapon weapon)
{
	reAllocateStats(ammo, health, armor, dash);
	m_stats[AMMO_TEXT].setString(std::to_string(ammo));
	m_stats[HEALTH_TEXT].setString(std::to_string(health));
	m_stats[ARMOR_TEXT].setString(std::to_string(armor));
	m_stats[DASH_TEXT].setString(std::to_string(dash));

	m_weaponRec.setTextureRect(sf::IntRect(0, weapon * 220, 650, 220));
	
}
//---------------reAllocateStats function--------------------
//put stats in their exact position acording to how many letters they hold
void Toolbar::reAllocateStats(int ammo, int health, int armor, int dash)
{
	if(ammo > 99)
		m_stats[AMMO_TEXT].setPosition(sf::Vector2f(20, 110));
	else if(ammo < 100 && ammo > 9)
		m_stats[AMMO_TEXT].setPosition(sf::Vector2f(20 + 25, 110));
	else if(ammo < 10)
		m_stats[AMMO_TEXT].setPosition(sf::Vector2f(20 + 50, 110 ));

	if (health > 99)
		m_stats[HEALTH_TEXT].setPosition(sf::Vector2f(270, 110));
	else if (health < 100 && health > 9)
		m_stats[HEALTH_TEXT].setPosition(sf::Vector2f(270 + 25, 110));
	else if (health < 10)
		m_stats[HEALTH_TEXT].setPosition(sf::Vector2f(270 + 50, 110));

	if (armor > 99)
		m_stats[ARMOR_TEXT].setPosition(sf::Vector2f(880, 110));
	else if (armor < 100 && armor > 9)
		m_stats[ARMOR_TEXT].setPosition(sf::Vector2f(880 + 25, 110));
	else if (armor < 10)
		m_stats[ARMOR_TEXT].setPosition(sf::Vector2f(880 + 50, 110));

	if (dash <= 0)
		m_drawDash = true;
	else
		m_drawDash = false;

}
//---------------draw function--------------------
//draw the toolber
void Toolbar::draw(sf::RenderWindow& window)
{
	window.draw(m_toolbarRec);

	for (int i = 0; i < TOOLBAR_TEXTS; i++)
	{
		if (m_drawDash && i == 3)
			break;
		window.draw(m_stats[i]);
	}

	window.draw(m_weaponRec);

	if (m_drawDash)
		window.draw(m_dashRec);

}