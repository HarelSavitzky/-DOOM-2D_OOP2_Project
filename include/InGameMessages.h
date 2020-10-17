#pragma once
//--------------------include Section --------------------
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include "Const.h"
#include "SingleTone.h"

//--------------------InGameMessages Class definition --------------------
class InGameMessages
{
public:
	InGameMessages();		
	void initializeInGameMessages();
	void setMessagePosition(sf::RenderWindow& window, sf::View& view,
		sf::Time deltaTime, int numOfMessage);
	void handleGameMessages(sf::RenderWindow& window, sf::View& view,
		sf::Time deltaTime, int numOfMessage);
	virtual ~InGameMessages() = default;


private:
	sf::Text m_inGameMessages[NUM_OF_MESSEGAS];
	sf::RectangleShape m_inGamePhotos[IN_GAME_PHOTOS];

};