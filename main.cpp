#include <iostream>
#include <string>
#include "Bass/shape.h"
#include "Bass/circle.h"
#include "Bass/triangle.h"
#include "Bass/screen.h"
#include "Bass/camera.h"
#include "Bass/pinhole_camera.h"
#include "Bass/integrator.h"
#include "Bass/hit.h"
#include "Bass/film.h"
#include "Bass/hdrfilm.h"
#include "Bass/core.h"
#include "Bass/ldrfilm.h"
#include "Bass/lights.h"
#include "Bass/point.h"
#include "Bass/material.h"

int main(int argc, char** argv)
{
	Eigen::Vector3d origin(0,0,0);
	Eigen::Vector3d cen(0, 0, -4);
	Eigen::Vector3d rcol(1, 0, 0);
	Eigen::Vector3d loc(1, 1, 1);
	Eigen::Vector3d dr(0, 0, 0);
	Eigen::Vector3d lpos(-3, 1, 0);
	
	screen one(800, 600);
	hdrfilm six(one.Getwidth(), one.Getheight());
	//ldrfilm eight(one.Getwidth(), one.Getheight(),0);
	hit five(origin);
	sphere two(cen, rcol, -2);
	pinhole three(dr,loc);
	points nine(loc,lpos);
	material ten(.8,.8,.2);


	Eigen::Vector3d A(-1, 1, -2);
	Eigen::Vector3d B(1, 1, -2);
	Eigen::Vector3d C(0, -1, -2);
	triangle four(A,B,C,rcol,60);

	int testfive;
	Eigen::Vector3d dir;

	int size = one.Getwidth() * one.Getheight() * 4;

	float *pixel = new float[size];
	if (pixel == NULL)
	{
		std::cout << "Failed to allocate memory" << std::endl;
	}

	unsigned int index = 0;
	for (int rows = 0; rows < one.Getheight(); rows++) {
		for (int cols = 0; cols < one.Getwidth(); cols++)
		{
			index = rows * one.Getwidth() * 4 + cols * 4;

			three.setDir(cols, rows, 60, origin);
			dir = three.getDir();

			Eigen::Vector3d form = two.Sectfind(origin, dir);
			five.setHit(form);
			testfive = five.strike();
			//std::cout << testfive;

			Eigen::Vector3d eve = ten.diffuse(two.normal(form),nine.getLcol(),nine.getLpos(),form);
			Eigen::Vector3d cain = ten.phong(two.normal(form), nine.getLpos(), form, origin, nine.getLcol(), 30);
			Eigen::Vector3d abel = ten.ambient();

			pixel[index + 0] = (abel(0) + cain(0) + eve(0))*testfive; //Red
			pixel[index + 1] = 0.0; //Green
			pixel[index + 2] = 0.0; //Blue
			pixel[index + 3] = 1.0; // Alpha
	}
		//std::cout << " " << std::endl;
	}
	//core seven(three,five);
	six.save("A.exr", pixel);
	//eight.save("A.png", pixel);
	std::cout << "Here";
}