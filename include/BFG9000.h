#pragma once
//--------------------include Section --------------------
#include  "BigBoomWeapons.h"

//--------------------BFG9000 Class definition --------------------
class BFG9000 : public BigBoomWeapons
{
public:
	using BigBoomWeapons::BigBoomWeapons;
	BFG9000(sf::Vector2f location, const sf::Texture& texture,
		sf::Vector2f target);
	virtual ~BFG9000() = default;
private:
};
