#include "Bass/point.h"

points::points()
{
	Eigen::Vector3d filler(1,1,1);

	mLpos = filler; mLcol = filler;
}

points::points(Eigen::Vector3d lcol, Eigen::Vector3d lpos)
{
	mLpos = lpos; mLcol = lcol;
}

points::~points(){}

Eigen::Vector3d points::getLcol()
{
	return mLcol;
}

Eigen::Vector3d points::getLpos()
{
	return mLpos;
}
