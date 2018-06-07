#include <string>
#include <iostream>
#include <Eigen/Dense>
#include "Bass/render.h"

#pragma once
#ifndef _J_CAM
#define _J_CAM

class camera {
protected:
	Eigen::Vector3d mLoc;

	camera() {};
	camera(Eigen::Vector3d loc) 
	: mLoc(loc){};
	~camera() {};
};

#endif // _J_CAM