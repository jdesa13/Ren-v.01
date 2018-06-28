#include "Bass/pinhole_camera.h"

pinhole::pinhole(){
	Eigen::Vector3d dr((0, 0, -1));
	Eigen::Vector3d P(0,0,0);
	
	mDr = dr; mLoc = P; Theta = 60;
}

pinhole::pinhole( Eigen::Vector3d dir, Eigen::Vector3d loc, int theta)
{
	mLoc = loc; mDr = dir; Theta = theta;
}

pinhole::~pinhole() {}

Eigen::Vector3d pinhole::getDir()
{
	return mDr;
}

void pinhole::setDir(int BigW, int BigH, int width, int height, Eigen::Vector3d p)
{
	
	float AR = BigW / BigH;

	float Pcx = AR * (2 * ((width + .5) / BigW) - 1) *tan((Theta / 2)* M_PI / 180);
	float Pcy = (1 - 2 * ((height + .5) / BigH)) *tan((Theta / 2)* M_PI / 180);


	Eigen::Vector3d Pc(Pcx, Pcy, -1);
	
	mDr = Pc - p;

}
