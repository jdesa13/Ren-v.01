#include "Bass/camera.h"
#include"Bass/film.h"

#ifndef _J_PINCAM
#define _J_PINCAM
class pinhole : public camera {
protected:
	Eigen::Vector3d mDr;
	int Theta;

public:

	pinhole();
	pinhole(Eigen::Vector3d dir, Eigen::Vector3d loc,int theta);
	~pinhole();

	Eigen::Vector3d getDir();
	void setDir(int BigW, int BigH, int width, int height, Eigen::Vector3d p);

};
#endif