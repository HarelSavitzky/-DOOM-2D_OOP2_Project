#include "Demons.h"
//constructor--------------
Demons::Demons()
{}
Demons::Demons(sf::Vector2f location, const sf::Texture& texture)
	: MovingObject(location, texture)                        
{}
//--------------- startGame function ---------------
//set the sprite of the demons, works for all the demons
//generic functions that activates animation of movement /attacking/death of all the demons
//each demon holds all the neccesary information for this function
//this function also activates attacking and death sound of the monsters
void Demons::setSpriteSheet(sf::Time deltaTime)				
{												
	m_movingTimer += deltaTime;				
										
	setSpriteSource(sf::Vector2f(getMovingDirection() * getRecSize().x, getSpriteSource().y));
	if (!getIsDead())
	{
		if (!m_isAttacking && !getIsStopped())					//if moving, activate movement animation
		{
			if (m_movingTimer.asSeconds() > m_swichFrameRate)
			{
				setSpriteSource(sf::Vector2f(getSpriteSource().x, getSpriteSource().y + 1));
				m_movingTimer = sf::seconds(0.0);
			}
			if (getSpriteSource().y >= getWalkingFrames())
			{
				setSpriteSource(sf::Vector2f(getSpriteSource().x, 0));
			}

			getSprite().setTextureRect(sf::IntRect(getSpriteSource().x, getSpriteSource().y * getRecSize().y, getRecSize().x, getRecSize().y));
			getSprite().setScale(getScaleSize().x, getScaleSize().y);
		}
		else if (m_isAttacking)										//activate attacking animation
		{
			if (m_activateAttackSound && m_isAShooter)
			{
				playDemonActionSound(ATTACKING);
				m_activateAttackSound = false;
			}

			if (m_movingTimer.asSeconds() > m_swichFrameRate)
			{
				setSpriteSource(sf::Vector2f(getSpriteSource().x, getSpriteSource().y + 1));
				m_movingTimer = sf::seconds(0.0);
			}
			if (getSpriteSource().y >= (getAttackingFrames() + getWalkingFrames()) - 1)
			{
				if (m_activateAttackSound && !m_isAShooter)
				{
					playDemonActionSound(ATTACKING);
					m_activateAttackSound = false;
				}
				if (m_isAShooter)
					setSpriteSource(sf::Vector2f(getMovingDirection(), getAttackingSource().y));
				else
				{
					setAttackingSource(sf::Vector2f(getMovingDirection(), getAttackingSource().y));
					setSpriteSource(sf::Vector2f(getMovingDirection(), 0));
				}
				m_isAttacking = false;
			}
		}
		getSprite().setTextureRect(sf::IntRect(getMovingDirection() * getRecSize().x,
			getSpriteSource().y * getRecSize().y, getRecSize().x, getRecSize().y));
	}
	else if (!getfinishDeath())
	{
		if (m_activateDeathSound)							//activate death animation
		{
			playDemonActionSound(DEATH);
			m_activateDeathSound = false;
		}
		if (m_movingTimer.asSeconds() > m_swichFrameRate)
		{
			setDeathSource(sf::Vector2f(getDeathSource().x + getRecSize().x, getDeathSource().y));
			m_movingTimer = sf::seconds(0.0);
		}
		if (getDeathSource().x >= getRecSize().x * getDeathFrames())
		{
			setfinishDeath();
			setDeathSource(sf::Vector2f(getDeathSource().x - getRecSize().x, getDeathSource().y));
		}
		getSprite().setTextureRect(sf::IntRect(getDeathSource().x, getDeathSource().y, getRecSize().x, getRecSize().y)); // get rec size
	}
	setIsStopped(false);
}
//--------------- setOnView function ---------------
//activate a sound when monster on view and make bool positive
//so monster will start tracking the slayer
void Demons::setOnView()
{
	m_onView = true;
	if (m_activateSightSound)			
	{
		playDemonActionSound(ON_SIGHT);
		m_activateSightSound = false;
	}
}
//--------------- setRandDirection function ---------------
//function the set random direction
void Demons::setRandDirection()		
{
	auto randDir = rand() % 8;
	auto direction = (sf::Vector2f(0, 0));

	switch (randDir)
	{
	case 0:
		direction.y -= getSpeed();
		break;
	case 1:
		direction.x -= getSpeed();
		break;
	case 2:
		direction.x += getSpeed();
		break;
	case 3:
		direction.x += getSpeed();
		direction.y += getSpeed();
		break;
	case 4:
		direction.x -= getSpeed();
		direction.y -= getSpeed();
		break;
	case 5:
		direction.x += getSpeed();
		direction.y -= getSpeed();
		break;
	case 6:
		direction.x -= getSpeed();
		direction.y += getSpeed();
		break;
	case 7:
		direction.y += getSpeed();
		break;

	}
	setDirection(direction);
	setMovingDirection();
	m_randMove = false;
}
//--------------- changeDirection function ---------------
//function to track the slayer, this function changes the monster direction according
//to slayer location
void Demons::changeDirection(sf::Time deltaTime)
{
	m_changeDirTimer += deltaTime;

	if (m_changeDirTimer.asSeconds() > getChangeDirRate())
	{
		m_changeDirTimer = sf::seconds(0.0);

		auto x = getSlayerLocaion().x - this->getObjectPosition().x;
		auto y = getSlayerLocaion().y - this->getObjectPosition().y;

		auto direction = (sf::Vector2f(0, 0));

		if (!m_isSlayerAlive)
			m_speed = 100;

		int movingRate = getSpeed();

		if (!m_randMove && m_isSlayerAlive)
		{
			if (abs(y) < abs(x))
			{
				if (x < 0)
					direction.x -= movingRate;
				else
					direction.x += movingRate;

				if (abs(y) > 100)
				{
					if (y < 0)
						direction.y -= movingRate;
					if (y > 0)
						direction.y += movingRate;
				}
			}
			else
			{
				if (y < 0)
					direction.y -= movingRate;
				else
					direction.y += movingRate;

				if (abs(x) > 100)
				{
					if (x < 0)
						direction.x -= movingRate;
					if (x > 0)
						direction.x += movingRate;
				}
			}
			setDirection(direction);
			setMovingDirection();
		}
		else
			setRandDirection();
	}
	setSpriteSheet(deltaTime);		//setting the animation
}
//--------------- takeDamage function ---------------
//function for taking damage from the slayer
//also activaes monster injury sound
void Demons::takeDamage(int damage)
{
	m_damageCount += damage;

	if (m_currentHealth == 0)
		return;

	m_currentHealth -= damage;

	if (m_currentHealth > 0 &&
		m_damageCount >= m_hundredCount * 100)
	{
		playDemonActionSound(INJURED);
		m_hundredCount++;
	}
	if (m_currentHealth <= 0)
	{
		m_currentHealth = 0;
		m_isDead = true;
	}
}
//--------------- setDemonActionSound function ---------------
//initialize sounds for each demon (sent from their constructors)
void Demons::setDemonActionSound(sf::Sound sight, sf::Sound attack, sf::Sound injured, sf::Sound death)
{
	m_sounds[ON_SIGHT] = sight;
	m_sounds[ON_SIGHT].setVolume(25);
	m_sounds[ATTACKING] = attack;
	//m_sounds[ATTACKING].setVolume(50);
	m_sounds[DEATH] = death;
    //m_sounds[DEATH].setVolume(40);
	m_sounds[INJURED] = injured;
	m_sounds[INJURED].setVolume(40);
}
//--------------- playDemonActionSound function ---------------
//play demon action sound
void Demons::playDemonActionSound(int action)
{
	m_sounds[action].play();
}
//--------------- countUntillNextHit function ---------------
//function to count between each hit of the demons - each one have a differnet hitting rate
void Demons::countUntillNextHit(sf::Time deltaTime)
{
	m_hittingTimer += deltaTime;

	if (m_hittingTimer.asSeconds() >= getHittingRate())
	{
		m_canHit = true;
		m_hittingTimer = sf::seconds(0.0);
	}
}