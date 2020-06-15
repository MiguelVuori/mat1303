#pragma once
#include "Ponto3D.h"
#include "GridCell.h"
#include "Triangulo.h"

class Implicito
{
private:
	float xmin, ymin, zmin, xmax, ymax, zmax;
	int n;
public:
	Implicito(float xi = -1, float yi = -1, float zi = -1,
		float xf = 1, float yf = 1, float zf = 1, int pontos = 10)
	{
		xmin = xi;
		ymin = yi;
		zmin = zi;
		xmax = xf;
		ymax = yf;
		zmax = zf;
		n = pontos;
	}

	float f(float *v)
	{
		float x = v[0];
		float y = v[1];
		float z = v[2];
		return(x*x*x + y * y*y + z * z*z + 1 - (x + y + z + 1)*(x + y + z + 1)*(x + y + z + 1));
	}
	void normal(float *normal, float *v) {
		float x = v[0];
		float y = v[1];
		float z = v[2];
		normal[0] = 3 * x*x - 3 * (x + y + z - 1)*(x + y + z - 1);
		normal[1] = 3 * y*y - 3 * (x + y + z - 1)*(x + y + z - 1);
		normal[2] = 3 * z*z - 3 * (x + y + z - 1)*(x + y + z - 1);
	}
	void tetraedro(float *v0, float *v1, float *v2, float *v3);
	int Polygonise(GridCell grid,float isolevel,Triangulo *triangles)
	void visualiza_implicito();
};

