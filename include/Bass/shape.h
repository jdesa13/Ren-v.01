#include <string>
#include <iostream>
#include <Eigen/Dense>
//#include"Bass/screen.h"

#pragma once
#ifndef _J_SHA
#define _J_SHA

class shape{ //:public screen {
protected:

	Eigen::Vector3d mColor;

public:
	shape();
	~shape();

	virtual void getCenter() {};
	virtual float intersect(Eigen::Vector3d origin, Eigen::Vector3d dr) = 0;
};

#endif // _J_CAM