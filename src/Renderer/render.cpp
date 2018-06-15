#include"Bass/render.h"

render::render()
{
	mWidth = 800; mHeight = 600;
}

render::render(int width, int height) {

	mWidth = width; mHeight = height;
}

render::~render() {}

void render::setsize(int a, int b) {

	mWidth = a; mHeight = b;
}