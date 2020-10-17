#pragma once
//--------------------include Section --------------------
#include "Weapons.h"
//--------------------BigBoomWeapons Class definition --------------------
class BigBoomWeapons : public Weapons
{
public:
	using Weapons::Weapons;
	BigBoomWeapons(sf::Vector2f location, const sf::Texture& texture,
		sf::Vector2f target);
	virtual ~BigBoomWeapons() = default;


	void boomHandle(sf::Time deltaTime);
	void setHitSounds(sf::Sound hit);
	void playHitSound() { m_hitSound.play(); };
	void setToExplode() { m_toExplode = true; };			
	void setEndExplotion() { m_endExplosion = true; };
	void setScalar(float scalar) { m_scalar = scalar; };
	void setBoomScalar(float scalar) { m_boomScalar = scalar; };
	void setExplotionSize(int explotionSize) { m_explosionSize = explotionSize; };			
	void setBoomSprite(const sf::Texture& texture) { m_boomSprite.setTexture(texture); };

	//get functions----------
	int getToExplotionSize() const { return m_explosionSize; };

	float getScalar() const { return m_scalar; };
	float getBoomScalar() const { return m_boomScalar; };

	bool getToExplode()const { return m_toExplode; };
	bool getEndExplotion()const { return m_endExplosion; };

	sf::Sprite& getBoomSprite() { return m_boomSprite; };

	//virtual functions----------
	virtual void draw(sf::RenderWindow& window)override;
	virtual void setSpriteSheet(sf::Time deltaTime) override {};
	virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;

private:
	int m_explosionSize;
	int m_explosionScale = 1;
	int m_explosionCounter = 0;

	float m_scalar;
	float m_boomScalar;

	bool m_endExplosion;
	bool m_toExplode;

	sf::Sound m_hitSound;
	sf::Sprite m_boomSprite;
	sf::Time m_explotionTimer = sf::seconds(0.0);

};
