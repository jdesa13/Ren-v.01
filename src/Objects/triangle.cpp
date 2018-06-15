#include "Bass/triangle.h"

triangle::triangle()
{
	Eigen::Vector3d fA(0, 0, 1); Eigen::Vector3d fB(0, 0, 1); Eigen::Vector3d fC(0, 0, 1); Eigen::Vector3d fcol(1, 0, 0);
	A = fA; B = fB; C = fC; mColor = fcol; theta = 66;
}

triangle::triangle(Eigen::Vector3d p0, Eigen::Vector3d p1, Eigen::Vector3d p2, Eigen::Vector3d col, float t)
{
	A = p0; B = p1; C = p2; mColor = col; theta = t;
}

triangle::~triangle(){}

Eigen::Vector3d triangle::Sectfind(Eigen::Vector3d p, Eigen::Vector3d dr)
{
	Eigen::Vector3d Q;
	Eigen::Vector3d BA = B - A;
	Eigen::Vector3d CA = C - A;
	Eigen::Vector3d ABC = BA.cross(CA);
	float CBA = ABC.norm();

	Eigen::Vector3d normal = ABC / CBA;

	float d = normal.dot(A);

	float t = (d - (normal.dot(p))) / (normal.dot(dr));

	Q = p + (t*dr);

	float check1 = ((B - A).cross(Q - A)).dot(normal);
	float check2 = ((C - B).cross(Q - B)).dot(normal);
	float check3 = ((A - C).cross(Q - C)).dot(normal);

	if (check1 >= 0 && check2 >= 0 && check3 >= 0)
	{
		return Q;
	}
	else
		return Eigen::Vector3d(-999.0f, -999.0f, -999.0f);

}


Eigen::Vector3d triangle::normal()
{
	Eigen::Vector3d U = B - A;
	Eigen::Vector3d V = C - A;

	Eigen::Vector3d UV = U.cross(V);
	float nom = (sqrt(pow(UV(0),2)+ pow(UV(1), 2)+ pow(UV(2), 2)));
	Eigen::Vector3d normy((UV(0) / nom), (UV(1) / nom), (UV(2) / nom));
	
	return normy;
}

void triangle::showPoints()
{
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << C << std::endl;
}
