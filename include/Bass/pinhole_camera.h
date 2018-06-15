#include "Bass/camera.h"

#ifndef _J_PINCAM
#define _J_PINCAM
class pinhole : public camera {
protected:
	Eigen::Vector3d mDr;
	float AR = mWidth / mHeight;

public:

	pinhole();
	pinhole(Eigen::Vector3d dir, Eigen::Vector3d loc);
	~pinhole();

	Eigen::Vector3d getDir();
	void setDir(int width, int height, int theta, Eigen::Vector3d p);

};
#endif