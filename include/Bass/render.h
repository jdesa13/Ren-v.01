#include <string>
#include <iostream>

#pragma once
#ifndef _J_REN
#define _J_REN

class render {
protected:
	unsigned int mWidth, mHeight;

	render() {};
	render(int width, int height)
	: mWidth(width), mHeight(height) {};
	~render() {};

public:

	void setsize(int a, int b);
};

#endif