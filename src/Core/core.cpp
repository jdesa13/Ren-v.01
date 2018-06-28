#include "Bass/core.h"

core::core()
{
	mPixel = 0;
}

core::core(float * pixel)
{
	mPixel = pixel;
}

core::~core(){}

void core::Corecol(int index, Eigen::Vector3d fill)
{
	mPixel[index + 0] = fill(0); //Red
	mPixel[index + 1] = fill(1); //Green
	mPixel[index + 2] = fill(2); //Blue
	mPixel[index + 3] = 1.0; // Alpha
}

float * core::getCcore()
{
	return mPixel;
}
