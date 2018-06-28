#include "Bass/material.h"
material::material()
{
	Kd = 1; Ks = 1; Ka = 1;
}

material::material(float d, float s, float a)
{
	Kd = d; Ks = s; Ka = a;
}

material::~material(){}

void material::SLcol(Eigen::Vector3d lcol)
{

	Eigen::Vector3d Snorm = mColor.normalized();
	Eigen::Vector3d Lnorm = lcol.normalized();
	Eigen::Vector3d SLcol(Snorm(0)*Lnorm(0), Snorm(1)*Lnorm(1), Snorm(2)*Lnorm(2));

	slcol = SLcol;
}

Eigen::Vector3d material::diffuse(Eigen::Vector3d n, Eigen::Vector3d lcol, Eigen::Vector3d lpos, Eigen::Vector3d sect)
{
	Eigen::Vector3d Nnorm = n.normalized();

	float ldn = Nnorm.dot((lpos - sect).normalized());
	if (ldn < 0) {
		ldn = 0;
	}

	SLcol(lcol);

	Eigen::Vector3d Dc = Kd * slcol * ldn;

	return Dc;
}

Eigen::Vector3d material::phong(Eigen::Vector3d n, Eigen::Vector3d lpos, Eigen::Vector3d sect, Eigen::Vector3d p, Eigen::Vector3d lcol, float shine)
{
	Eigen::Vector3d Nnorm = n.normalized();
	Eigen::Vector3d rdeye = (sect - p).normalized();
	Eigen::Vector3d IncomingLight = (sect - lpos).normalized();


	Eigen::Vector3d  L = (2.0 * IncomingLight.dot(Nnorm))  * Nnorm - (IncomingLight);
	float spec = powf(std::max(L.dot(rdeye), 0.0), shine);
	Eigen::Vector3d EV = Ks * lcol.normalized() * spec;
	
	return EV;
}

Eigen::Vector3d material::ambient()
{
	Eigen::Vector3d Ac = Ka * slcol * Kd;
	
	return Ac;
}

