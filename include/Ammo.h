#pragma once
//--------------------include Section --------------------
#include "StaticObject.h"

//--------------------Ammo Class definition --------------------
class Ammo : public StaticObject
{
public:
	using StaticObject::StaticObject;
	Ammo();
	virtual ~Ammo() = default;
	void SetSizeOfMag(int magSize) { m_sizeOfMag = magSize; };
	int getSizeOfMag() { return m_sizeOfMag; };

private:
	int m_sizeOfMag;
};