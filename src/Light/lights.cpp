#include "Bass/lights.h"

lights::lights()
{
	Eigen::Vector3d filler(1, 1, 1); 

	mLcol = filler;
}

lights::lights( Eigen::Vector3d lcol)
{
	mLcol = lcol;
}

lights::~lights(){}
