#include <string>
#include <iostream>
#include "Bass/render.h"

#pragma once
#ifndef _J_W
#define _J_W

class screen : public render {

public:

	screen();
	screen(int width, int height);
	~screen();

	void setsize(int a, int b);
	int Getwidth();
	int Getheight();

};

#endif