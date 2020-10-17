#pragma once
//--------------------include Section --------------------
#include "Walls.h"
//--------------------HorizontalWall Class definition --------------------
class HorizontalWall : public Walls
{
public:
	using Walls::Walls;
	HorizontalWall();
	virtual ~HorizontalWall() = default;

private:
};