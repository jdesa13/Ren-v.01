#include "rapidjson/document.h"
#include "rapidjson/reader.h"
#include "rapidjson/istreamwrapper.h"
#include "Bass/screen.h"
#include "Bass/camera.h"
#include "Bass/pinhole_camera.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <Eigen/Dense>

#pragma once
#ifndef _J_jsonp
#define _J_jsonp

class parser{
protected:
	char* mRead;
public:

	parser() { mRead = "default"; };
	parser(char* file) { mRead = file; }
	~parser() {};

	pinhole getpin();
	std::vector <shape*> getShapes();
	rapidjson::Document check();
	int getfilmw();
	int getfilmh();
	std::string filename();



};

#endif
