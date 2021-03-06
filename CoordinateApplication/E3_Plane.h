#pragma once

#include "E3_Point.h"

/*
@brief: This is a class of three-dimensional plane
@author: JoMar
@date: 2016-06-12
*/
typedef class _e3_plane
{
public:
	_e3_plane();

	_e3_plane(const _e3_plane& newObject);

	_e3_plane(const double& newA, const double& newB, const double& newC, const double& newD);

	_e3_plane(const E3_POINT& point, const E3_VECTOR& vector1, const E3_VECTOR& vector2);

	~_e3_plane();

	_e3_plane& operator=(const _e3_plane& object);

	/*
	@brief: This is a function to get a normal vector of the plane
	@return: normal vector
	@author: JoMar
	@date: 2016-06-12
	*/
	E3_VECTOR NormalVector() const;

	double a;
	double b;
	double c;
	double d;
}
/*
@brief: This is a class of three-dimensional plane
@author: JoMar
@date: 2016-06-12
*/
E3_PLANE;

