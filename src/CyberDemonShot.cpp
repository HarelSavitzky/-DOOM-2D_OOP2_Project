#include "CyberDemonShot.h"

CyberDemonShot::CyberDemonShot(sf::Vector2f location, const sf::Texture& texture,
	sf::Vector2f target) : BigBoomWeapons(location, texture,target)
{
	setBoomSprite(SingleTone::instance().texture(CYBERDEMON_BLAST_TEXTURE));
	getSprite().setTexture(texture);
	getSprite().setPosition(location);
	getSprite().setScale(0.17, 0.17);
	setCurrentVelocity(getAimDirNorm() * 18.f);	
	setShootingRange(1200.f);
	setWeaponDamage(3);
	setExplotionSize(18);
	setScalar(0.05);
	setBoomScalar(0.07);
	setHitSounds(*SingleTone::instance().getSound(CYBERDEMON_HIT_SOUND).get());
}