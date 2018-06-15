#include "Bass/core.h"

core::core()
{
	Eigen::Vector3d loc(1, 1, 1); Eigen::Vector3d dr(0, 0, 1);
	pinhole three(dr, loc); mPin = three;
	Eigen::Vector3d origin(0, 0, 0);
	hit five(origin); mFind = five;
}

core::core(pinhole pin, hit find)
{
	mPin = pin; mFind = find;
}

core::~core(){}

float* core::cirCol(sphere cir, Eigen::Vector3d origin)
{
	int size = mWidth * mHeight * 4;
	unsigned int index = 0;
	Eigen::Vector3d dir;
	Eigen::Vector3d form;
	int testfive;

	float *pixel = new float[size];
	if (pixel == NULL)
	{
		std::cout << "Failed to allocate memory" << std::endl;
	}

	for (int rows = 0; rows < mHeight; rows++) {
		for (int cols = 0; cols < mWidth; cols++)
		{
			index = rows * mHeight* 4 + cols * 4;

			mPin.setDir(rows, cols, 60, origin);
			dir = mPin.getDir();

			
			form = cir.Sectfind(origin, dir);
			//std::cout << form << std::endl;

			mFind.setHit(form);

			testfive = mFind.strike();

			pixel[index + 0] = 1.0; //Red
			pixel[index + 1] = 0.0; //Green
			pixel[index + 2] = 0.0; //Blue
			pixel[index + 3] = 1.0; // Alpha
		}
		//std::cout << " " << std::endl;
	}
	
	return pixel;
}
