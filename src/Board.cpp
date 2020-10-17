#include "Board.h"

//--------------- templateCollisionCheck function ---------------
template <typename FwdIt, typename FzdIt, typename Fn>
void templateCollisionCheck(FwdIt begin1, FwdIt end1, FzdIt object, Fn fn)
{
	for (; begin1 != end1; ++begin1)			//template function to check collision between objects
	{
		fn(*begin1, object);
	}
}
//--------------- checkCollision function ---------------
//function to check collision between all the objects
void Board::checkCollision()		
{
	auto function = [](auto& a, auto& b)
	{
		if (collide(*a, *b))
			Collision::instance().handleCollision(*a, *b);
	};

	templateCollisionCheck(m_staticObjects.begin(),
		m_staticObjects.end(), m_slayer.get(), function); //Slayer with Static

	templateCollisionCheck(m_shots.begin(),
		m_shots.end(), m_slayer.get(), function); //Slayer with Shots

	templateCollisionCheck(m_demons.begin(),
		m_demons.end(), m_slayer.get(), function); //Slayer with Demons


	for (auto& demon : m_demons)
		templateCollisionCheck(m_staticObjects.begin(),	//Demons with Static
			m_staticObjects.end(), demon.get(), function);

	for (auto& shots : m_shots)
		templateCollisionCheck(m_demons.begin(), //Demons with Shots
			m_demons.end(), shots.get(), function);

	for (auto& shots : m_shots)
		templateCollisionCheck(m_staticObjects.begin(), //Shots with Static
			m_staticObjects.end(), shots.get(), function);

	for (int i = 0; i < m_demons.size(); i++)
		for (int j = 0; j < m_demons.size(); j++)//Demons with Demons
			if (i == j)
				continue;
			else if (m_demons[i]->getSprite().getGlobalBounds().intersects(m_demons[j]->getSprite().getGlobalBounds()))
				Collision::instance().handleCollision(*m_demons[i], *m_demons[j]);
}
//--------------- collide function ---------------
//checks the collision between 2 sprites
bool collide(GameObject& a, GameObject& b) 
{
	return a.getSprite().getGlobalBounds().intersects(b.getSprite().getGlobalBounds());
}
//--------------- readStageFromFile function ---------------
//function to read stage by stage (from the file to the container)
void Board::readStageFromFile(std::ifstream& gameFile, bool isFirst)
{
	std::string currentLine;							
	std::string stringFromBoard;

	if (!isFirst)
		m_boardRepresentation.clear();
	while (!gameFile.eof())
	{
		std::getline(gameFile, currentLine);
		if (currentLine == END_OF_LEVEL)
			break;
		if (currentLine == END_GAME)	
		{
			m_lastLevel = true;
			break;								
		}
		std::vector < char >  t;
		for (int k = 0; k < currentLine.size(); k++)
			t.push_back(currentLine[k]);

		m_boardRepresentation.push_back(t);
	}
}
//--------------- convertBoardRepresentationToObjects function ---------------
//build the SFML representation from the board representation (from the container)
//creating all objects on with SFML---------------
void Board::convertBoardRepresentationToObjects()
{
	for (int i = 0; i < m_boardRepresentation.size(); i++)	
	{
		for (int j = 0; j < m_boardRepresentation[i].size(); j++)
		{
			sf::Vector2f objectIndex(i, j);
			char Symbol = m_boardRepresentation[i][j];
			switch (Symbol)
			{
			case SLAYER:
				m_slayer = std::make_unique<Slayer>(objectIndex,
					SingleTone::instance().texture(PLAYER_TEXTURE));
				break;
			case FIRE:
				m_staticObjects.emplace_back(std::make_unique<Fire>(objectIndex,
					SingleTone::instance().texture(FIRE_TEXTURE)));
				break;
			case MACHINE_GUN_AMMO:
				m_staticObjects.emplace_back(std::make_unique<ChainGunAmmo>(objectIndex,
					SingleTone::instance().texture(MACHINE_GUN_AMMO_TEXTURE)));
				break;
			case PISTOL_AMMO:
				m_staticObjects.emplace_back(std::make_unique<PistolAmmo>(objectIndex,
					SingleTone::instance().texture(PISTOL_AMMO_TEXTURE)));
				break;
			case SHOTGUN_AMMO:
				m_staticObjects.emplace_back(std::make_unique<ShotGunAmmo>(objectIndex,
					SingleTone::instance().texture(SHOTGUN_AMMO_TEXTURE)));
				break;
			case PLASME_RIFLE_AMMO:
				m_staticObjects.emplace_back(std::make_unique<PlasmaRifleAmmo>(objectIndex,
					SingleTone::instance().texture(PLASME_RILE_AMMO_TEXTURE)));
				break;
			case BFG_AMMO:
				m_staticObjects.emplace_back(std::make_unique<BFGAmmo>(objectIndex,
					SingleTone::instance().texture(BFG_AMMO_TEXTURE)));
				break;
			case SMALL_HEALTH:
				m_staticObjects.emplace_back(std::make_unique<SmallHealth>(objectIndex,
					SingleTone::instance().texture(SMALL_HEALTH_TEXTURE)));
				break;
			case BIG_HEALTH:
				m_staticObjects.emplace_back(std::make_unique<BigHealth>(objectIndex,
					SingleTone::instance().texture(BIG_HEALTH_TEXTURE)));
				break;
			case ULTRA_HEALTH:
				m_staticObjects.emplace_back(std::make_unique<UltraHealth>(objectIndex,
					SingleTone::instance().texture(ULTRA_HEALTH_TEXTURE)));
				break;
			case ARMOR:
				m_staticObjects.emplace_back(std::make_unique<Armor>(objectIndex,
					SingleTone::instance().texture(ARMOR_TEXTURE)));
				break;
			case HORI_WALL:
				m_staticObjects.emplace_back(std::make_unique<HorizontalWall>(objectIndex,
					SingleTone::instance().texture(HORI_WALL_TEXTURE)));
				break;
			case VER_WALL:
				m_staticObjects.emplace_back(std::make_unique<VerticalWall>(objectIndex,
					SingleTone::instance().texture(VER_WALL_TEXTURE)));
				break;
			case DIAG_WALL_R:
				m_staticObjects.emplace_back(std::make_unique<DiagonalWallR>(objectIndex,
					SingleTone::instance().texture(HORI_WALL_TEXTURE)));
				break;
			case DIAG_WALL_L:
				m_staticObjects.emplace_back(std::make_unique<DiagonalWallL>(objectIndex,
					SingleTone::instance().texture(DIAGONAL_LEFT_WALL_TEXTURE)));
				break;
			case BARON:
				m_demons.emplace_back(std::make_unique<BaronOfHell>(objectIndex,
					SingleTone::instance().texture(BARON_OF_HELL_TEXTURE)));
				break;
			case CACODEMON:
				m_demons.emplace_back(std::make_unique<Cacodemon>(objectIndex,
					SingleTone::instance().texture(CACODEMON_TEXTURE)));
				break;
			case REVENANT:
				m_demons.emplace_back(std::make_unique<Revenant>(objectIndex,
					SingleTone::instance().texture(REVENANT_TEXTURE)));
				break;
			case CYBERDEMON:
				m_demons.emplace_back(std::make_unique<CyberDemon>(objectIndex,
					SingleTone::instance().texture(CYBERDEMON_TEXTURE)));
				break;
			case HEAVY_WEAPON_DUDE:
				m_demons.emplace_back(std::make_unique<HeavyWeaponDude>(objectIndex,
					SingleTone::instance().texture(HEAVY_WEAPON_DUDE_TEXTURE)));
				break;
			case MANCUBUS:
				m_demons.emplace_back(std::make_unique<Mancubus>(objectIndex,
					SingleTone::instance().texture(MANCUBUS_TEXTURE)));
				break;
			}
		}
	}
}
//--------------- buildBoard function ---------------
//function to build the board, different map after each map and than randomize maps
void Board::buildBoard(sf::RenderWindow& window, int levelNum)
{
	sf::RectangleShape tempRec;
	tempRec.setSize(sf::Vector2f(8000, 8000));
	switch (levelNum)
	{
	case 1:
		tempRec.setTexture(&SingleTone::instance().texture(LEVEL_ONE_BACK_TEXTURE));
		break;
	case 2:
		tempRec.setTexture(&SingleTone::instance().texture(LEVEL_TOW_BACK_TEXTURE));
		break;
	case 3:
		tempRec.setTexture(&SingleTone::instance().texture(LEVEL_THREE_BACK_TEXTURE));
		break;
	default:
		auto random = rand() % 3;
		switch (random)
		{
		case 0:
			tempRec.setTexture(&SingleTone::instance().texture(LEVEL_ONE_BACK_TEXTURE));
			break;
		case 1:
			tempRec.setTexture(&SingleTone::instance().texture(LEVEL_TOW_BACK_TEXTURE));
			break;
		case 2:
			tempRec.setTexture(&SingleTone::instance().texture(LEVEL_THREE_BACK_TEXTURE));
			break;
		}
		break;
	}

	for (int i = 0; i < NUM_OF_BACK; i++)
	{
		m_backGroundRec[i] = tempRec;
		m_backGroundRec[i].setSize(sf::Vector2f(10000, 10000));

		switch (i)
		{
		case 0:
			m_backGroundRec[i].setPosition(FIRST_BACK_LOC);
			break;
		case 1:
			m_backGroundRec[i].setPosition(SECOND_BACK_LOC);
			break;
		case 2:
			m_backGroundRec[i].setPosition(THIRD_BACK_LOC);
			break;
		case 3:
			m_backGroundRec[i].setPosition(FOURTH_BACK_LOC);
			break;
		}
	}
	if (levelNum == 1)
	{
		static bool onlyOnce = false;
		if (!onlyOnce)
		{
			m_toolBar.initializeToolBar(window);
			m_messages.initializeInGameMessages();
			onlyOnce = true;
		}
	}
	m_toRestart = false;
	m_startTheNextLevel = false;
	m_lastDeaths = 0;
}
//--------------- draw function ---------------
//function to draw all the game on the render window,(EVERYTHING - from a-z)
void Board::draw(sf::RenderWindow& window, sf::Time deltaTime, sf::View& playerView, sf::View& toolBarView)
{
	window.setView(playerView);

	for (auto& back : m_backGroundRec)		
		window.draw(back);

	for (auto& staticObj : m_staticObjects)
	{
		staticObj->setSpriteSheet(deltaTime);
		staticObj->draw(window);
	}
	if (m_slayer->getIsDead())
	{
		m_slayer->draw(window);
		for (auto& demons : m_demons)
			demons->draw(window);
	}
	else
	{
		for (auto& demons : m_demons)
			demons->draw(window);
		m_slayer->draw(window);
	}
	for (auto& shots : m_shots)
		shots->draw(window);

	window.setView(toolBarView);	//handle several views and go back to players view
	m_toolBar.draw(window);
	window.setView(playerView);

	if (m_slayer->getFinishedDying())
		restartMessageInitiate(window, playerView, deltaTime);

	else if (!m_movingToNextLevel && !m_slayer->getFinishedDying()
		&& !m_endGame && !m_startMessage)
		m_messageTimer = sf::seconds(0.0);

	handleMessages(window, playerView, deltaTime);
}
//--------------- swapWeapons function ---------------
//cahnge weapons
void Board::swapWeapons(sf::Keyboard::Key key)	
{
	switch (key)
	{
	case sf::Keyboard::Num1:
		m_slayer->setCurrentWeapon(PISTOL);
		break;
	case sf::Keyboard::Num2:
		m_slayer->setCurrentWeapon(SHOTGUN);
		break;
	case sf::Keyboard::Num3:
		m_slayer->setCurrentWeapon(CHAIN_GUN);
		break;
	case sf::Keyboard::Num4:
		m_slayer->setCurrentWeapon(PLASMA_RIFLE);
		break;
	case sf::Keyboard::Num5:
		m_slayer->setCurrentWeapon(BFG);
		break;
	}
}
//--------------- handleShooting function ---------------
//handle the shooting of each weapon---and inserting to m_shots
void Board::handleShooting(sf::Event event, sf::RenderWindow& window, sf::Time deltaTime)
{
	static float temp = 0.0f;
	temp += deltaTime.asSeconds();
	auto currentWeapon = m_slayer->getCurrentWeapon();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (!m_slayer->getIsDead()))
	{
		m_slayer->stopObject();

		sf::Vector2i pixellocation = sf::Mouse::getPosition(window);
		sf::Vector2f worldlocation = window.mapPixelToCoords(pixellocation);		//converting to the real coordinates

		switch (currentWeapon)
		{
		case PISTOL:
			if (m_slayer->getWeaponAmmo(PISTOL) != 0 && (temp > (0.6f)))
			{
				m_slayer->setIsShooting(true);
				m_shots.emplace_back(std::make_unique<Pistol>(m_slayer->getObjectPosition(),
					SingleTone::instance().texture(PISTOL_SHOT_TEXTURE), worldlocation));
				temp = 0.0f;
				m_slayer->setShootingDirection(m_shots.back()->getShootingDirection());
				m_slayer->updateShooting(PISTOL);
				SingleTone::instance().getSound(PISTOL_FIRE_SOUND).get()->play();
			}
			break;
		case SHOTGUN:
			if (m_slayer->getWeaponAmmo(SHOTGUN) != 0 && (temp > (1.0f)))
			{
				m_slayer->setIsShooting(true);
				m_shots.emplace_back(std::make_unique<ShotGun>(m_slayer->getObjectPosition(),
					SingleTone::instance().texture(SHOTGUN_SHOT_TEXTURE), worldlocation));
				temp = 0.0f;
				m_slayer->setShootingDirection(m_shots.back()->getShootingDirection());
				m_slayer->updateShooting(SHOTGUN);
				SingleTone::instance().getSound(SHOTGUN_FIRE_SOUND).get()->play();

			}
			break;
		case CHAIN_GUN:
			if (m_slayer->getWeaponAmmo(CHAIN_GUN) != 0 && (temp > (0.12f)))
			{
				m_slayer->setIsShooting(true);
				m_shots.emplace_back(std::make_unique<ChainGun>(m_slayer->getObjectPosition(),
					SingleTone::instance().texture(MACHINE_GUN_BULLET_TEXTURE), worldlocation));
				temp = 0.0f;
				m_slayer->setShootingDirection(m_shots.back()->getShootingDirection());
				m_slayer->updateShooting(CHAIN_GUN);
				SingleTone::instance().getSound(CHAINGUN_FIRE_SOUND).get()->play();

			}
			break;
		case PLASMA_RIFLE:
			if (m_slayer->getWeaponAmmo(PLASMA_RIFLE) != 0 && (temp > (0.7f)))
			{
				m_slayer->setIsShooting(true);
				m_shots.emplace_back(std::make_unique<PlasmaRifle>(m_slayer->getObjectPosition(),
					SingleTone::instance().texture(PLASME_RIFLE_SHOT_TEXTURE), worldlocation));
				m_slayer->setShootingDirection(m_shots.back()->getShootingDirection());
				m_slayer->updateShooting(PLASMA_RIFLE);
				temp = 0.0f;
				SingleTone::instance().getSound(PLASMA_SHOT_SOUND).get()->play();

			}
			break;
		case BFG:
			if (m_slayer->getWeaponAmmo(BFG) != 0 && (temp > (2.0f)))
			{
				m_slayer->setIsShooting(true);
				m_shots.emplace_back(std::make_unique<BFG9000>(m_slayer->getObjectPosition(),
					SingleTone::instance().texture(BFG_SHOT_TEXTURE), worldlocation));
				temp = 0.0f;
				m_slayer->setShootingDirection(m_shots.back()->getShootingDirection());
				m_slayer->updateShooting(BFG);
				SingleTone::instance().getSound(BFG_FIRE_SOUND).get()->play();
			}
			break;
		}
	}
	else
		m_slayer->setIsShooting(false);

	for (auto& shots : m_shots)
		shots->move(sf::Vector2f(0, 0), deltaTime);
}
//--------------- updateGameStats function ---------------
//update the game stats to the toolbar
void Board::updateGameStats()	
{
	m_toolBar.updateStats(m_slayer->getWeaponAmmo(m_slayer->getCurrentWeapon()),
		m_slayer->getHealth(), m_slayer->getArmor(), m_slayer->getDashTimer(), m_slayer->getCurrentWeapon());
}
//--------------- handleDemonsShooting function ---------------
//handle the shooting of the shooting demons---- ( 3 of them)
void Board::handleDemonsShooting(sf::Time deltaTime)
{
	for (auto& demon : m_demons)		
	{
		if (!m_slayer->getIsDead())
		{
			if (typeid(*demon) == typeid(CyberDemon) && !demon->getIsDead())
			{
				if (distance(m_slayer->getObjectPosition(), demon->getObjectPosition()) < CYBERDEMON_RANGE)
				{
					demon->stopObject();
					if (demon->getCanHit())
					{
						demon->setIsAttacking(true);
						m_shots.emplace_back(std::make_unique<CyberDemonShot>(demon->getObjectPosition(),
							SingleTone::instance().texture(CYBERDEMON_SHOT_TEXTURE), m_slayer->getObjectPosition()));
						demon->setCanHit(false);
					}
				}
			}
			if (typeid(*demon) == typeid(Mancubus) && !demon->getIsDead())
			{
				if (distance(m_slayer->getObjectPosition(), demon->getObjectPosition()) < MANCUBUS_RANGE)
				{
					demon->stopObject();
					if (demon->getCanHit())
					{
						demon->setIsAttacking(true);
						m_shots.emplace_back(std::make_unique<MancubusShot>(demon->getObjectPosition(),
							SingleTone::instance().texture(MANCUBUS_SHOT_TEXTURE), m_slayer->getObjectPosition()));
						demon->setCanHit(false);
					}
				}
			}
			if (typeid(*demon) == typeid(HeavyWeaponDude) && !demon->getIsDead())
			{
				if (distance(m_slayer->getObjectPosition(), demon->getObjectPosition()) < DUDE_RANGE)
				{
					demon->stopObject();
					if (demon->getCanHit())
					{
						demon->setIsAttacking(true);
						m_shots.emplace_back(std::make_unique<HeavyWeaponDudeShot>(demon->getObjectPosition(),
							SingleTone::instance().texture(DUDE_SHOT_TEXTURE), m_slayer->getObjectPosition()));
						demon->setCanHit(false);
					}
				}
			}
		}
	}
}
//--------------- handleDemonsActions function ---------------
//handle the demons action, from direction, moving and relevant updates
void Board::handleDemonsActions(sf::Time deltaTime)	
{
	for (auto& demon : m_demons)
	{
		if (!demon->getCanHit())
			demon->countUntillNextHit(deltaTime);
	}

	for (auto& demon : m_demons)
	{
		if (m_slayer->getIsDead())
			demon->updateSlayerDeathStatus();
		else
			demon->setDirRate(1.5);

		demon->updateSlayerLocation(m_slayer->getSprite().getPosition());
		demon->changeDirection(deltaTime);

		if (!demon->getIsDead() && demon->getOnView())//get update sprite out, so when dies he can do only that, without all other function
			demon->move(demon->getDirection(), deltaTime);
	}
	handleDemonsShooting(deltaTime);
}
//--------------- handlePlayerActions function ---------------
//handle the slayer movement and updates
void Board::handlePlayerActions(sf::Time deltaTime)
{
	if (!m_slayer->getFinishedDying())
		m_slayer->changeDirection(deltaTime);

	if (!m_movingToNextLevel && !m_startMessage)
		m_slayer->move(m_slayer->getDirection(), deltaTime);
	m_slayer->countUntillNextHit(deltaTime);
}
//--------------- checkDelete function ---------------
//function  to check wich element needs todelete and delete him
void Board::checkDelete()
{
	for (int i = 0; i < m_shots.size(); i++)
	{
		if (m_shots[i]->getDeleteStatus())
			m_shots.erase(m_shots.begin() + i);
	}
	for (int i = 0; i < m_demons.size(); i++)
	{
		if (m_demons[i]->getDeleteStatus())
			m_demons.erase(m_demons.begin() + i);
	}
	for (int i = 0; i < m_staticObjects.size(); i++)
	{
		if (m_staticObjects[i]->getDeleteStatus())
			m_staticObjects.erase(m_staticObjects.begin() + i);
	}
}
//--------------- isStageCompleted function ---------------
//check if stage is completed
bool Board::isStageCompleted()	
{
	for (auto& demon : m_demons)
		if (!demon->getIsDead())
			return false;

	if (m_slayer->getIsDead())
		return false;

	return true;
}
//--------------- handleView function ---------------
//handle the view on the render window
void Board::handleView(sf::RenderWindow& window, sf::View& viewPlayer, sf::Vector2f current_view)
{
	if (m_slayer->getObjectPosition().x + 10 > window.getSize().x / 2)
		current_view.x = m_slayer->getObjectPosition().x + 10;					
	else if (m_slayer->getObjectPosition().x - 10 < window.getSize().x / 2)
		current_view.x = m_slayer->getObjectPosition().x - 10;

	if (m_slayer->getObjectPosition().y + 10 > window.getSize().y / 2)
		current_view.y = m_slayer->getObjectPosition().y + 10;
	else if (m_slayer->getObjectPosition().y - 10 < window.getSize().y / 2)
		current_view.y = m_slayer->getObjectPosition().y - 10;

	viewPlayer.setCenter(current_view);
	window.setView(viewPlayer);

	checkMonsterInsideView(window);
}
//--------------- checkMonsterInsideView function ---------------
//if monster is in view, start tracking the slayer
void Board::checkMonsterInsideView(sf::RenderWindow& window)	
{
	sf::Vector2f viewCenter(window.getView().getCenter());
	sf::Vector2f viewSize(window.getView().getSize());
	sf::FloatRect currentViewRect(viewCenter - viewSize / 2.f, viewSize);

	for (int i = 0; i < m_demons.size(); i++)
		if (m_demons[i]->getSprite().getGlobalBounds().intersects(currentViewRect))
			m_demons[i]->setOnView();
}
//--------------- clearDataStructures function ---------------
//clear data structures between the levels
void Board::clearDataStructures()
{
	m_backToMenu = false;	
	delete m_slayer.release();
	m_demons.clear();
	m_staticObjects.clear();
	m_shots.clear();
}
//--------------- handleMessages function ---------------
//handle different messages--- from in game message class
void Board::handleMessages(sf::RenderWindow& window, sf::View& view, sf::Time deltaTime)
{
	sf::Vector2f currentView;

	if (m_startMessage)
	{
		m_messageTimer += deltaTime;
		m_messages.setMessagePosition(window, view, deltaTime, START_MSGS);
		m_messages.handleGameMessages(window, view, m_messageTimer, START_MSGS);
		if (m_messageTimer.asSeconds() > 2)
		{
			m_messageTimer = sf::seconds(0.0);
			m_startMessage = false;
		}
	}

	if (m_movingToNextLevel)
	{
		m_messageTimer += deltaTime;
		m_messages.setMessagePosition(window, view, deltaTime, LEVEL_COMPLETE_MSGS);
		m_messages.handleGameMessages(window, view, m_messageTimer, LEVEL_COMPLETE_MSGS);
		if (m_messageTimer.asSeconds() > 6)
		{
			m_messageTimer = sf::seconds(0.0);
			m_movingToNextLevel = false;
			m_startTheNextLevel = true;
		}
	}
	if (m_endGame)
	{
		m_messageTimer += deltaTime;
		m_messages.setMessagePosition(window, view, deltaTime, END_GAME_MSGS);
		m_messages.handleGameMessages(window, view, m_messageTimer, END_GAME_MSGS);
		if (m_messageTimer.asSeconds() > 6)
		{
			m_messageTimer = sf::seconds(0.0);
			m_endGame = false;
			m_backToMenu = true;
		}
	}

}
//--------------- moveToNextLevelMessageInitiate function ---------------
// some more functions to handle and initiate the messages
void Board::moveToNextLevelMessageInitiate()	
{
	if (!m_slayer->getIsDead())
		m_movingToNextLevel = true;
}
//--------------- restartMessageInitiate function ---------------
void Board::restartMessageInitiate(sf::RenderWindow& window, sf::View& view, sf::Time deltaTime)
{
	m_messageTimer += deltaTime;
	m_messages.setMessagePosition(window, view, m_messageTimer, RESTART_MSGS);
	m_toRestart = true;
	m_messages.handleGameMessages(window, view, m_messageTimer, RESTART_MSGS);
}
//--------------- endGameMessageInitiate function ---------------
void Board::endGameMessageInitiate()
{
	if (!m_slayer->getIsDead())
		m_endGame = true;
}
//--------------- startGameMessageInitiate function ---------------
void Board::startGameMessageInitiate()
{
	m_startMessage = true;
	m_messageTimer = sf::seconds(0.0);
}

