#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
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
#include "Bass/render.h"
#include "rapidjson/document.h"
#include "rapidjson/reader.h"
#include "rapidjson/istreamwrapper.h"
#include "Bass/jsonparse.h"

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
		std::cerr << "Example: " << argv[0] << " ../data/test.json" << std::endl;// Tell the user how to run the program
		return 1;
	}

	parser here(argv[1]);

	pinhole one = here.getpin();
	std::vector <shape*> holder = here.getShapes();
	int width = here.getfilmw();
	int height = here.getfilmh();
	
	Eigen::Vector3d col(1, 1, 1);
	Eigen::Vector3d origin(0, 0, 0);
	Eigen::Vector3d r(1, 0, 0);
	Eigen::Vector3d g(0, 1, 0);
	ldrfilm six(width, height,0);
	int size = width * height * 4;
	float *pixel = new float[size];
	if (pixel == NULL)
	{
		std::cout << "Failed to allocate memory" << std::endl;
	}

	core eleven(pixel);

	float hit_point = INFINITY;
	double intersect_point = INFINITY;
	int intersect_object = -1;
	bool hit = false;

	int index;
	for (int i = 0; i<height; i++) {

		for (int j = 0; j<width; j++) {

			hit_point = INFINITY;
			intersect_point = INFINITY;
			intersect_object = -1;
			hit = false; 

			one.setDir(width, height,j,i,origin);
			for (int k = 0; k < holder.size(); k++) {

				intersect_point = holder[k]->intersect(origin, one.getDir());

				//std::cout << intersect_point;
				//std::cout << " ";

				if (intersect_point < hit_point) {
					hit_point = intersect_point;
					intersect_object = k;
					hit = true;
				}

			}//end shape loop
			//std::cout << " " << "  ";
			index = i * width * 4 + j * 4;

			if (hit) {
				if (intersect_object == 0) {
					eleven.Corecol(index, r);
				}
				else
				{
					eleven.Corecol(index, g);
				}
			}
			else {

				eleven.Corecol(index,col);

			}

			// 

		}
		//std::cout << "" << std::endl;
	}

	 six.save(here.filename(), eleven.getCcore());
	 std::cout << "add example here!";
	return 0;
}

//int main(int argc, char** argv)
//{
//	Eigen::Vector3d origin(0,0,0);
//	Eigen::Vector3d cen(0, 0, -4);
//	Eigen::Vector3d rcol(1, 0, 0);
//	Eigen::Vector3d loc(1, 1, 1);
//	Eigen::Vector3d lpos(-3, 1, 0);
//	Eigen::Vector3d A(-1, 1, -2);
//	Eigen::Vector3d B(1, 1, -2);
//	Eigen::Vector3d C(0, -1, -2);
//	
//	//render one(800, 600);
//	sphere two(cen, rcol, -2);
//	pinhole three(origin, loc);
//	triangle four(A, B, C, rcol, 60);
//	hit five(origin);
//	hdrfilm six(800, 600);
//	points nine(loc,lpos);
//	material ten(.8,.8,.2);
//
//
//	int size = 800 * 600 * 4;
//	float *pixel = new float[size];
//	if (pixel == NULL)
//	{
//		std::cout << "Failed to allocate memory" << std::endl;
//	}
//	core eleven(pixel);
//
//	Eigen::Vector3d dif;
//	Eigen::Vector3d pho;
//	Eigen::Vector3d amb;
//	Eigen::Vector3d all;
//	Eigen::Vector3d form;
//	unsigned int index = 0;
//	for (int rows = 0; rows < 600; rows++) {
//		for (int cols = 0; cols < 800; cols++)
//		{
//			index = rows * 800 * 4 + cols * 4;
//
//			three.setDir(800,600,cols, rows, 60, origin);
//
//			form = two.Sectfind(origin, three.getDir());
//			five.setHit(form);	
//
//			dif = ten.diffuse(two.normal(form),nine.getLcol(),nine.getLpos(),form);
//			pho = ten.phong(two.normal(form), nine.getLpos(), form, origin, nine.getLcol(), 30);
//			amb = ten.ambient();
//			all = (dif + pho + amb) * five.strike();
//			//std::cout << all << std::endl;
//
//			eleven.Corecol(index,all);
//	}
//		//std::cout << " " << std::endl;
//	}
//	six.save("A.exr", eleven.getCcore());
//	std::cout << "Here";
//}