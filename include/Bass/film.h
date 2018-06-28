#include <string>
#include <iostream>
#include "Bass/camera.h"

#pragma once
#ifndef _J_FILM
#define _J_FILM

class film : public camera {
protected:

	unsigned int mWidth, mHeight;

public:

	film() {};
	film(int width, int height) { mWidth = width; mHeight = height; };
	~film() {};

	virtual void save(const std::string &filename, float *ptr) = 0;

};

#endif // _J_FILM