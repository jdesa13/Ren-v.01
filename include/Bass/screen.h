#include <string>
#include <iostream>
#include "Bass/render.h"
#include "Bass/camera.h"
#include "Bass/pinhole_camera.h"
#include "Bass/shape.h"
#include "Bass/circle.h"
#include <iostream>
#include <string>
#include <vector>
#include <Eigen/Dense>

#pragma once
#ifndef _J_W
#define _J_W

class screen : public render {
protected:
	std::string mFormat;
	std::vector <shape*> mShapes;
	int width;
	int height;
public:

	screen() { mFormat = "default"; };
	screen(std::string here) { mFormat = here; }
	~screen() {};

	pinhole camToWorld(Eigen::Vector3d dir, Eigen::Vector3d loc, int theta);
	void shapesToWorld(std::string here, Eigen::Vector3d cen, Eigen::Vector3d col, float r);
	std::vector <shape*> getShapes();
	void setFileW(int w);
	void setFileH(int h);
	int getFH();
	int getFW();

	
};

#endif