#pragma once
//--------------------include Section --------------------
#include <SFML/Graphics.hpp>
#include <typeindex>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> 
#include <stdlib.h>
#include <fstream>
#include <istream>
#include "Toolbar.h"
#include "StaticObject.h"
#include "Fire.h"
#include "HorizontalWall.h"
#include "VerticalWall.h"
#include "DiagonalWallR.h"
#include "DiagonalWallL.h"
#include "Ammo.h"
#include "PistolAmmo.h"
#include "ChainGunAmmo.h"
#include "ShotGunAmmo.h"
#include "BFGAmmo.h"
#include "PlasmaRifleAmmo.h"
#include "Health.h"
#include "SmallHealth.h"
#include "BigHealth.h"
#include "UltraHealth.h"
#include "Collision.h"
#include "SingleTone.h"
#include "Weapons.h"
#include "Pistol.h"
#include "ShotGun.h"
#include "ChainGun.h"
#include "BFG9000.h"
#include "HeavyWeaponDudeShot.h"
#include "MancubusShot.h"
#include "CyberDemonShot.h"
#include "PlasmaRifle.h"
#include "Armor.h"
#include "Slayer.h""
#include "Demons.h"
#include "BaronOfHell.h"
#include "Cacodemon.h"
#include "Revenant.h"
#include "CyberDemon.h"
#include "HeavyWeaponDude.h"
#include "Mancubus.h"
#include "InGameMessages.h"

//--------------------Board Class definition --------------------
class Board
{
public:
	Board(){};
	virtual ~Board() = default;

	void buildBoard(sf::RenderWindow& window, int levelNum);		
	void readStageFromFile(std::ifstream& gameFile, bool isFirst);
	void convertBoardRepresentationToObjects();
	void clearDataStructures();

	void checkDelete();
	bool isStageCompleted();
	void checkCollision();
	void updateGameStats();
	void swapWeapons(sf::Keyboard::Key key);
	void checkMonsterInsideView(sf::RenderWindow& window);

	void restartMessageInitiate(sf::RenderWindow& window, sf::View& view, sf::Time deltaTime);
	void moveToNextLevelMessageInitiate();
	void endGameMessageInitiate();					//messages functions - handling them - created on ingamemessages class
	void startGameMessageInitiate();

	void handleDemonsShooting(sf::Time deltaTime);	//differnet handle functions to handle the objects
	void handleDemonsActions(sf::Time deltaTime);
	void handlePlayerActions(sf::Time deltaTime);
	void handleShooting(sf::Event event, sf::RenderWindow& window, sf::Time deltaTime);
	void handleView(sf::RenderWindow& window, sf::View& viewPlayer, sf::Vector2f current_view); 
	void handleMessages(sf::RenderWindow& window, sf::View& view, sf::Time deltaTime);

	void draw(sf::RenderWindow& window, sf::Time deltaTime, sf::View& playerView, sf::View& toolBarView);

	void setLastLevel(bool isLsat) { m_lastLevel = isLsat; };
	void setToRestart(bool toRestart) { m_toRestart = toRestart; };

	float distance(sf::Vector2f vec1, sf::Vector2f vec2);
		
	bool getToRestart() const{ return m_toRestart; };			//get functions
	bool getStartTheNextLevel() const{ return m_startTheNextLevel; };
	bool getBackToMenu() const{ return m_backToMenu; };
	bool getIsLast() const{ return m_lastLevel; };

	void checkKillingSpree(sf::Time deltaTime);

private:
	bool m_toRestart = false;
	bool m_startMessage = false;
	bool m_movingToNextLevel = false;
	bool m_startTheNextLevel = false;
	bool m_lastLevel = false;
	bool m_endGame = false;
	bool m_backToMenu = false;
	
	bool m_startKillingSpreeCheck = false;
	sf::Time m_killingSpreeTimer = sf::seconds(0.0);
	int m_killingCounter = 0;
	bool m_activateKillingSound = false;
	int m_totallDeaths = 0;
	int m_lastDeaths = 0;

	Toolbar m_toolBar;

	std::unique_ptr <Slayer> m_slayer;
	std::vector<std::unique_ptr <Demons>> m_demons;
	std::vector<std::unique_ptr <Weapons>> m_shots;
	std::vector<std::unique_ptr <StaticObject>> m_staticObjects;
	std::vector <std::vector < char > > m_boardRepresentation;

	sf::RectangleShape m_backGroundRec[NUM_OF_BACK]; 
	InGameMessages m_messages;
	sf::Time m_messageTimer = sf::seconds(0.0);

};