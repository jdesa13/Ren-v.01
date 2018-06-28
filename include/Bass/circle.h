#include "Bass/shape.h"

#pragma once
#ifndef _J_SPH
#define _J_SPH

class sphere : public shape {
protected:
	Eigen::Vector3d mCenter;
	float mRadius;
	

public:
	
	sphere();
	sphere(Eigen::Vector3d cen, Eigen::Vector3d col, float r);
	~sphere();

	Eigen::Vector3d Sectfind(Eigen::Vector3d p, Eigen::Vector3d dr);
	Eigen::Vector3d normal(Eigen::Vector3d sect);
    void getCenter();
	float intersect(Eigen::Vector3d origin, Eigen::Vector3d dr);
	int hit(float d);
};

#endif //_J_CIR