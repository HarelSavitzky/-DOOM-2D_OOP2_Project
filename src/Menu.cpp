#include "Menu.h"

//---------------Menu constructor--------------------
Menu::Menu()
{
	m_amount = NUMBER_OF_MAIN__MENU_ITEMS;
}
//---------------mainMenuInitialize function--------------------
//this function	initializing the main menu
//defines the menu, from text to background
void Menu::mainMenuInitialize(float width, float height)
{
	for (int i = 0; i < m_amount; i++)
	{													
		m_menu[i].setOutlineThickness(10);			
		m_menu[i].setFont(*SingleTone::instance().getFont(NEW_DOOM_FONT).get());
		m_menu[i].setCharacterSize(width / 9);

		switch (i)
		{
		case PLAY_BUTTON:
			m_menu[i].setOrigin(m_menu[i].getLocalBounds().width * 0.5,
				m_menu[i].getLocalBounds().height * 0.5);
			m_menu[i].setFillColor(DARK_RED_COLOR);
			m_menu[i].setString("play");
			m_menu[i].setPosition(sf::Vector2f(width * 0.5 , height / (m_amount * 2) * 2.7));

			break;
		case HELP_BUTTON:
			m_menu[i].setFillColor(DARK_GREY_COLOR);
			m_menu[i].setString("help");
			m_menu[i].setPosition(sf::Vector2f(width * 0.5, height / (m_amount * 2) * 3.7));
			break;

		case QUIT_BUTTON:
			m_menu[i].setFillColor(DARK_GREY_COLOR);
			m_menu[i].setString("quit");
			m_menu[i].setPosition(sf::Vector2f(width * 0.5, height / (m_amount * 2) * 4.7));
			break;
		}
		m_menu[i].setOrigin(m_menu[i].getLocalBounds().width * 0.5,
			m_menu[i].getLocalBounds().height * 0.5);
	}
	m_menuBack.setSize(sf::Vector2f(width, height));
	m_menuBack.setTexture(&SingleTone::instance().texture(MAIN_MENU_PHOTO_TEXTURE));
	m_menuBack.setPosition(0, 0);
}

