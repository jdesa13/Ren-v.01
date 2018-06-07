#include "Bass/camera.h"

#ifndef _J_PINCAM
#define _J_PINCAM
class pinhole : public camera {
protected:
	Eigen::Vector3d mDr;

public:

	pinhole();
	pinhole(Eigen::Vector3d P, Eigen::Vector3d dir);
	~pinhole();

	Eigen::Vector3d getDir();
	void setDir(int width, int height, int Xsize, int Ysize, int theta, Eigen::Vector3d p);

};
#endif