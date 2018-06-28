#include "Bass/shape.h"

shape::shape()
{
	Eigen::Vector3d filler(1,0,0);

	mColor = filler;
}

shape::~shape(){}
