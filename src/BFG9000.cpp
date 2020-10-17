#include "BFG9000.h"

BFG9000::BFG9000(sf::Vector2f location, const sf::Texture& texture,
	sf::Vector2f target): BigBoomWeapons(location, texture, target)
{
	setBoomSprite(SingleTone::instance().texture(BFG_EXP_TEXTURE));
	getSprite().setScale(0.17,0.17);
	setCurrentVelocity(getAimDirNorm() * 22.f);	
	setShootingRange(1200.f);
	setWeaponDamage(12);
	setExplotionSize(15);
	setScalar(0.1);
	setBoomScalar(0.1);
	setHitSounds(*SingleTone::instance().getSound(BFG_HIT_SOUND).get());
}