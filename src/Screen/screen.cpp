#include"Bass/screen.h"

screen::screen()
{}

screen::screen(int width, int height)
{
	mWidth = width; mHeight = height;
}
screen::~screen() {}

void screen::setsize(int a, int b)
{
	mWidth = a; mHeight = b;
}
int screen::Getwidth() {

	return mWidth;

}
int screen::Getheight() {

	return mHeight;

}