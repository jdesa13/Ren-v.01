#include "Bass/hit.h"

hit::hit()
{
	Eigen::Vector3d miss(-999,-999,-999);
	mHit = miss;
}

hit::hit(Eigen::Vector3d dr)
{
	mHit = dr;
}

hit::~hit(){}

int hit::strike()
{
	int hit = 1;
	int miss = 0;

	if (mHit(0) == -999 && mHit(1) == -999 && mHit(2) == -999)
	{
		return miss;
	}

	return hit;
}

void hit::setHit(Eigen::Vector3d dr)
{
	mHit = dr;
}
