#include "Ponto3D.h"

float Ponto3D::produto_interno(Ponto3D vet) {
	return (x * vet.x) + (y * vet.y) + (z * vet.z);
}

Ponto3D Ponto3D::operator+(const Ponto3D& pt3dPoint)
{
	Ponto3D result(pt3dPoint.x + x, pt3dPoint.y + y, pt3dPoint.z + z);

	return result;
}

Ponto3D Ponto3D::operator-(const Ponto3D& pt3dPoint)
{

	Ponto3D result(pt3dPoint.x - x, pt3dPoint.y - y, pt3dPoint.z - z);

	return result;
}

Ponto3D Ponto3D::operator*(float fScale)
{

	Ponto3D result(x * fScale, y * fScale, z * fScale);

	return result;
}
/*
Ponto3D operator*(float fScale, const Ponto3D& pt3dPoint)
{
	Ponto3D result;

	result.x = pt3dPoint.x*fScale;
	result.y = pt3dPoint.y*fScale;
	result.z = pt3dPoint.z*fScale;

	return result;
}
*/
Ponto3D Ponto3D::operator/(float fScale)
{

	Ponto3D result(x / fScale, y / fScale, z / fScale);
	
	return result;
}

void Ponto3D::operator*=(float fScale)
{
	x *= fScale;
	y *= fScale;
	z *= fScale;

}

void Ponto3D::operator/=(float fScale)
{
	x /= fScale;
	y /= fScale;
	z /= fScale;


}

void Ponto3D::operator+=(const Ponto3D& pt3dPoint)
{
	x += pt3dPoint.x;
	y += pt3dPoint.y;
	z += pt3dPoint.z;

}

void Ponto3D::operator-=(const Ponto3D& pt3dPoint)
{
	x -= pt3dPoint.x;
	y -= pt3dPoint.y;
	z -= pt3dPoint.z;
	
}
void Ponto3D::operator=(const Ponto3D& pt3dPoint)
{
    x = pt3dPoint.x;
	y = pt3dPoint.y;
	z = pt3dPoint.z;
	

}

/*
float get_x(void)
    return x;
float get_y(void)
    return y;
float get_z(void)
    return z;
*/