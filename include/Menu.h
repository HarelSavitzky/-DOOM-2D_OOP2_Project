#pragma once
//--------------------include Section --------------------
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include "SingleTone.h"
#include "Const.h"

//--------------------Menu Class definition --------------------
class Menu
{
public:
	Menu();			//constructors
	void mainMenuInitialize(float width, float height);
	void helpMenuInitialize(float width, float height);
		//handle menu functions--------------
	void drawMenu(sf::RenderWindow& window);
	void drawHelpMenu(sf::RenderWindow& window);
	void drawInnerHelp(sf::RenderWindow& window, int button);
	void MoveUp();
	void MoveDown();
		//get function-------------
	int getPressedItem() const { return m_selectedItemIndex; }

private:
	int m_selectedItemIndex = 0, m_amount;

	std::unique_ptr<sf::Font> m_font;
	sf::Text m_menu[NUMBER_OF_MAIN__MENU_ITEMS];//menu text

	sf::RectangleShape m_menuBack;		//menu picturs in rec
	sf::RectangleShape m_helpPhotos[HELP_MENU_PHOTOS];
	sf::Text m_helpText[HELP_TEXTS];
};