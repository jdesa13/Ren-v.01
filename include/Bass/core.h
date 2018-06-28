#include "Bass/camera.h"
#include <Eigen/Dense>

#ifndef _J_CORE
#define _J_CORE
class core : public camera {
protected:
	float* mPixel;

public:

	core();
	core(float* pixel);
	~core();
	
	void Corecol(int index, Eigen::Vector3d fill);
	float* getCcore();
};
#endif