//--------------- distance function ---------------
//function to calculate distance
float Board::distance(sf::Vector2f vec1, sf::Vector2f vec2)
{
	return sqrt(pow(vec1.x - vec2.x, 2) + pow(vec1.y - vec2.y, 2));
}
//--------------- checkKillingSpree function ---------------
//function to check and activate killing spree sounds
void Board::checkKillingSpree(sf::Time deltaTime)
{
	bool killedTogether = false;
	m_totallDeaths = 0;

	for(auto&demon : m_demons)
		if (demon->getIsDead())
			m_totallDeaths++;		
	
		if (m_lastDeaths < m_totallDeaths
		&& !m_startKillingSpreeCheck)
	{
		if (m_totallDeaths - m_lastDeaths > 1)
			killedTogether = true;

		m_killingCounter = m_totallDeaths - m_lastDeaths;

		m_startKillingSpreeCheck = true;
		m_lastDeaths = m_totallDeaths;
	}
	if (m_startKillingSpreeCheck)
	{
		m_killingSpreeTimer += deltaTime;

		if ((m_killingSpreeTimer <= sf::seconds(2.0) &&
			m_lastDeaths < m_totallDeaths) || killedTogether)
		{
			if (killedTogether)
			{
				killedTogether = false;
			}
			else
			{
				m_killingCounter++;
			}
			m_lastDeaths = m_totallDeaths;
			m_killingSpreeTimer = sf::seconds(0.0);
			m_activateKillingSound = true;
		}
		 if (m_killingSpreeTimer > sf::seconds(2.0))
		 {
			m_killingCounter = 0;
			m_startKillingSpreeCheck = false;
			m_killingSpreeTimer = sf::seconds(0.0);
		}

		if (m_activateKillingSound && !m_slayer->getIsDead())   
		{
			switch (m_killingCounter)
			{                                 
			case 2:
				SingleTone::instance().getSound(DOUBLE_KILL_SOUND).get()->play();
				break;
			case 3:
				SingleTone::instance().getSound(MULTI_KILL_SOUND).get()->play();
				break;
			case 4:
				SingleTone::instance().getSound(KILLING_SPREE_SOUND).get()->play();
				break;
			case 5:
				SingleTone::instance().getSound(ULTRA_KILL_SOUND).get()->play();
				break;
			case 6:
				SingleTone::instance().getSound(GODLIKE_SOUND).get()->play();
				break;
			}
			m_activateKillingSound = false;
		}

	}
}
