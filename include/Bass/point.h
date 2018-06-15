#include <string>
#include <iostream>
#include <Eigen/Dense>
#include "Bass/lights.h"

#pragma once
#ifndef _J_PTS
#define _J_PTS

class points : public lights {
protected:
	Eigen::Vector3d mLpos;

public:
	points();
	points(Eigen::Vector3d lcol, Eigen::Vector3d lpos);
	~points();

	Eigen::Vector3d getLcol();
	Eigen::Vector3d getLpos();

};

#endif