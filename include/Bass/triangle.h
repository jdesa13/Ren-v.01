#include "Bass/shape.h"

#pragma once
#ifndef _J_TRI
#define _J_TRI

class triangle : public shape {
protected:
	Eigen::Vector3d A;
	Eigen::Vector3d B;
	Eigen::Vector3d C;
	float theta;

public:
	triangle();
	triangle(Eigen::Vector3d p0, Eigen::Vector3d p1, Eigen::Vector3d p2, Eigen::Vector3d col, float t);
	~triangle();

	Eigen::Vector3d Sectfind(Eigen::Vector3d p, Eigen::Vector3d dr);
	Eigen::Vector3d normal();
	void showPoints();
};

#endif //_J_CIR