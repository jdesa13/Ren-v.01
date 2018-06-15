#include "Bass/pinhole_camera.h"

pinhole::pinhole(){
	Eigen::Vector3d dr((0, 0, -1));
	Eigen::Vector3d P(0,0,0);
	
	mDr = dr; mLoc = P;
}

pinhole::pinhole( Eigen::Vector3d dir, Eigen::Vector3d loc)
{
	mLoc = loc; mDr = dir;
}

pinhole::~pinhole() {}

Eigen::Vector3d pinhole::getDir()
{
	return mDr;
}

void pinhole::setDir(int width, int height, int theta, Eigen::Vector3d p)
{
	
	float Pcx = AR * (2 * ((width + .5) / mWidth) - 1) *tan((theta / 2)* M_PI / 180);
	float Pcy = (1 - 2 * ((height + .5) / mHeight)) *tan((theta / 2)* M_PI / 180);


	Eigen::Vector3d Pc(Pcx, Pcy, -1);
	
	mDr = Pc - p;

}
