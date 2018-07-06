#include "Bass/screen.h"

pinhole screen::camToWorld(Eigen::Vector3d dir, Eigen::Vector3d loc, int theta)
{
	enum cam {PIN};
	cam x;

	if (mFormat == "pinhole") {
		x = PIN;
	}

	switch (x) {

	case PIN:
	{pinhole one(dir, loc, theta);
	return one;
	break;
	}
	default:
	{std::cout << "ERROR in cam2W in screen" << std::endl;
	break; }

	}


}

void screen::shapesToWorld(std::string here, Eigen::Vector3d cen, Eigen::Vector3d col, float r)
{
	shape* one;
	enum cam { SPH, TRI};
	cam x;

	if (here == "sphere") {
		x = SPH;
	}

	switch (x) {

	case SPH:
	{one = new sphere(cen, col, r);
	break;
	}
	default:
	{std::cout << "ERROR in cam2W in screen" << std::endl;
	break; }

	}

	mShapes.push_back(one);
	std::cout << mShapes.size() << std::endl;
	std::cout <<":3" <<std::endl;
}

std::vector<shape*> screen::getShapes()
{
	return mShapes;
}

void screen::setFileW(int w)
{
	width = w;
}

void screen::setFileH(int h)
{
	height = h;
}

int screen::getFH()
{
	return height;
}

int screen::getFW()
{
	return width;
}
