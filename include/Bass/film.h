#include <string>
#include <iostream>
#include "Bass/camera.h"

#pragma once
#ifndef _J_FILM
#define _J_FILM

class film : public camera {
public:

	film() { mWidth = 800; mHeight = 600; };
	film(int width, int height) { mWidth = width; mHeight = height; };
	~film() {};

	virtual void save(const std::string &filename, float *ptr) = 0;

};

#endif // _J_FILM