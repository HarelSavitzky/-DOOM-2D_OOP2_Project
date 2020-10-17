#include "Slayer.h"
//---------------Slayer constructor--------------------
Slayer::Slayer(sf::Vector2f location, const sf::Texture& texture) :
	MovingObject(location, texture)
{
	setSpriteSource(sf::Vector2f(0, SLAYER_DOWN));
	setRecSize(sf::Vector2f(44, 57));
	getSprite().setTextureRect(sf::IntRect(0, SLAYER_DOWN * getRecSize().y, getRecSize().x, getRecSize().y));
	getSprite().setScale(1.6, 1.6);
	getSprite().setOrigin(getSprite().getLocalBounds().width * 0.5,
		getSprite().getLocalBounds().height * 0.4);			
	m_movingRate = 450;
	m_weapon = PISTOL;
	m_shootingDirection = DOWN;				//initializing slayer members
	initializeAmmo();
	m_health = 100;
	m_maxHealth = 100;
	m_armor = 0;
	m_maxArmor = 150;
	m_isDead = false;
	m_isShooting = false;
	m_finishShooting = true;

}
//---------------updateShooting function--------------------
//update amount of ammo when shooting
void Slayer::updateShooting(Weapon weapon)
{
	if (m_ammo[weapon] <= 0)
		return;
	if (m_ammo[weapon] > 0)
		m_ammo[weapon] -= 1;
}
//---------------pickAmmo function--------------------
//handle ammo pick up
bool Slayer::pickAmmo(Weapon weapon, int ammo)
{

	if (m_ammo[weapon] == m_maxAmmo[weapon])
		return false;

	if (m_maxAmmo[weapon] - m_ammo[weapon] < ammo)
		m_ammo[weapon] = m_maxAmmo[weapon];
	else
		m_ammo[weapon] += ammo;
	SingleTone::instance().getSound(ARMOR_PICKUP_SOUND).get()->setVolume(20);
	SingleTone::instance().getSound(AMMO_PICKUP_SOUND).get()->play();

	return true;
}
//---------------pickArmor function--------------------
//handle armor pick up
bool Slayer::pickArmor(int armor)
{
	if (m_armor == m_maxArmor)
		return false;

	if (m_maxArmor - m_armor < armor)
		m_armor = m_maxArmor;
	else
		m_armor += armor;
	SingleTone::instance().getSound(ARMOR_PICKUP_SOUND).get()->setVolume(200);
	SingleTone::instance().getSound(ARMOR_PICKUP_SOUND).get()->play();

	return true;
}
//---------------pickArmor function--------------------
//handle health pick up
bool Slayer::pickHealth(int health)
{
	if (m_health == m_maxHealth)
		return false;

	if (m_maxHealth - m_health < health)
		m_health = m_maxHealth;
	else
		m_health += health;
	SingleTone::instance().getSound(ARMOR_PICKUP_SOUND).get()->setVolume(20);
	SingleTone::instance().getSound(ITEMP_PICKUP_SOUND).get()->play();

	return true;
}
//---------------getDashTimer function--------------------
//get the dash timer so can be updated in toolbar
int Slayer::getDashTimer()
{
	auto temp = (int)m_canDashTimer.asSeconds();
	temp = 3 - temp;		
	return temp;
}
//---------------changeDirection function--------------------
//change the direction of the slayer and handle the dashing!------------
void Slayer::changeDirection(sf::Time deltaTime)
{
	static sf::Time dashMoveTimer = sf::seconds(0.0);
	m_canDashTimer += deltaTime;

	if (m_canDashTimer.asSeconds() >= 3)		//handle dash block
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || m_isDashing)
		{
			m_isDashing = true;
			m_movingRate = DASH_SPEED;
			dashMoveTimer += deltaTime;
			if (dashMoveTimer.asSeconds() >= 0.3)
			{
				SingleTone::instance().getSound(SLAYER_DASH_SOUND).get()->setVolume(30);
				SingleTone::instance().getSound(SLAYER_DASH_SOUND).get()->play();
				m_isDashing = false;
				m_canDashTimer = sf::seconds(0.0);
				dashMoveTimer = sf::seconds(0.0);
			}
		}
	}
	else if (!m_isDashing)
		m_movingRate = REGULAR_SLAYER_SPEED;

	sf::Vector2f direction = (sf::Vector2f(0, 0));		//set new direction
	if (!m_isDead)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			direction.y -= m_movingRate;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			direction.y += m_movingRate;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			direction.x += m_movingRate;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			direction.x -= m_movingRate;
	}
	setDirection(direction);

	setMovingDirection();

	if (!m_isShooting)
		setSpriteSource(sf::Vector2f(getMovingDirection() * getRecSize().x, getSpriteSource().y));	
	else if (m_isShooting)
		setSpriteSource(sf::Vector2f(m_shootingDirection * 55, 229));//put const

	setSpriteSheet(deltaTime);
}
//---------------setSpriteSheet function--------------------
//handle slayer sprite sheet, also pretty generic, another player  
//would probably work fine with this func
void Slayer::setSpriteSheet(sf::Time deltaTime)		
{																	
	static sf::Time temp = sf::seconds(0.0);
	static sf::Vector2f deathSpriteSource = sf::Vector2f(0, 402);

	temp += deltaTime;
	if (!m_isDead)
	{
		if (!m_isShooting)		//if he is moving animation
		{
			if (temp.asSeconds() > 0.1)
			{
				setSpriteSource(sf::Vector2f(getSpriteSource().x, getSpriteSource().y + 1));
				temp = sf::seconds(0.0);
			}
			if (getSpriteSource().y >= 4)
			{
				setSpriteSource(sf::Vector2f(getSpriteSource().x, 0));
			}
			if (getDirection() != sf::Vector2f(0, 0))						//as long as i move, update my sprite
				getSprite().setTextureRect(sf::IntRect(getSpriteSource().x, getSpriteSource().y * getRecSize().y, getRecSize().x, getRecSize().y));
		}
		else
		{
			m_finishShooting = false;
			if (temp.asSeconds() > 0.05)		//if the slayer is shooting animation
			{
				setSpriteSource(sf::Vector2f(getSpriteSource().x, getSpriteSource().y + 57));
				temp = sf::seconds(0.0);
			}
			if (getSpriteSource().y >= 290)
			{
				setSpriteSource(sf::Vector2f(getSpriteSource().x, 229));
			}

			getSprite().setTextureRect(sf::IntRect(getSpriteSource().x, getSpriteSource().y, 55, 57));
		}
		if (!m_isShooting && getDirection() == sf::Vector2f(0, 0) && m_finishShooting == false)
		{
			m_finishShooting = true;													//keep player in right form without
			setSpriteSource(sf::Vector2f(m_shootingDirection * getRecSize().x, 0));			//consider movement or shooting (after shooting)
			getSprite().setTextureRect(sf::IntRect(m_shootingDirection * getRecSize().x, 0, getRecSize().x, getRecSize().y));
		}
	}
	else if (!m_finishedDying)
	{												//if the slayer is dead animation
		if (temp.asSeconds() > 0.15)
		{
			deathSpriteSource = sf::Vector2f(deathSpriteSource.x + 60, deathSpriteSource.y);
			temp = sf::seconds(0.0);
		}
		if (deathSpriteSource.x >= 490)
		{
			m_finishedDying = true;
			deathSpriteSource = sf::Vector2f(480, 402);
		}
		getSprite().setTextureRect(sf::IntRect(deathSpriteSource.x, deathSpriteSource.y, 60, 60)); 
	}
	getSprite().setScale(1.7, 1.7);
}
//---------------takeDamage function--------------------
//slayer takes damage  function - absorb to shield or to himself
void Slayer::takeDamage(int damage)
{
	if (m_health == 0)
		return;

	if (m_health + m_armor > damage && m_canMakeInjuredSound)		//make death && injured sounds if needed
	{
		SingleTone::instance().getSound(SLAYER_INJURED_SOUND).get()->play();
		m_canMakeInjuredSound = false;
	}

	else if (m_health + m_armor < damage)
	{
		if (damage == 12)
			SingleTone::instance().getSound(HUMILIATION_SOUND).get()->play();
		else
			SingleTone::instance().getSound(SLAYER_DEATH_SOUND).get()->play();
	}

	if (m_armor == 0)
		m_health -= damage;

	else if (m_armor >= damage)
		m_armor -= damage;
	else if (m_armor > 0 && m_armor < damage)
	{
		int temp = abs(m_armor - damage);
		m_armor = 0;
		m_health -= temp;
	}

	if (m_health <= 0)
	{
		m_health = 0;
		m_isDead = true;
	}
}
//---------------countUntillNextHit function--------------------
//count untill the next hit that that the slayer can take, from fire or demon
void Slayer::countUntillNextHit(sf::Time deltaTime)
{
	static sf::Time temp = sf::seconds(0.0);
	temp += deltaTime;

	if (m_canMakeInjuredSound == false)
		m_injuredSoundTimer += deltaTime;

	if (m_injuredSoundTimer.asSeconds() > 1.5)
	{
		m_injuredSoundTimer = sf::seconds(0.0);
		m_canMakeInjuredSound = true;
	}
	if (temp.asSeconds() >= 1)		//set hit rate
	{
		m_canGetBurn = true;
		temp = sf::seconds(0.0);
	}
}
//---------------initializeAmmo function--------------------
//initialize the ammo stats, except of what the shooting holds, this has to be here
void Slayer::initializeAmmo()	
{
	m_ammo[PISTOL] = 60;
	m_ammo[SHOTGUN] = 30;						
	m_ammo[CHAIN_GUN] = 300;
	m_ammo[PLASMA_RIFLE] = 80;
	m_ammo[BFG] = 2;

	m_maxAmmo[PISTOL] = 60;
	m_maxAmmo[SHOTGUN] = 30;
	m_maxAmmo[CHAIN_GUN] = 300;
	m_maxAmmo[PLASMA_RIFLE] = 80;
	m_maxAmmo[BFG] = 2;
}