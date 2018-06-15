#include <string>
#include <iostream>
#include <Eigen/Dense>
#include "Bass/screen.h"

#pragma once
#ifndef _J_LIT
#define _J_LIT

class lights : public screen{
protected:
	Eigen::Vector3d mLcol;

	lights();
	lights(Eigen::Vector3d lcol);
	~lights();

};

#endif