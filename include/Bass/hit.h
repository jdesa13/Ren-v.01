#include"Bass/integrator.h"

#pragma once
#ifndef _J_HIT
#define _J_HIT

class hit :public integrator {
protected:
	Eigen::Vector3d mHit;
public:
	
	hit();
	hit(Eigen::Vector3d dr);
	~hit();

	int strike();
	void setHit(Eigen::Vector3d dr);
};

#endif // _J_HIT