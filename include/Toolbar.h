#pragma once
//--------------------include Section --------------------
#include<iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Const.h"
#include "SingleTone.h"
//--------------------Toolbar Class definition -------------------- 
class Toolbar
{
public:
	Toolbar() {};
	virtual ~Toolbar() = default;
	void draw(sf::RenderWindow& window);
	void initializeToolBar(sf::RenderWindow& window);
	void updateStats(int ammo, int health, int armor, int dash, Weapon weapon);
	void reAllocateStats(int ammo, int health, int armor, int dash);

private:
	bool m_drawDash;

	sf::Font m_font;
	sf::Text m_text [TOOLBAR_TEXTS];	
	sf::Text m_stats[TOOLBAR_TEXTS];
	sf::RectangleShape m_toolbarRec;
	sf::RectangleShape m_weaponRec;
	sf::RectangleShape m_dashRec;
};