#include "Controller.h"
//--------------- Controller Constructor ---------------
Controller::Controller() : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "DOOM 2D - Harel Savitzky")
{
	m_current_view = sf::Vector2f((float)m_window.getSize().x / 2, (float)m_window.getSize().y / 2);			//initializing views
	m_window.setFramerateLimit(60);

	m_playerView.reset(sf::FloatRect((float)0, (float)0, (float)m_window.getSize().x, (float)m_window.getSize().y));
	m_playerView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

	m_toolBarView.reset(sf::FloatRect((float)0, (float)0, (float)m_window.getSize().x, (float)m_window.getSize().y));
	m_toolBarView.setViewport(sf::FloatRect(0, 0.92, 0.6f, 0.08f));
}
//--------------- startGame function ---------------
//couple of actions when play pressed
void Controller::startGame()
{
	m_inMainMenu = false;		
	m_startingGame = true;
	m_currentMusic = 1;
	stopMusic(MENU_MUSIC);
	startMusic(GAME_MUSIC);
	m_board.startGameMessageInitiate();
}
//--------------- openClocks function ---------------
//function to open clocks when the game is initiated
void Controller::openClocks()
{
	if (m_startingGame)
	{												//out of menu?
		m_deltaTime = m_clock.restart();		//start the clocks
		m_deltaTime += m_deltaTime;
		m_startingGame = false;
	}
}
//--------------- resizeView function ---------------
//function to keep aspect ratio normal when the window is resized
void Controller::resizeView()
{
	float aspectRatio = float(m_window.getSize().x / float(m_window.getSize().y));
	m_playerView.setSize(WINDOW_HEIGHT * aspectRatio, WINDOW_HEIGHT);				//handle resize
	m_toolBarView.setSize(WINDOW_HEIGHT * aspectRatio, WINDOW_HEIGHT);
}
//--------------- buildGame function ---------------
// function to build the current game level, each level at a time
void Controller::buildGame(std::ifstream& gameFile)
{
	if (m_isFirstLevel)
	{
		m_mainMenu.mainMenuInitialize(m_window.getSize().x, m_window.getSize().y);
		m_helpMenu.helpMenuInitialize(m_window.getSize().x, m_window.getSize().y);		//build the game
		openFile(gameFile);
		startMusic(MENU_MUSIC);
	}
	m_board.buildBoard(m_window, m_levelNum); //temp location
	m_board.readStageFromFile(gameFile, m_isFirstLevel);
	m_board.convertBoardRepresentationToObjects();

	if (m_isFirstLevel)
		m_isFirstLevel = false;
}
//--------------- manageGame function ---------------
//main game mannaging function, from building the game to playing it and 
//any other action from program starts untill program exits
void Controller::manageGame()
{
	std::ifstream gameFile;
	buildGame(gameFile);
	srand(time(NULL));//

	while (m_window.isOpen())				//main game/event loops
	{
		while (m_window.pollEvent(m_event))
		{
			switch (m_event.type)
			{
			case sf::Event::Closed:
				m_window.close();		//close window event
				break;
			case sf::Event::Resized:
				resizeView();			//Resized event
				break;
			case sf::Event::KeyReleased:	//in menu event
				if (m_inHelpMenu)
					inHelpMenuFunc();
				else if (m_inMainMenu)
					inMainMenuFunc();
				else
					m_board.swapWeapons(m_event.key.code);	//swap weapons
				break;
			}
		}
		if (!m_inMainMenu)
		{
			openClocks();
			m_deltaTime = m_clock.restart();

			m_board.handleDemonsActions(m_deltaTime);			//functions to handle the game
			m_board.handlePlayerActions(m_deltaTime);				//slayer -demons -shooting /....
			m_board.handleShooting(m_event, m_window, m_deltaTime);
			m_board.handleView(m_window, m_playerView, m_current_view);
			m_board.updateGameStats();

			pauseGame(gameFile);	//handle pause
			gameStatusChecks(gameFile);	//check game status
		}
		playerStopOrStartMusic();
		presentGame();
	}
	gameFile.close();
}
//--------------- gameStatusChecks function ---------------
//check what is the game status, if objects needs to be deleted/
//killing spree/ collision / needs to restart/ stage complete
void Controller::gameStatusChecks(std::ifstream& gameFile)
{
	m_board.checkDelete();		
	m_board.checkKillingSpree(m_deltaTime);
	m_board.checkCollision();		//check different cases
	checkRestart(gameFile);
	checkStageComplition(gameFile);
}
//--------------- checkStageComplition function ---------------
//function to check and handle stage complition
void Controller::checkStageComplition(std::ifstream& gameFile)
{
	if (m_board.getBackToMenu())
		backToMainMenu(gameFile);

	if (m_board.isStageCompleted())
	{
		if (m_board.getIsLast())
		{
			m_board.endGameMessageInitiate();	//initiate end game message
		}
		else
		{
			if (m_board.getStartTheNextLevel())	
			{
				m_levelNum++;
				m_board.clearDataStructures();	//and  build next one
				buildGame(gameFile);
			}
			else
				m_board.moveToNextLevelMessageInitiate();// initiate next level message
		}
	}
}
//--------------- presentGame function ---------------
//function to present the game/ menues & gameplay
void Controller::presentGame()
{
	m_window.clear(DARK_GREY_COLOR);
	if(m_inAnotherHelpMenu)					//present differnet menues
		m_helpMenu.drawInnerHelp(m_window, m_currentHelpMenu);
	else if (m_inHelpMenu)
		m_helpMenu.drawHelpMenu(m_window);
	else if (m_inMainMenu)
		m_mainMenu.drawMenu(m_window);
	else
		m_board.draw(m_window, m_deltaTime, m_playerView, m_toolBarView);	//present the game

	m_window.display();
}
//--------------- inMainMenuFunc function ---------------
//function to handle the main menu
void Controller::inMainMenuFunc()
{
	switch (m_event.key.code)
	{
	case sf::Keyboard::Up:
		m_mainMenu.MoveUp();
		break;					//move up and down in menu
	case sf::Keyboard::Down:
		m_mainMenu.MoveDown();
		break;

	case sf::Keyboard::Return:				//enter pressed
		switch (m_mainMenu.getPressedItem())
		{
		case PLAY_BUTTON:
			startGame();
			break;
		case HELP_BUTTON:
			m_inHelpMenu = true;
			break;
		case QUIT_BUTTON:
			m_window.close();
			break;
		}
	}
}
//--------------- inHelpMenuFunc function ---------------
//function to handle the help menu
void Controller::inHelpMenuFunc()	//handle options menu
{

	switch (m_event.key.code)
	{
	case sf::Keyboard::Up:
		m_helpMenu.MoveUp();
		break;					//move up and down in menu
	case sf::Keyboard::Down:
		m_helpMenu.MoveDown();
		break;
	case sf::Keyboard::Escape:
		if(m_inAnotherHelpMenu)	
			m_inAnotherHelpMenu = false;
		else
			m_inHelpMenu = false;
		break;
		m_helpMenu.MoveDown();
		break;

	case sf::Keyboard::Return:				
		if (!m_inAnotherHelpMenu)
		{
			switch (m_helpMenu.getPressedItem())
			{
			case ARMORY_BUTTON:
				m_inAnotherHelpMenu = true;
				m_currentHelpMenu = ARMORY_BUTTON;
				m_helpMenu.drawInnerHelp(m_window, ARMORY_BUTTON);
				break;
			case DEMONS_BUTTON:
				m_inAnotherHelpMenu = true;
				m_currentHelpMenu = DEMONS_BUTTON;
				m_helpMenu.drawInnerHelp(m_window, DEMONS_BUTTON);
				break;
			case CONTROLS_BUTTON:
				m_inAnotherHelpMenu = true;
				m_currentHelpMenu = CONTROLS_BUTTON;
				m_helpMenu.drawInnerHelp(m_window, CONTROLS_BUTTON);
				break;
			}
		}
	}
}
//--------------- openFile function ---------------
//function to open the levels file
void Controller::openFile(std::ifstream& gameFile)
{
	gameFile.open("levels.txt");					//function to open the game file

	if (!gameFile.is_open())				//if the file dosent open throw exception
		throw std::runtime_error("\nException throwed:\nCant open file\n");
}
//--------------- checkRestart function ---------------
//function to check and to initiate restart if needed
void Controller::checkRestart(std::ifstream& gameFile)	//check if  needs to restat and ask user
{
	if (m_board.getToRestart())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			m_board.clearDataStructures();
			m_board.convertBoardRepresentationToObjects();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{
			m_board.setToRestart(false);
			backToMainMenu(gameFile);
			m_window.display();
		}
	}
}
//--------------- backToMainMenu function ---------------
//actions to take if we got back to the main menu - wich happens
//when player is dead and dosent wish to continue/player finished the game/ player exits
void Controller::backToMainMenu(std::ifstream& gameFile)
{
	m_board.setToRestart(false);	//initialize all that necesary when back to menu
	m_levelNum = 1;
	gameFile.seekg(0);
	m_board.setLastLevel(false);
	m_playerView.reset(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	m_window.setView(m_playerView);
	m_currentMusic = 0;
	stopMusic(GAME_MUSIC);
	startMusic(MENU_MUSIC);
	m_board.clearDataStructures();
	m_board.buildBoard(m_window, m_levelNum);
	m_board.readStageFromFile(gameFile, m_isFirstLevel);
	m_board.convertBoardRepresentationToObjects();
	m_inMainMenu = true;
}
//--------------- startMusic function ---------------
//function to start menu/game music
void Controller::startMusic(int music)
{
	switch (music)
	{
	case MENU_MUSIC:
		SingleTone::instance().getMusic(MENU_MUSIC).get()->setLoop(true);
		SingleTone::instance().getMusic(MENU_MUSIC).get()->setVolume(25);
		SingleTone::instance().getMusic(MENU_MUSIC).get()->play();
		break;
	case GAME_MUSIC:
		SingleTone::instance().getMusic(GAME_MUSIC).get()->setLoop(true);
		SingleTone::instance().getMusic(GAME_MUSIC).get()->setVolume(18);
		SingleTone::instance().getMusic(GAME_MUSIC).get()->play();
		break;
	}
}
//--------------- playerStopOrStartMusic function ---------------
//function to stop / pause the music (by the player)
void Controller::playerStopOrStartMusic()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		if (!SingleTone::instance().getMusic(m_currentMusic).get()->getStatus())
			startMusic(m_currentMusic);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		stopMusic(m_currentMusic);
	}
}
//--------------- pauseGame function ---------------
//function to pause the game (by the player)
void Controller::pauseGame(std::ifstream& gameFile)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		createPauseMessage();
		m_window.draw(m_pauseMessage);
		m_window.display();
		while (1)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
			{
				break;
			}
		}
		m_deltaTime = m_clock.restart();
	}
}
//--------------- stopMusic function ---------------
//function to stop the current music
void Controller::stopMusic(int music)
{
	switch (music)
	{
	case MENU_MUSIC:
		SingleTone::instance().getMusic(MENU_MUSIC).get()->stop();
		break;
	case GAME_MUSIC:
		SingleTone::instance().getMusic(GAME_MUSIC).get()->stop();
		break;
	}
}
//--------------- createPauseMessage function ---------------
//function to create the pause message
void Controller::createPauseMessage()	//neccesary over here
{
	m_pauseMessage.setOutlineThickness(5);
	m_pauseMessage.setFont(*SingleTone::instance().getFont(NEW_DOOM_FONT).get());
	m_pauseMessage.setCharacterSize(WINDOW_WIDTH / 8);
	m_pauseMessage.setOrigin(m_pauseMessage.getLocalBounds().width * 0.5,
		m_pauseMessage.getLocalBounds().height * 0.5);
	m_pauseMessage.setFillColor(DARK_RED_COLOR);
	m_pauseMessage.setString(PAUSED_MESSAGE);
	m_pauseMessage.setPosition(m_playerView.getCenter().x, m_playerView.getCenter().y);
}