//--------------- helpMenuInitialize function ---------------
//this function initialising the help menu
//defines the menu, from text to background
void Menu::helpMenuInitialize(float width, float height)
{
	for (int i = 0; i < m_amount; i++)
	{													
		m_menu[i].setOutlineThickness(10);			
		m_menu[i].setFont(*SingleTone::instance().getFont(NEW_DOOM_FONT).get());
		m_menu[i].setCharacterSize(width / 9);
		
		switch (i)
		{
		case ARMORY_BUTTON:
			m_menu[i].setFillColor(DARK_RED_COLOR);
			m_menu[i].setString("armory");
			m_menu[i].setPosition(sf::Vector2f(width * 0.5, height / (m_amount * 2) * 2.7));
			m_helpPhotos[i].setTexture(&SingleTone::instance().texture(ARMORY_HELP_PHOTO_TEXTURE));
			break;
		case DEMONS_BUTTON:
			m_menu[i].setFillColor(DARK_GREY_COLOR);
			m_menu[i].setString("demons");
			m_menu[i].setPosition(sf::Vector2f(width * 0.5, height / (m_amount * 2) * 3.7));
			m_helpPhotos[i].setTexture(&SingleTone::instance().texture(DEMONS_HELP_PHOTO_TEXTURE));
			break;			
		case CONTROLS_BUTTON:
			m_menu[i].setFillColor(DARK_GREY_COLOR);
			m_menu[i].setString("controls");
			m_menu[i].setPosition(sf::Vector2f(width * 0.5, height / (m_amount * 2) * 4.7));
			m_helpPhotos[i].setTexture(&SingleTone::instance().texture(KEYS_HELP_PHOTO_TEXTURE));
			break;
		}
		m_menu[i].setOrigin(m_menu[i].getLocalBounds().width * 0.5,
			m_menu[i].getLocalBounds().height * 0.5);

		m_helpPhotos[i].setSize(sf::Vector2f(width, height));
		m_helpPhotos[i].setPosition(0, 0);
	}
	m_helpPhotos[BACKGROUND].setTexture(&SingleTone::instance().texture(HELP_MENU_BACK_PHOTO_TEXTURE));
	m_helpPhotos[BACKGROUND].setSize(sf::Vector2f(width, height));
	m_helpPhotos[BACKGROUND].setPosition(0, 0);
	m_menuBack.setSize(sf::Vector2f(width, height));
	m_menuBack.setTexture(&SingleTone::instance().texture(HELP_MENU_BACK_PHOTO_TEXTURE));
	m_menuBack.setPosition(0, 0);

	for (int i = 0; i < HELP_TEXTS; i++)
	{

		m_helpText[i].setFont(*SingleTone::instance().getFont(NEW_DOOM_FONT).get());
		m_helpText[i].setFillColor(DARK_RED_COLOR);
		switch (i)
		{
		case ESCAPE_MESSAGE:
			m_helpText[i].setOutlineThickness(2);
			m_helpText[i].setCharacterSize(width / 35);
			m_helpText[i].setString(ESCAPE_TEXT);
			m_helpText[i].setPosition(sf::Vector2f(10, 10));
			break;
		case INSTRUCTION_MESSAGE:
			m_helpText[i].setOutlineThickness(4);
			m_helpText[i].setCharacterSize(width / 15);
			m_helpText[i].setString(INSTRUCTION_TEXT);
			m_helpText[i].setPosition(sf::Vector2f(width * 0.5, height * 0.2));
			m_helpText[i].setOrigin(m_helpText[i].getLocalBounds().width * 0.5,
				m_helpText[i].getLocalBounds().height * 0.5);
			break;		
		case FULL_SCREEN_MESSAGE:
			m_helpText[i].setOutlineThickness(2);
			m_helpText[i].setCharacterSize(width / 35);
			m_helpText[i].setString(FULL_SCREEN_TEXT);
			m_helpText[i].setPosition(sf::Vector2f(10, height - 200));
			break;
		}

	}

}
//---------------drawMenu function--------------------
//function to draw the main menu
void Menu::drawMenu(sf::RenderWindow& window)
{
	window.draw(m_menuBack);	

	for (auto& menuItem : m_menu)
		window.draw(menuItem);
}
//---------------drawHelpMenu function--------------------
//function to draw the help menu
void Menu::drawHelpMenu(sf::RenderWindow& window)
{
	window.draw(m_menuBack);		

	for (auto& menuItem : m_menu)	
		window.draw(menuItem);

	for (auto& helpText : m_helpText)
		window.draw(helpText);
	
}
//---------------drawInnerHelp function--------------------
//function to draw the inner help menu
void Menu::drawInnerHelp(sf::RenderWindow& window, int button)
{
	window.draw(m_helpPhotos[BACKGROUND]);			
	window.draw(m_helpPhotos[button]);
}
//---------------MoveUp function--------------------
//move up in menu
void Menu::MoveUp()									
{
	if (m_selectedItemIndex - 1 >= 0)
	{
		m_menu[m_selectedItemIndex].setFillColor(DARK_GREY_COLOR);
		m_selectedItemIndex--;
		m_menu[m_selectedItemIndex].setFillColor(DARK_RED_COLOR);
	}
}
//---------------MoveDown function--------------------
//move down in menu
void Menu::MoveDown()
{
	if (m_selectedItemIndex + 1 < NUMBER_OF_MAIN__MENU_ITEMS)		
	{
		m_menu[m_selectedItemIndex].setFillColor(DARK_GREY_COLOR);
		m_selectedItemIndex++;
		m_menu[m_selectedItemIndex].setFillColor(DARK_RED_COLOR);
	}
}