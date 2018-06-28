#include <iostream>
#include <fstream>
#include <sstream>
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

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
		std::cerr << "Example: " << argv[0] << " ../data/test.json" << std::endl;// Tell the user how to run the program
		return 1;
	}

	std::cout << "Opening the following file: " << argv[1] << std::endl;
	std::ifstream mFile(argv[1]);
	try {
		if (!mFile) throw "File undefined condition!";
	}
	catch (const char* msg)
	{
		std::cerr << "ERROR: READING FILE : " << argv[1] << ". Could not find it?" << std::endl;
		std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
	}




	rapidjson::Document document;
	rapidjson::IStreamWrapper isw(mFile);


	if (document.ParseStream(isw).HasParseError())
		std::cerr << "FAIL - JSON file Parse ERROR encountered" << std::endl;


	//Just for unit testing - I would move this to class/strut/function, use asserts, something not this.
	if (!document.HasMember("scene"))
		std::cerr << "FAIL - Not a valid scene file..." << std::endl;
	if (document["scene"]["version"].IsNull() || !document["scene"]["version"].IsString())
		std::cerr << "FAIL - Missing Version Numer!" << std::endl;
	if (document["scene"]["integrator"]["type"].IsNull() || !document["scene"]["integrator"]["type"].IsString())
		std::cerr << "FAIL - Missing Integrator in the scene file." << std::endl;



	std::cout << "Sensor Type: " << document["scene"]["sensor"]["type"].GetString() << ". Film file: "
		<< document["scene"]["sensor"]["film"]["outputname"].GetString() << "."
		<< document["scene"]["sensor"]["film"]["fileFormat"].GetString() << " of size: "
		<< document["scene"]["sensor"]["film"]["width"].GetInt() << "x" << document["scene"]["sensor"]["film"]["height"].GetInt() << std::endl;
	
	Eigen::Vector3d loc;
	rapidjson::Value& pos = document["scene"]["sensor"]["transform"]["position"];
	assert(pos.IsArray());
	for (rapidjson::SizeType i = 0; i < pos.Size(); i++)
	{
		loc(i) = pos[i].GetInt();
	}
	std::cout << loc << std::endl;

	Eigen::Vector3d dir;
	rapidjson::Value& view = document["scene"]["sensor"]["transform"]["viewat"];
	assert(view.IsArray());
	for (rapidjson::SizeType i = 0; i < view.Size(); i++)
	{
		dir(i) = view[i].GetInt();
	}
	std::cout << dir << std::endl;

	screen dot(document["scene"]["sensor"]["type"].GetString());
	pinhole one = dot.camToWorld(dir, loc, document["scene"]["sensor"]["transform"]["fov"].GetInt());

	//std::cout<< "  There are: "<<document["scene"]["shape"].Size() << " Shapes in the JSON scene file." << std::endl;
	rapidjson::Value& shapes = document["scene"]["shapes"];
	rapidjson::Value& ldrnm = document["scene"]["sensor"]["film"]["outputname"];

	Eigen::Vector3d cen;
	Eigen::Vector3d col(1,1,1);
	Eigen::Vector3d origin(0, 0, 0);
	Eigen::Vector3d dr(0, 0, 1);
	std::cout << "You have found " << shapes.Size() << " Shapes in the scene file." << std::endl;
	for (rapidjson::SizeType i = 0; i < shapes.Size(); i++) // rapidjson uses SizeType instead of size_t.
	{

		rapidjson::Value& ter = shapes[i]["position"];
		assert(ter.IsArray());
		for (rapidjson::SizeType i = 0; i < ter.Size(); i++)
		{
			cen(i) = ter[i].GetFloat();
		}
		//std::cout << cen << std::endl;

		dot.shapesToWorld(shapes[i]["type"].GetString(), cen, col, shapes[i]["radius"].GetInt());
	}

	std::vector<shape*> holder = dot.getShapes();
	
	rapidjson::Value& width = document["scene"]["sensor"]["film"]["width"];
	rapidjson::Value& height = document["scene"]["sensor"]["film"]["height"];
	
	mFile.close();
	
	ldrfilm six(width.GetInt(), height.GetInt(),0);
	int size = width.GetInt() * height.GetInt() * 4;
	float *pixel = new float[size];
	if (pixel == NULL)
	{
		std::cout << "Failed to allocate memory" << std::endl;
	}

	core eleven(pixel);

	float t1 = INFINITY;
	float t2 = INFINITY;
	int index;
	for (int i = 0; height.GetInt(); i++) {

		for (int j = 0; width.GetInt(); j++) {

			index = i * width.GetInt() * 4 + j * 4;
			for (int k = 1; k < holder.size(); k++) {

				t1 = holder[k - 1]->intersect(origin, dr);
				t2 = holder[k]->intersect(origin, dr);
				if (t1 != INFINITY && t2 != INFINITY) {
					if (t1 == -999.0  && t2 < t1) {
						eleven.Corecol(index, col);
					}
					else if (t2 == -999.0 && t1 < t2) {
						eleven.Corecol(index, col);
					}
				}
			}
		}
	}

	 six.save(ldrnm.GetString(), eleven.getCcore());
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