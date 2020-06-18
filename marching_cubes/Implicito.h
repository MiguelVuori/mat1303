#include "Ponto3D.h"
#include "GridCell.h"
#include "Triangulo.h"
#include <cmath>
#include <vector>

using namespace std;

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

	float f(Ponto3D ponto)
	{
		float x = ponto.x;
		float y = ponto.y;
		float z = ponto.z;
		return -sin(x*x + y*y) + z;
	}
	Ponto3D normal(Ponto3D v)
	{
		Ponto3D ponto;
		float x = v.x;
		float y = v.y;
		float z = v.z;
		ponto.x = 3 * x * x - 3 * (x + y + z - 1) * (x + y + z - 1);
		ponto.y = 3 * y * y - 3 * (x + y + z - 1) * (x + y + z - 1);
		ponto.z = 3 * z * z - 3 * (x + y + z - 1) * (x + y + z - 1);
		return ponto;
	}

	void tetraedro(float *v0, float *v1, float *v2, float *v3);

	void Polygonise(GridCell grid, float isolevel, float dx, float dy, float dz, float eyex, float eyey, float eyez, bool lines, vector<Triangulo> &triangles);
	
	void MarchingLines(vector<Triangulo> &triangles);

	Ponto3D VertexInterp(float isolevel,Ponto3D p1,Ponto3D p2,float valp1,float valp2);

	float LinearInterp(Ponto3D p1, Ponto3D p2, Ponto3D p3, float dx, float dy, float dz, Ponto3D observer);

	vector<Triangulo> calcula_triangles(float eyex, float eyey, float eyez, bool lines);

	void showtriangles(vector<Triangulo> &triangles);
};

