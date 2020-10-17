#include "MancubusShot.h"

MancubusShot::MancubusShot(sf::Vector2f location, const sf::Texture& texture,
	sf::Vector2f target) : BigBoomWeapons(location, texture,target)
{
	setBoomSprite(SingleTone::instance().texture(MANCUBUS_BLAST_TEXTURE));
	getSprite().setScale(0.1, 0.1);
	setSpriteSource(sf::Vector2f(0, 0));
	setCurrentVelocity(getAimDirNorm() * 14.f);		
	setShootingRange(1200.f);
	setWeaponDamage(2);						//defining the shot of the mancubus demon
	setExplotionSize(16);
	setScalar(0.03);
	setBoomScalar(0.7);
	setSpriteSource(sf::Vector2f(0, 0));
	getBoomSprite().setOrigin((getBoomSprite().getTexture()->getSize().x * 0.5),
		getBoomSprite().getTexture()->getSize().y * 0.5);
	getBoomSprite().setTextureRect(sf::IntRect(getSpriteSource().x * 240, getSpriteSource().y * 240, 240, 240));
	setHitSounds(*SingleTone::instance().getSound(MANCUBUS_HIT_SOUND).get());
}
//--------------- setSpriteSheet function ---------------
//needs a differnet function to handle his sprite sheet
//comparing to the other big boom shootings
void MancubusShot::setSpriteSheet(sf::Time deltaTime)			
{																	
	m_spriteTimer += deltaTime;
	getBoomSprite().setOrigin(getBoomSprite().getLocalBounds().width * 0.5,
		getBoomSprite().getLocalBounds().height * 0.5);
	if (m_spriteTimer.asSeconds() > 0.1)
	{
		if (getSpriteSource().x == 8 && getSpriteSource().y == 4)
			setSpriteSource(sf::Vector2f(1, 5));
		
		if (getSpriteSource().x < 8)
			setSpriteSource(sf::Vector2f(getSpriteSource().x + 1, getSpriteSource().y));
		else
			setSpriteSource(sf::Vector2f(0, getSpriteSource().y + 1));

		m_spriteTimer = sf::seconds(0.0);
	}
	getBoomSprite().setTextureRect(sf::IntRect(getSpriteSource().x * 240, getSpriteSource().y * 240, 240, 240));
	getSprite().setColor(sf::Color::Transparent);
}
//--------------- move function ---------------
//same for the moving function, he needs his own
void MancubusShot::move(sf::Vector2f direction, sf::Time deltaTime)
{
	if (getToExplode())
	{
		setSpriteSheet(deltaTime);
		boomHandle(deltaTime);
	}
	else
	{
		if (!getDeleteStatus())
		{
			getSprite().move(getCurrentVelocity());

			getBoomSprite().setOrigin((getBoomSprite().getTexture()->getSize().x * 0.5),
				getBoomSprite().getTexture()->getSize().y * 0.5);

			getSprite().setOrigin((getSprite().getTexture()->getSize().x * 0.5),
				(getSprite().getTexture()->getSize().y * 0.5));

			getBoomSprite().setPosition(getSprite().getPosition().x, getSprite().getPosition().y);
		}
	}
	if (distance(getStartingPoint(), getObjectPosition()) >= getShootingRange() ||
		distance(getBoomSprite().getPosition(), getTarget()) <= 20)
	{
		setCurrentVelocity(sf::Vector2f(0, 0));
		setToExplode();
	}
}