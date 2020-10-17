#pragma once
//--------------------include Section --------------------
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<new>
#include "Const.h"
#include "Menu.h"
#include "Toolbar.h"
#include "Board.h"
#include <fstream>
//--------------------Controller Class definition --------------------
class Controller
{
public:
	Controller();
	virtual ~Controller() = default;
	void manageGame();

	void inMainMenuFunc();
	void inHelpMenuFunc();

	void startGame();
	void presentGame();

	void openClocks();
	void buildGame(std::ifstream& gameFile);
	void openFile(std::ifstream& gameFile);

	void resizeView();
	void gameStatusChecks(std::ifstream& gameFile);
	void checkRestart(std::ifstream& gameFile);
	void checkStageComplition(std::ifstream& gameFile);

	void backToMainMenu(std::ifstream& gameFile);

	void stopMusic(int music);
	void startMusic(int music);
	void playerStopOrStartMusic();

	void pauseGame(std::ifstream& gameFile);
	void createPauseMessage();

private:
	int m_currentMusic = 0;
	int m_levelNum = 1;
	int m_currentHelpMenu;

	bool m_isFirstLevel = true;
	bool m_startingGame = false;
	bool m_inMainMenu = true;
	bool m_inHelpMenu = false;
	bool m_inAnotherHelpMenu = false;

	Menu m_mainMenu;
	Menu m_helpMenu;
	Board m_board;

	sf::Event m_event;
	sf::RenderWindow m_window;
	sf::Clock m_clock;
	sf::Time m_deltaTime;
	sf::View m_playerView;
	sf::View m_toolBarView;
	sf::Vector2f m_current_view;
	sf::Text m_pauseMessage;
};