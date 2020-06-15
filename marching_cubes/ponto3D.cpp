#include "ponto3D.h"

Ponto3D operator+(const Ponto3D& pt3dPoint1, const Ponto3D& pt3dPoint2)
{
	Ponto3D result;

	result.x = pt3dPoint1.x + pt3dPoint2.x;
	result.y = pt3dPoint1.y + pt3dPoint2.y;
	result.z = pt3dPoint1.z + pt3dPoint2.z;

	return result;
}

Ponto3D operator-(const Ponto3D& pt3dPoint1, const Ponto3D& pt3dPoint2)
{
	Ponto3D result;

	result.x = pt3dPoint1.x - pt3dPoint2.x;
	result.y = pt3dPoint1.y - pt3dPoint2.y;
	result.z = pt3dPoint1.z - pt3dPoint2.z;

	return result;
}

Ponto3D operator*(const Ponto3D& pt3dPoint, float fScale)
{
	Ponto3D result;

	result.x = pt3dPoint.x*fScale;
	result.y = pt3dPoint.y*fScale;
	result.z = pt3dPoint.z*fScale;

	return result;
}

Ponto3D operator*(float fScale, const Ponto3D& pt3dPoint)
{
	Ponto3D result;

	result.x = pt3dPoint.x*fScale;
	result.y = pt3dPoint.y*fScale;
	result.z = pt3dPoint.z*fScale;

	return result;
}

Ponto3D operator/(const Ponto3D& pt3dPoint, float fScale)
{
	Ponto3D result;

	result.x = pt3dPoint.x/fScale;
	result.y = pt3dPoint.y/fScale;
	result.z = pt3dPoint.z/fScale;
	
	return result;
}

Ponto3D& operator*=(Ponto3D& pt3dPoint, float fScale)
{
	pt3dPoint.x *= fScale;
	pt3dPoint.y *= fScale;
	pt3dPoint.z *= fScale;

	return pt3dPoint;
}

Ponto3D& operator/=(Ponto3D& pt3dPoint, float fScale)
{
	pt3dPoint.x /= fScale;
	pt3dPoint.y /= fScale;
	pt3dPoint.z /= fScale;

	return pt3dPoint;
}

Ponto3D& operator+=(Ponto3D& pt3dPoint1, const Ponto3D& pt3dPoint2)
{
	pt3dPoint1.x += pt3dPoint2.x;
	pt3dPoint1.y += pt3dPoint2.y;
	pt3dPoint1.z += pt3dPoint2.z;

	return pt3dPoint1;
}

Ponto3D& operator-=(Ponto3D& pt3dPoint1, const Ponto3D& pt3dPoint2)
{
	pt3dPoint1.x -= pt3dPoint2.x;
	pt3dPoint1.y -= pt3dPoint2.y;
	pt3dPoint1.z -= pt3dPoint2.z;
	
	return pt3dPoint1;
}
Ponto3D& operator=(Ponto3D& pt3dPoint1, const Ponto3D& pt3dPoint2)
{
    pt3dPoint1.x = pt3dPoint2.x;
	pt3dPoint1.y = pt3dPoint2.y;
	pt3dPoint1.z = pt3dPoint2.z;
	
	return pt3dPoint1;
}

float get_x(void)
    return x;
float get_y(void)
    return y;
float get_z(void)
    return z;