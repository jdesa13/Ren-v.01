#include "Bass/circle.h"

sphere::sphere()
{
	Eigen::Vector3d fcen(0, 0, 1); Eigen::Vector3d fcol(1, 0, 0);
	mCenter = fcen; mColor = fcol; mRadius = 1;
}

sphere::sphere(Eigen::Vector3d cen, Eigen::Vector3d col, float r)
{
	mCenter = cen; mColor = col; mRadius = r;
}

sphere::~sphere(){}

Eigen::Vector3d sphere::Sectfind(Eigen::Vector3d p, Eigen::Vector3d dr)
{
	Eigen::Vector3d sc = (p - mCenter);
	float a = dr.dot(dr);
	float b = 2.0f * (sc).dot(dr);
	float c = sc.dot(sc) - mRadius * mRadius;
	float D = pow(b, 2.0f) - (4.0f * a * c);

	float t = 0.0f;
	if (D == 0.0f) {
		t = -b / 2.0f;
	}
	else if (D > 0.0) {
		float t0 = (-b - pow(D, (0.5f))) / (a * 2.0);
		float t1 = (-b + pow(D, (0.5f))) / (a * 2.0);
		if (t0 > 0.0) {
			t = t0;
		}
		else
			t = t1;
	}
	else
	{
		return Eigen::Vector3d(-999.0f, -999.0f, -999.0f);

	}

	Eigen::Vector3d sect = p + dr * t;


	return sect;

}

Eigen::Vector3d sphere::normal(Eigen::Vector3d sect)
{
	return sect - mCenter;
}

void sphere::Getcen()
{
	std::cout << mCenter << std::endl;
}
