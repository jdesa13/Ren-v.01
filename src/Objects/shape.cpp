#include "Bass/shape.h"

shape::shape()
{
	Eigen::Vector3d filler(1,1,1);

	mColor = filler;
}

shape::~shape(){}
