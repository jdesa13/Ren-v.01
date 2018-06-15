#include <string>
#include <iostream>

#pragma once
#ifndef _J_REN
#define _J_REN

class render {
protected:
	unsigned int mWidth, mHeight;

public:

	render();
	render(int width, int height);
	~render();

	void setsize(int a, int b);
};

#endif