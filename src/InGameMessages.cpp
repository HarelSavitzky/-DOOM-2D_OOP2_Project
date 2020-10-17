#include "InGameMessages.h"

//---------------Menu constructor--------------------
InGameMessages::InGameMessages()
{
}
//--------------- initializeInGameMessages function ---------------
//initialize the in-game messages & pictures
void InGameMessages::initializeInGameMessages()
{
	for (int i = 0; i < NUM_OF_MESSEGAS; i++)
	{													
		m_inGameMessages[i].setOutlineThickness(5);			
		m_inGameMessages[i].setFont(*SingleTone::instance().getFont(NEW_DOOM_FONT).get());
		m_inGameMessages[i].setCharacterSize(WINDOW_WIDTH / 8);
		m_inGameMessages[i].setOrigin(m_inGameMessages[i].getLocalBounds().width * 0.5,
			m_inGameMessages[i].getLocalBounds().height * 0.5);
		m_inGameMessages[i].setFillColor(DARK_RED_COLOR);

		switch (i)
		{
		case DIED:
			m_inGameMessages[i].setString(DIED_MESSAGE);
			break;
		case WIN:
			m_inGameMessages[i].setString(WIN_MESSAGE);
			break;
		case RESTART:
			m_inGameMessages[i].setString(RESTART_MESSAGE);
			break;
		case LEVEL_COMPLETE:
			m_inGameMessages[i].setString(LEVEL_COMPLETE_MESSAGE);
			break;
		case LOADING:
			m_inGameMessages[i].setString(LOADING_NEXT_MESSAGE);
			break;
		case STARTING:
			m_inGameMessages[i].setString(STARTING_MESSAGE);
			m_inGameMessages[i].setCharacterSize(WINDOW_WIDTH / 7);
			break;
		}
	}
	m_inGamePhotos[LOGO].setTexture(&SingleTone::instance().texture(OPTIONS_LOGOE_TEXTURE));
	m_inGamePhotos[END_GAME_PHOTO].setTexture(&SingleTone::instance().texture(END_GAME_PHOTO_TEXTURE));
	m_inGamePhotos[LOGO].setSize(sf::Vector2f(400, 400));
}
//--------------- setMessagePosition function ---------------
//update the in-game messages position
void InGameMessages::setMessagePosition(sf::RenderWindow& window, sf::View& view, sf::Time deltaTime, int numOfMessage)
{
	
	switch (numOfMessage)
	{
	case RESTART_MSGS:			//restart			
		m_inGameMessages[RESTART].setOrigin(m_inGameMessages[RESTART].getLocalBounds().width * 0.5,
			m_inGameMessages[RESTART].getLocalBounds().height * 0.5);
		m_inGameMessages[RESTART].setPosition(view.getCenter().x, view.getCenter().y);

		m_inGameMessages[DIED].setOrigin(m_inGameMessages[DIED].getLocalBounds().width * 0.5,
			m_inGameMessages[DIED].getLocalBounds().height * 0.5);
		m_inGameMessages[DIED].setPosition(view.getCenter().x, view.getCenter().y);
		break;

	case LEVEL_COMPLETE_MSGS:

		m_inGameMessages[LEVEL_COMPLETE].setOrigin(m_inGameMessages[LEVEL_COMPLETE].getLocalBounds().width * 0.5,
			m_inGameMessages[LEVEL_COMPLETE].getLocalBounds().height * 0.5);

		m_inGameMessages[LEVEL_COMPLETE].setPosition(view.getCenter().x, view.getCenter().y);

		m_inGameMessages[LOADING].setOrigin(m_inGameMessages[LOADING].getLocalBounds().width * 0.5,
			m_inGameMessages[LOADING].getLocalBounds().height * 0.5);

		m_inGameMessages[LOADING].setPosition(view.getCenter().x, view.getCenter().y + 200);

		m_inGamePhotos[LOGO].setOrigin(m_inGamePhotos[LOGO].getLocalBounds().width * 0.5,
			m_inGamePhotos[LOGO].getLocalBounds().height * 0.5);
		m_inGamePhotos[LOGO].setPosition(view.getCenter().x, view.getCenter().y - 180);
		break;

	case END_GAME_MSGS:
		m_inGameMessages[WIN].setOrigin(m_inGameMessages[WIN].getLocalBounds().width * 0.5,
			m_inGameMessages[WIN].getLocalBounds().height * 0.5);
		m_inGameMessages[WIN].setPosition(view.getCenter().x, view.getCenter().y);
		m_inGamePhotos[END_GAME_PHOTO].setSize(sf::Vector2f(view.getSize().x, view.getSize().y));
		m_inGamePhotos[END_GAME_PHOTO].setOrigin(m_inGamePhotos[END_GAME_PHOTO].getLocalBounds().width * 0.5,
			m_inGamePhotos[END_GAME_PHOTO].getLocalBounds().height * 0.5);
		m_inGamePhotos[END_GAME_PHOTO].setPosition(view.getCenter().x, view.getCenter().y);
		break;
	case START_MSGS:
		m_inGameMessages[STARTING].setOrigin(m_inGameMessages[STARTING].getLocalBounds().width * 0.5,
			m_inGameMessages[STARTING].getLocalBounds().height * 0.5);
		m_inGameMessages[STARTING].setPosition(view.getCenter().x, view.getCenter().y);
		break;
	}
}
//--------------- handleGameMessages function ---------------
//handle the game messages display - print them and count time between them
void InGameMessages::handleGameMessages(sf::RenderWindow& window, sf::View& view, sf::Time deltaTime, int numOfMessage)
{
	static bool unstopable = false;	//endGame

	switch (numOfMessage)
	{
	case RESTART_MSGS:			//restart			
		if (deltaTime.asSeconds() < 2)
			window.draw(m_inGameMessages[DIED]);
		else
			window.draw(m_inGameMessages[RESTART]);
		break;

	case LEVEL_COMPLETE_MSGS:
		if (deltaTime.asSeconds() < 3)//level complete
			window.draw(m_inGameMessages[LEVEL_COMPLETE]);

		if (deltaTime.asSeconds() > 3)
		{
			window.clear();
			window.draw(m_inGamePhotos[LOGO]);
			window.draw(m_inGameMessages[LOADING]);
		}
		break;
	case END_GAME_MSGS: //end game
		if (deltaTime.asSeconds() < 3)
			window.draw(m_inGameMessages[WIN]);

		if (deltaTime.asSeconds() > 3 && !unstopable)
		{
			SingleTone::instance().getSound(UNSTOPABLE_SOUND).get()->play();	//unstopable sound
			unstopable = true;
		}
		if (deltaTime.asSeconds() > 3)
		{
			window.clear();
			window.draw(m_inGamePhotos[END_GAME_PHOTO]);
		}
		if (deltaTime.asSeconds() > 6)
		{
			unstopable = false;
		}
		break;
	case START_MSGS:
		if (deltaTime.asSeconds() < 2)		//startingGame
		{
			window.clear();
			window.draw(m_inGameMessages[STARTING]);
		}
		break;
	}
}
