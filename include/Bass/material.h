#include <string>
#include <iostream>
#include "Bass/shape.h"

#pragma once
#ifndef _J_MAT
#define _J_MAT

class material : public shape {
protected:
	float Kd;
	float Ks;
	float Ka;
	Eigen::Vector3d slcol;


public:

	material();
	material(float d, float s, float a);
	~material();

	void SLcol(Eigen::Vector3d lcol);

	Eigen::Vector3d diffuse(Eigen::Vector3d n, Eigen::Vector3d lcol,Eigen::Vector3d lpos, Eigen::Vector3d sect);
	Eigen::Vector3d phong(Eigen::Vector3d n, Eigen::Vector3d lpos, Eigen::Vector3d sect, Eigen::Vector3d p, Eigen::Vector3d lcol, float shine);
	Eigen::Vector3d ambient();
};

#endif