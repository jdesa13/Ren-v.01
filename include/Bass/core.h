#include "Bass/camera.h"
#include "Bass/pinhole_camera.h"
#include "Bass/hit.h"
#include "Bass/circle.h"
#include <Eigen/Dense>

#ifndef _J_CORE
#define _J_CORE
class core : public camera {
protected:
	pinhole mPin;
	hit mFind;

public:

	core();
	core(pinhole pin, hit find);
	~core();
	
	float* cirCol(sphere cir, Eigen::Vector3d origin);
};
#endif