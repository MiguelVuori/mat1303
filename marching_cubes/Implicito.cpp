#include "Implicito.h"
#include "Ponto3D.h"
#include <GL/glut.h>
#include <cmath>
#include "GridCell.h"
#include <iostream>

/*
void Implicito::tetraedro(float *v0, float *v1, float *v2, float *v3)
{
	float w[4];
	float p[4][3],t;
	int   s = 0;

	w[0] = f(v0);
	w[1] = f(v1);
	w[2] = f(v2);
	w[3] = f(v3);

	

	if (w[0] * w[1] < 0)
	{
		t = -w[0] / (w[1] - w[0]);
		for (int i = 0; i < 3; i++)
			p[s][i] = v0[i] + t * (v1[i] - v0[i]);
		s++;
	}
	
	if (w[1] * w[3] < 0)
	{
		t = -w[1] / (w[3] - w[1]);
		for (int i = 0; i < 3; i++)
			p[s][i] = v1[i] + t * (v3[i] - v1[i]);
		s++;
	}
	
	if (w[3] * w[0] < 0)
	{
		t = -w[0] / (w[3] - w[0]);
		for (int i = 0; i < 3; i++)
			p[s][i] = v0[i] + t * (v3[i] - v0[i]);
		s++;
	}
	
	if (w[2] * w[3] < 0)
	{
		t = -w[2] / (w[3] - w[2]);
		for (int i = 0; i < 3; i++)
			p[s][i] = v2[i] + t * (v3[i] - v2[i]);
		s++;
	}
	if (w[0] * w[2] < 0)
	{
		t = -w[0] / (w[2] - w[0]);
		for (int i = 0; i < 3; i++)
			p[s][i] = v0[i] + t * (v2[i] - v0[i]);
		s++;
	}

	if (w[1] * w[2] < 0)
	{
		t = -w[1] / (w[2] - w[1]);
		for (int i = 0; i < 3; i++)
			p[s][i] = v1[i] + t * (v2[i] - v1[i]);
		s++;
	}

	
#define TETRA 1
	if (s == 3) {
#if TETRA
		glColor3f(0, 0, 1);
		glBegin(GL_LINE_LOOP);
		glVertex3fv(v0);
		glVertex3fv(v1);
		glVertex3fv(v2);
		glEnd();
		glBegin(GL_LINES);
		glVertex3fv(v0);
		glVertex3fv(v3);
		glVertex3fv(v1);
		glVertex3fv(v3);
		glVertex3fv(v2);
		glVertex3fv(v3);
		glEnd();
#endif
	}
	if (s == 4) {
#if TETRA
		glColor3f(0, 0, 1);
		glBegin(GL_LINE_LOOP);
		glVertex3fv(v0);
		glVertex3fv(v1);
		glVertex3fv(v2);
		glEnd();
		glBegin(GL_LINES);
		glVertex3fv(v0);
		glVertex3fv(v3);
		glVertex3fv(v1);
		glVertex3fv(v3);
		glVertex3fv(v2);
		glVertex3fv(v3);
		glEnd();
#endif
	}
	glColor3f(218.0/255.9, 160.0/255, 30.0/255);
	if (s == 30) {
		glBegin(GL_LINE_LOOP);
		glVertex3fv(p[0]);
		glVertex3fv(p[1]);
		glVertex3fv(p[2]);
		glEnd();
	}


	float nv[3];
	if (s == 3) {
		glBegin(GL_TRIANGLES);
		normal(nv, p[0]);
		glNormal3fv(nv);
		glVertex3fv(p[0]);

		normal(nv, p[1]);
		glNormal3fv(nv);
		glVertex3fv(p[1]);

		normal(nv, p[2]);
		glNormal3fv(nv);
		glVertex3fv(p[2]);
		glEnd();
	}

	if (s == 40) {
		glBegin(GL_LINE_LOOP);
		glVertex3fv(p[0]);
		glVertex3fv(p[1]);
		glVertex3fv(p[2]);
		glVertex3fv(p[3]);
		glEnd();
	}
	if (s == 4) {
		glBegin(GL_QUADS);
		normal(nv, p[0]);
		glNormal3f(nv[0],nv[1],nv[2]);
		glVertex3fv(p[0]);

		normal(nv, p[1]);
		glNormal3f(nv[0], nv[1], nv[2]);
		glVertex3fv(p[1]);

		normal(nv, p[2]);
		glNormal3f(nv[0], nv[1], nv[2]);
		glVertex3fv(p[2]);

		normal(nv, p[3]);
		glNormal3f(nv[0], nv[1], nv[2]);
		glVertex3fv(p[3]);
		glEnd();
	}
}
*/
void Implicito::visualiza_implicito()
{
	Ponto3D inicio;
	Ponto3D vetor[8];
	float vals[8];
	float dx, dy, dz;
	dx = (xmax - xmin) / n;
	dy = (ymax - ymin) / n;
	dz = (zmax - zmin) / n;

	inicio.x = xmin;
	for (int i = 0; i < n; i++)
	{
		inicio.y = ymin;
		for (int j = 0; j < n; j++)
		{
			inicio.z = zmin;
			for (int k = 0; k < n; k++)
			{

				vetor[0] = inicio; // determina x, y, z
				inicio.x = inicio.x + dx;
				vetor[1] = inicio; // determina x + dx, y, z
				inicio.z = inicio.z + dz;
				vetor[2] = inicio; // determina x + dx, y, z + dz
				inicio.x = inicio.x - dx;
				vetor[3] = inicio; // determina x, y, z + dz
				inicio.z = inicio.z - dz;
				inicio.y = inicio.y + dy;
				vetor[4] = inicio; //determina x, y + dy, z;
				inicio.x = inicio.x + dx;
				vetor[5] = inicio; // determina x + dx, y + dy, z
				inicio.z = inicio.z + dz;
				vetor[6] = inicio; // determina x + dx, y + dy, z + dz
				inicio.x = inicio.x - dx;
				vetor[7] = inicio; // determina x, y + dy, z + dz

				for (int m = 0; m < 8; m++)
				{
					vals[m] = f(vetor[m]);
				}
				GridCell grid(vetor, vals);
				Polygonise(grid, 0, dx, dy, dz);
				inicio.y = inicio.y - dy;
			}
			inicio.y += dy;
		}
		inicio.x += dx;
	}
}

int Implicito::Polygonise(GridCell grid, float isolevel, float dx, float dy, float dz)
{

	int i, ntriang;
	int cubeindex;
	float normal_list[12];
	Ponto3D vertlist[12];
	Ponto3D observer(5, 5, 3);
	int edgeTable[256] = {
		0x0, 0x109, 0x203, 0x30a, 0x406, 0x50f, 0x605, 0x70c,
		0x80c, 0x905, 0xa0f, 0xb06, 0xc0a, 0xd03, 0xe09, 0xf00,
		0x190, 0x99, 0x393, 0x29a, 0x596, 0x49f, 0x795, 0x69c,
		0x99c, 0x895, 0xb9f, 0xa96, 0xd9a, 0xc93, 0xf99, 0xe90,
		0x230, 0x339, 0x33, 0x13a, 0x636, 0x73f, 0x435, 0x53c,
		0xa3c, 0xb35, 0x83f, 0x936, 0xe3a, 0xf33, 0xc39, 0xd30,
		0x3a0, 0x2a9, 0x1a3, 0xaa, 0x7a6, 0x6af, 0x5a5, 0x4ac,
		0xbac, 0xaa5, 0x9af, 0x8a6, 0xfaa, 0xea3, 0xda9, 0xca0,
		0x460, 0x569, 0x663, 0x76a, 0x66, 0x16f, 0x265, 0x36c,
		0xc6c, 0xd65, 0xe6f, 0xf66, 0x86a, 0x963, 0xa69, 0xb60,
		0x5f0, 0x4f9, 0x7f3, 0x6fa, 0x1f6, 0xff, 0x3f5, 0x2fc,
		0xdfc, 0xcf5, 0xfff, 0xef6, 0x9fa, 0x8f3, 0xbf9, 0xaf0,
		0x650, 0x759, 0x453, 0x55a, 0x256, 0x35f, 0x55, 0x15c,
		0xe5c, 0xf55, 0xc5f, 0xd56, 0xa5a, 0xb53, 0x859, 0x950,
		0x7c0, 0x6c9, 0x5c3, 0x4ca, 0x3c6, 0x2cf, 0x1c5, 0xcc,
		0xfcc, 0xec5, 0xdcf, 0xcc6, 0xbca, 0xac3, 0x9c9, 0x8c0,
		0x8c0, 0x9c9, 0xac3, 0xbca, 0xcc6, 0xdcf, 0xec5, 0xfcc,
		0xcc, 0x1c5, 0x2cf, 0x3c6, 0x4ca, 0x5c3, 0x6c9, 0x7c0,
		0x950, 0x859, 0xb53, 0xa5a, 0xd56, 0xc5f, 0xf55, 0xe5c,
		0x15c, 0x55, 0x35f, 0x256, 0x55a, 0x453, 0x759, 0x650,
		0xaf0, 0xbf9, 0x8f3, 0x9fa, 0xef6, 0xfff, 0xcf5, 0xdfc,
		0x2fc, 0x3f5, 0xff, 0x1f6, 0x6fa, 0x7f3, 0x4f9, 0x5f0,
		0xb60, 0xa69, 0x963, 0x86a, 0xf66, 0xe6f, 0xd65, 0xc6c,
		0x36c, 0x265, 0x16f, 0x66, 0x76a, 0x663, 0x569, 0x460,
		0xca0, 0xda9, 0xea3, 0xfaa, 0x8a6, 0x9af, 0xaa5, 0xbac,
		0x4ac, 0x5a5, 0x6af, 0x7a6, 0xaa, 0x1a3, 0x2a9, 0x3a0,
		0xd30, 0xc39, 0xf33, 0xe3a, 0x936, 0x83f, 0xb35, 0xa3c,
		0x53c, 0x435, 0x73f, 0x636, 0x13a, 0x33, 0x339, 0x230,
		0xe90, 0xf99, 0xc93, 0xd9a, 0xa96, 0xb9f, 0x895, 0x99c,
		0x69c, 0x795, 0x49f, 0x596, 0x29a, 0x393, 0x99, 0x190,
		0xf00, 0xe09, 0xd03, 0xc0a, 0xb06, 0xa0f, 0x905, 0x80c,
		0x70c, 0x605, 0x50f, 0x406, 0x30a, 0x203, 0x109, 0x0};
	int triTable[256][16] =
		{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 8, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 1, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {1, 8, 3, 9, 8, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {1, 2, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 8, 3, 1, 2, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {9, 2, 10, 0, 2, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {2, 8, 3, 2, 10, 8, 10, 9, 8, -1, -1, -1, -1, -1, -1, -1},
		 {3, 11, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 11, 2, 8, 11, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {1, 9, 0, 2, 3, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {1, 11, 2, 1, 9, 11, 9, 8, 11, -1, -1, -1, -1, -1, -1, -1},
		 {3, 10, 1, 11, 10, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 10, 1, 0, 8, 10, 8, 11, 10, -1, -1, -1, -1, -1, -1, -1},
		 {3, 9, 0, 3, 11, 9, 11, 10, 9, -1, -1, -1, -1, -1, -1, -1},
		 {9, 8, 10, 10, 8, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {4, 7, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {4, 3, 0, 7, 3, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 1, 9, 8, 4, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {4, 1, 9, 4, 7, 1, 7, 3, 1, -1, -1, -1, -1, -1, -1, -1},
		 {1, 2, 10, 8, 4, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {3, 4, 7, 3, 0, 4, 1, 2, 10, -1, -1, -1, -1, -1, -1, -1},
		 {9, 2, 10, 9, 0, 2, 8, 4, 7, -1, -1, -1, -1, -1, -1, -1},
		 {2, 10, 9, 2, 9, 7, 2, 7, 3, 7, 9, 4, -1, -1, -1, -1},
		 {8, 4, 7, 3, 11, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {11, 4, 7, 11, 2, 4, 2, 0, 4, -1, -1, -1, -1, -1, -1, -1},
		 {9, 0, 1, 8, 4, 7, 2, 3, 11, -1, -1, -1, -1, -1, -1, -1},
		 {4, 7, 11, 9, 4, 11, 9, 11, 2, 9, 2, 1, -1, -1, -1, -1},
		 {3, 10, 1, 3, 11, 10, 7, 8, 4, -1, -1, -1, -1, -1, -1, -1},
		 {1, 11, 10, 1, 4, 11, 1, 0, 4, 7, 11, 4, -1, -1, -1, -1},
		 {4, 7, 8, 9, 0, 11, 9, 11, 10, 11, 0, 3, -1, -1, -1, -1},
		 {4, 7, 11, 4, 11, 9, 9, 11, 10, -1, -1, -1, -1, -1, -1, -1},
		 {9, 5, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {9, 5, 4, 0, 8, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 5, 4, 1, 5, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {8, 5, 4, 8, 3, 5, 3, 1, 5, -1, -1, -1, -1, -1, -1, -1},
		 {1, 2, 10, 9, 5, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {3, 0, 8, 1, 2, 10, 4, 9, 5, -1, -1, -1, -1, -1, -1, -1},
		 {5, 2, 10, 5, 4, 2, 4, 0, 2, -1, -1, -1, -1, -1, -1, -1},
		 {2, 10, 5, 3, 2, 5, 3, 5, 4, 3, 4, 8, -1, -1, -1, -1},
		 {9, 5, 4, 2, 3, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 11, 2, 0, 8, 11, 4, 9, 5, -1, -1, -1, -1, -1, -1, -1},
		 {0, 5, 4, 0, 1, 5, 2, 3, 11, -1, -1, -1, -1, -1, -1, -1},
		 {2, 1, 5, 2, 5, 8, 2, 8, 11, 4, 8, 5, -1, -1, -1, -1},
		 {10, 3, 11, 10, 1, 3, 9, 5, 4, -1, -1, -1, -1, -1, -1, -1},
		 {4, 9, 5, 0, 8, 1, 8, 10, 1, 8, 11, 10, -1, -1, -1, -1},
		 {5, 4, 0, 5, 0, 11, 5, 11, 10, 11, 0, 3, -1, -1, -1, -1},
		 {5, 4, 8, 5, 8, 10, 10, 8, 11, -1, -1, -1, -1, -1, -1, -1},
		 {9, 7, 8, 5, 7, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {9, 3, 0, 9, 5, 3, 5, 7, 3, -1, -1, -1, -1, -1, -1, -1},
		 {0, 7, 8, 0, 1, 7, 1, 5, 7, -1, -1, -1, -1, -1, -1, -1},
		 {1, 5, 3, 3, 5, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {9, 7, 8, 9, 5, 7, 10, 1, 2, -1, -1, -1, -1, -1, -1, -1},
		 {10, 1, 2, 9, 5, 0, 5, 3, 0, 5, 7, 3, -1, -1, -1, -1},
		 {8, 0, 2, 8, 2, 5, 8, 5, 7, 10, 5, 2, -1, -1, -1, -1},
		 {2, 10, 5, 2, 5, 3, 3, 5, 7, -1, -1, -1, -1, -1, -1, -1},
		 {7, 9, 5, 7, 8, 9, 3, 11, 2, -1, -1, -1, -1, -1, -1, -1},
		 {9, 5, 7, 9, 7, 2, 9, 2, 0, 2, 7, 11, -1, -1, -1, -1},
		 {2, 3, 11, 0, 1, 8, 1, 7, 8, 1, 5, 7, -1, -1, -1, -1},
		 {11, 2, 1, 11, 1, 7, 7, 1, 5, -1, -1, -1, -1, -1, -1, -1},
		 {9, 5, 8, 8, 5, 7, 10, 1, 3, 10, 3, 11, -1, -1, -1, -1},
		 {5, 7, 0, 5, 0, 9, 7, 11, 0, 1, 0, 10, 11, 10, 0, -1},
		 {11, 10, 0, 11, 0, 3, 10, 5, 0, 8, 0, 7, 5, 7, 0, -1},
		 {11, 10, 5, 7, 11, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {10, 6, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 8, 3, 5, 10, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {9, 0, 1, 5, 10, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {1, 8, 3, 1, 9, 8, 5, 10, 6, -1, -1, -1, -1, -1, -1, -1},
		 {1, 6, 5, 2, 6, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {1, 6, 5, 1, 2, 6, 3, 0, 8, -1, -1, -1, -1, -1, -1, -1},
		 {9, 6, 5, 9, 0, 6, 0, 2, 6, -1, -1, -1, -1, -1, -1, -1},
		 {5, 9, 8, 5, 8, 2, 5, 2, 6, 3, 2, 8, -1, -1, -1, -1},
		 {2, 3, 11, 10, 6, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {11, 0, 8, 11, 2, 0, 10, 6, 5, -1, -1, -1, -1, -1, -1, -1},
		 {0, 1, 9, 2, 3, 11, 5, 10, 6, -1, -1, -1, -1, -1, -1, -1},
		 {5, 10, 6, 1, 9, 2, 9, 11, 2, 9, 8, 11, -1, -1, -1, -1},
		 {6, 3, 11, 6, 5, 3, 5, 1, 3, -1, -1, -1, -1, -1, -1, -1},
		 {0, 8, 11, 0, 11, 5, 0, 5, 1, 5, 11, 6, -1, -1, -1, -1},
		 {3, 11, 6, 0, 3, 6, 0, 6, 5, 0, 5, 9, -1, -1, -1, -1},
		 {6, 5, 9, 6, 9, 11, 11, 9, 8, -1, -1, -1, -1, -1, -1, -1},
		 {5, 10, 6, 4, 7, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {4, 3, 0, 4, 7, 3, 6, 5, 10, -1, -1, -1, -1, -1, -1, -1},
		 {1, 9, 0, 5, 10, 6, 8, 4, 7, -1, -1, -1, -1, -1, -1, -1},
		 {10, 6, 5, 1, 9, 7, 1, 7, 3, 7, 9, 4, -1, -1, -1, -1},
		 {6, 1, 2, 6, 5, 1, 4, 7, 8, -1, -1, -1, -1, -1, -1, -1},
		 {1, 2, 5, 5, 2, 6, 3, 0, 4, 3, 4, 7, -1, -1, -1, -1},
		 {8, 4, 7, 9, 0, 5, 0, 6, 5, 0, 2, 6, -1, -1, -1, -1},
		 {7, 3, 9, 7, 9, 4, 3, 2, 9, 5, 9, 6, 2, 6, 9, -1},
		 {3, 11, 2, 7, 8, 4, 10, 6, 5, -1, -1, -1, -1, -1, -1, -1},
		 {5, 10, 6, 4, 7, 2, 4, 2, 0, 2, 7, 11, -1, -1, -1, -1},
		 {0, 1, 9, 4, 7, 8, 2, 3, 11, 5, 10, 6, -1, -1, -1, -1},
		 {9, 2, 1, 9, 11, 2, 9, 4, 11, 7, 11, 4, 5, 10, 6, -1},
		 {8, 4, 7, 3, 11, 5, 3, 5, 1, 5, 11, 6, -1, -1, -1, -1},
		 {5, 1, 11, 5, 11, 6, 1, 0, 11, 7, 11, 4, 0, 4, 11, -1},
		 {0, 5, 9, 0, 6, 5, 0, 3, 6, 11, 6, 3, 8, 4, 7, -1},
		 {6, 5, 9, 6, 9, 11, 4, 7, 9, 7, 11, 9, -1, -1, -1, -1},
		 {10, 4, 9, 6, 4, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {4, 10, 6, 4, 9, 10, 0, 8, 3, -1, -1, -1, -1, -1, -1, -1},
		 {10, 0, 1, 10, 6, 0, 6, 4, 0, -1, -1, -1, -1, -1, -1, -1},
		 {8, 3, 1, 8, 1, 6, 8, 6, 4, 6, 1, 10, -1, -1, -1, -1},
		 {1, 4, 9, 1, 2, 4, 2, 6, 4, -1, -1, -1, -1, -1, -1, -1},
		 {3, 0, 8, 1, 2, 9, 2, 4, 9, 2, 6, 4, -1, -1, -1, -1},
		 {0, 2, 4, 4, 2, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {8, 3, 2, 8, 2, 4, 4, 2, 6, -1, -1, -1, -1, -1, -1, -1},
		 {10, 4, 9, 10, 6, 4, 11, 2, 3, -1, -1, -1, -1, -1, -1, -1},
		 {0, 8, 2, 2, 8, 11, 4, 9, 10, 4, 10, 6, -1, -1, -1, -1},
		 {3, 11, 2, 0, 1, 6, 0, 6, 4, 6, 1, 10, -1, -1, -1, -1},
		 {6, 4, 1, 6, 1, 10, 4, 8, 1, 2, 1, 11, 8, 11, 1, -1},
		 {9, 6, 4, 9, 3, 6, 9, 1, 3, 11, 6, 3, -1, -1, -1, -1},
		 {8, 11, 1, 8, 1, 0, 11, 6, 1, 9, 1, 4, 6, 4, 1, -1},
		 {3, 11, 6, 3, 6, 0, 0, 6, 4, -1, -1, -1, -1, -1, -1, -1},
		 {6, 4, 8, 11, 6, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {7, 10, 6, 7, 8, 10, 8, 9, 10, -1, -1, -1, -1, -1, -1, -1},
		 {0, 7, 3, 0, 10, 7, 0, 9, 10, 6, 7, 10, -1, -1, -1, -1},
		 {10, 6, 7, 1, 10, 7, 1, 7, 8, 1, 8, 0, -1, -1, -1, -1},
		 {10, 6, 7, 10, 7, 1, 1, 7, 3, -1, -1, -1, -1, -1, -1, -1},
		 {1, 2, 6, 1, 6, 8, 1, 8, 9, 8, 6, 7, -1, -1, -1, -1},
		 {2, 6, 9, 2, 9, 1, 6, 7, 9, 0, 9, 3, 7, 3, 9, -1},
		 {7, 8, 0, 7, 0, 6, 6, 0, 2, -1, -1, -1, -1, -1, -1, -1},
		 {7, 3, 2, 6, 7, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {2, 3, 11, 10, 6, 8, 10, 8, 9, 8, 6, 7, -1, -1, -1, -1},
		 {2, 0, 7, 2, 7, 11, 0, 9, 7, 6, 7, 10, 9, 10, 7, -1},
		 {1, 8, 0, 1, 7, 8, 1, 10, 7, 6, 7, 10, 2, 3, 11, -1},
		 {11, 2, 1, 11, 1, 7, 10, 6, 1, 6, 7, 1, -1, -1, -1, -1},
		 {8, 9, 6, 8, 6, 7, 9, 1, 6, 11, 6, 3, 1, 3, 6, -1},
		 {0, 9, 1, 11, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {7, 8, 0, 7, 0, 6, 3, 11, 0, 11, 6, 0, -1, -1, -1, -1},
		 {7, 11, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {7, 6, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {3, 0, 8, 11, 7, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 1, 9, 11, 7, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {8, 1, 9, 8, 3, 1, 11, 7, 6, -1, -1, -1, -1, -1, -1, -1},
		 {10, 1, 2, 6, 11, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {1, 2, 10, 3, 0, 8, 6, 11, 7, -1, -1, -1, -1, -1, -1, -1},
		 {2, 9, 0, 2, 10, 9, 6, 11, 7, -1, -1, -1, -1, -1, -1, -1},
		 {6, 11, 7, 2, 10, 3, 10, 8, 3, 10, 9, 8, -1, -1, -1, -1},
		 {7, 2, 3, 6, 2, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {7, 0, 8, 7, 6, 0, 6, 2, 0, -1, -1, -1, -1, -1, -1, -1},
		 {2, 7, 6, 2, 3, 7, 0, 1, 9, -1, -1, -1, -1, -1, -1, -1},
		 {1, 6, 2, 1, 8, 6, 1, 9, 8, 8, 7, 6, -1, -1, -1, -1},
		 {10, 7, 6, 10, 1, 7, 1, 3, 7, -1, -1, -1, -1, -1, -1, -1},
		 {10, 7, 6, 1, 7, 10, 1, 8, 7, 1, 0, 8, -1, -1, -1, -1},
		 {0, 3, 7, 0, 7, 10, 0, 10, 9, 6, 10, 7, -1, -1, -1, -1},
		 {7, 6, 10, 7, 10, 8, 8, 10, 9, -1, -1, -1, -1, -1, -1, -1},
		 {6, 8, 4, 11, 8, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {3, 6, 11, 3, 0, 6, 0, 4, 6, -1, -1, -1, -1, -1, -1, -1},
		 {8, 6, 11, 8, 4, 6, 9, 0, 1, -1, -1, -1, -1, -1, -1, -1},
		 {9, 4, 6, 9, 6, 3, 9, 3, 1, 11, 3, 6, -1, -1, -1, -1},
		 {6, 8, 4, 6, 11, 8, 2, 10, 1, -1, -1, -1, -1, -1, -1, -1},
		 {1, 2, 10, 3, 0, 11, 0, 6, 11, 0, 4, 6, -1, -1, -1, -1},
		 {4, 11, 8, 4, 6, 11, 0, 2, 9, 2, 10, 9, -1, -1, -1, -1},
		 {10, 9, 3, 10, 3, 2, 9, 4, 3, 11, 3, 6, 4, 6, 3, -1},
		 {8, 2, 3, 8, 4, 2, 4, 6, 2, -1, -1, -1, -1, -1, -1, -1},
		 {0, 4, 2, 4, 6, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {1, 9, 0, 2, 3, 4, 2, 4, 6, 4, 3, 8, -1, -1, -1, -1},
		 {1, 9, 4, 1, 4, 2, 2, 4, 6, -1, -1, -1, -1, -1, -1, -1},
		 {8, 1, 3, 8, 6, 1, 8, 4, 6, 6, 10, 1, -1, -1, -1, -1},
		 {10, 1, 0, 10, 0, 6, 6, 0, 4, -1, -1, -1, -1, -1, -1, -1},
		 {4, 6, 3, 4, 3, 8, 6, 10, 3, 0, 3, 9, 10, 9, 3, -1},
		 {10, 9, 4, 6, 10, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {4, 9, 5, 7, 6, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 8, 3, 4, 9, 5, 11, 7, 6, -1, -1, -1, -1, -1, -1, -1},
		 {5, 0, 1, 5, 4, 0, 7, 6, 11, -1, -1, -1, -1, -1, -1, -1},
		 {11, 7, 6, 8, 3, 4, 3, 5, 4, 3, 1, 5, -1, -1, -1, -1},
		 {9, 5, 4, 10, 1, 2, 7, 6, 11, -1, -1, -1, -1, -1, -1, -1},
		 {6, 11, 7, 1, 2, 10, 0, 8, 3, 4, 9, 5, -1, -1, -1, -1},
		 {7, 6, 11, 5, 4, 10, 4, 2, 10, 4, 0, 2, -1, -1, -1, -1},
		 {3, 4, 8, 3, 5, 4, 3, 2, 5, 10, 5, 2, 11, 7, 6, -1},
		 {7, 2, 3, 7, 6, 2, 5, 4, 9, -1, -1, -1, -1, -1, -1, -1},
		 {9, 5, 4, 0, 8, 6, 0, 6, 2, 6, 8, 7, -1, -1, -1, -1},
		 {3, 6, 2, 3, 7, 6, 1, 5, 0, 5, 4, 0, -1, -1, -1, -1},
		 {6, 2, 8, 6, 8, 7, 2, 1, 8, 4, 8, 5, 1, 5, 8, -1},
		 {9, 5, 4, 10, 1, 6, 1, 7, 6, 1, 3, 7, -1, -1, -1, -1},
		 {1, 6, 10, 1, 7, 6, 1, 0, 7, 8, 7, 0, 9, 5, 4, -1},
		 {4, 0, 10, 4, 10, 5, 0, 3, 10, 6, 10, 7, 3, 7, 10, -1},
		 {7, 6, 10, 7, 10, 8, 5, 4, 10, 4, 8, 10, -1, -1, -1, -1},
		 {6, 9, 5, 6, 11, 9, 11, 8, 9, -1, -1, -1, -1, -1, -1, -1},
		 {3, 6, 11, 0, 6, 3, 0, 5, 6, 0, 9, 5, -1, -1, -1, -1},
		 {0, 11, 8, 0, 5, 11, 0, 1, 5, 5, 6, 11, -1, -1, -1, -1},
		 {6, 11, 3, 6, 3, 5, 5, 3, 1, -1, -1, -1, -1, -1, -1, -1},
		 {1, 2, 10, 9, 5, 11, 9, 11, 8, 11, 5, 6, -1, -1, -1, -1},
		 {0, 11, 3, 0, 6, 11, 0, 9, 6, 5, 6, 9, 1, 2, 10, -1},
		 {11, 8, 5, 11, 5, 6, 8, 0, 5, 10, 5, 2, 0, 2, 5, -1},
		 {6, 11, 3, 6, 3, 5, 2, 10, 3, 10, 5, 3, -1, -1, -1, -1},
		 {5, 8, 9, 5, 2, 8, 5, 6, 2, 3, 8, 2, -1, -1, -1, -1},
		 {9, 5, 6, 9, 6, 0, 0, 6, 2, -1, -1, -1, -1, -1, -1, -1},
		 {1, 5, 8, 1, 8, 0, 5, 6, 8, 3, 8, 2, 6, 2, 8, -1},
		 {1, 5, 6, 2, 1, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {1, 3, 6, 1, 6, 10, 3, 8, 6, 5, 6, 9, 8, 9, 6, -1},
		 {10, 1, 0, 10, 0, 6, 9, 5, 0, 5, 6, 0, -1, -1, -1, -1},
		 {0, 3, 8, 5, 6, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {10, 5, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {11, 5, 10, 7, 5, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {11, 5, 10, 11, 7, 5, 8, 3, 0, -1, -1, -1, -1, -1, -1, -1},
		 {5, 11, 7, 5, 10, 11, 1, 9, 0, -1, -1, -1, -1, -1, -1, -1},
		 {10, 7, 5, 10, 11, 7, 9, 8, 1, 8, 3, 1, -1, -1, -1, -1},
		 {11, 1, 2, 11, 7, 1, 7, 5, 1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 8, 3, 1, 2, 7, 1, 7, 5, 7, 2, 11, -1, -1, -1, -1},
		 {9, 7, 5, 9, 2, 7, 9, 0, 2, 2, 11, 7, -1, -1, -1, -1},
		 {7, 5, 2, 7, 2, 11, 5, 9, 2, 3, 2, 8, 9, 8, 2, -1},
		 {2, 5, 10, 2, 3, 5, 3, 7, 5, -1, -1, -1, -1, -1, -1, -1},
		 {8, 2, 0, 8, 5, 2, 8, 7, 5, 10, 2, 5, -1, -1, -1, -1},
		 {9, 0, 1, 5, 10, 3, 5, 3, 7, 3, 10, 2, -1, -1, -1, -1},
		 {9, 8, 2, 9, 2, 1, 8, 7, 2, 10, 2, 5, 7, 5, 2, -1},
		 {1, 3, 5, 3, 7, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 8, 7, 0, 7, 1, 1, 7, 5, -1, -1, -1, -1, -1, -1, -1},
		 {9, 0, 3, 9, 3, 5, 5, 3, 7, -1, -1, -1, -1, -1, -1, -1},
		 {9, 8, 7, 5, 9, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {5, 8, 4, 5, 10, 8, 10, 11, 8, -1, -1, -1, -1, -1, -1, -1},
		 {5, 0, 4, 5, 11, 0, 5, 10, 11, 11, 3, 0, -1, -1, -1, -1},
		 {0, 1, 9, 8, 4, 10, 8, 10, 11, 10, 4, 5, -1, -1, -1, -1},
		 {10, 11, 4, 10, 4, 5, 11, 3, 4, 9, 4, 1, 3, 1, 4, -1},
		 {2, 5, 1, 2, 8, 5, 2, 11, 8, 4, 5, 8, -1, -1, -1, -1},
		 {0, 4, 11, 0, 11, 3, 4, 5, 11, 2, 11, 1, 5, 1, 11, -1},
		 {0, 2, 5, 0, 5, 9, 2, 11, 5, 4, 5, 8, 11, 8, 5, -1},
		 {9, 4, 5, 2, 11, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {2, 5, 10, 3, 5, 2, 3, 4, 5, 3, 8, 4, -1, -1, -1, -1},
		 {5, 10, 2, 5, 2, 4, 4, 2, 0, -1, -1, -1, -1, -1, -1, -1},
		 {3, 10, 2, 3, 5, 10, 3, 8, 5, 4, 5, 8, 0, 1, 9, -1},
		 {5, 10, 2, 5, 2, 4, 1, 9, 2, 9, 4, 2, -1, -1, -1, -1},
		 {8, 4, 5, 8, 5, 3, 3, 5, 1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 4, 5, 1, 0, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {8, 4, 5, 8, 5, 3, 9, 0, 5, 0, 3, 5, -1, -1, -1, -1},
		 {9, 4, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {4, 11, 7, 4, 9, 11, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1},
		 {0, 8, 3, 4, 9, 7, 9, 11, 7, 9, 10, 11, -1, -1, -1, -1},
		 {1, 10, 11, 1, 11, 4, 1, 4, 0, 7, 4, 11, -1, -1, -1, -1},
		 {3, 1, 4, 3, 4, 8, 1, 10, 4, 7, 4, 11, 10, 11, 4, -1},
		 {4, 11, 7, 9, 11, 4, 9, 2, 11, 9, 1, 2, -1, -1, -1, -1},
		 {9, 7, 4, 9, 11, 7, 9, 1, 11, 2, 11, 1, 0, 8, 3, -1},
		 {11, 7, 4, 11, 4, 2, 2, 4, 0, -1, -1, -1, -1, -1, -1, -1},
		 {11, 7, 4, 11, 4, 2, 8, 3, 4, 3, 2, 4, -1, -1, -1, -1},
		 {2, 9, 10, 2, 7, 9, 2, 3, 7, 7, 4, 9, -1, -1, -1, -1},
		 {9, 10, 7, 9, 7, 4, 10, 2, 7, 8, 7, 0, 2, 0, 7, -1},
		 {3, 7, 10, 3, 10, 2, 7, 4, 10, 1, 10, 0, 4, 0, 10, -1},
		 {1, 10, 2, 8, 7, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {4, 9, 1, 4, 1, 7, 7, 1, 3, -1, -1, -1, -1, -1, -1, -1},
		 {4, 9, 1, 4, 1, 7, 0, 8, 1, 8, 7, 1, -1, -1, -1, -1},
		 {4, 0, 3, 7, 4, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {4, 8, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {9, 10, 8, 10, 11, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {3, 0, 9, 3, 9, 11, 11, 9, 10, -1, -1, -1, -1, -1, -1, -1},
		 {0, 1, 10, 0, 10, 8, 8, 10, 11, -1, -1, -1, -1, -1, -1, -1},
		 {3, 1, 10, 11, 3, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {1, 2, 11, 1, 11, 9, 9, 11, 8, -1, -1, -1, -1, -1, -1, -1},
		 {3, 0, 9, 3, 9, 11, 1, 2, 9, 2, 11, 9, -1, -1, -1, -1},
		 {0, 2, 11, 8, 0, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {3, 2, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {2, 3, 8, 2, 8, 10, 10, 8, 9, -1, -1, -1, -1, -1, -1, -1},
		 {9, 10, 2, 0, 9, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {2, 3, 8, 2, 8, 10, 0, 1, 8, 1, 10, 8, -1, -1, -1, -1},
		 {1, 10, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {1, 3, 8, 9, 1, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 9, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {0, 3, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};

	/*
		Determine the index into the edge table which
		tells us which vertices are inside of the surface
	*/
	cubeindex = 0;
	if (grid.val[0] < isolevel)
		cubeindex |= 1;
	if (grid.val[1] < isolevel)
		cubeindex |= 2;
	if (grid.val[2] < isolevel)
		cubeindex |= 4;
	if (grid.val[3] < isolevel)
		cubeindex |= 8;
	if (grid.val[4] < isolevel)
		cubeindex |= 16;
	if (grid.val[5] < isolevel)
		cubeindex |= 32;
	if (grid.val[6] < isolevel)
		cubeindex |= 64;
	if (grid.val[7] < isolevel)
		cubeindex |= 128;

	/* Cube is entirely in/out of the surface */
	if (edgeTable[cubeindex] == 0)
		return (0);

	/* Find the vertices where the surface intersects the cube */
	if (edgeTable[cubeindex] & 1)
	{
		Ponto3D normal_0, normal_1, aux_0, aux_1;
		float pd_int0, pd_int1;

		vertlist[0] =
			VertexInterp(isolevel, grid.p[0], grid.p[1], grid.val[0], grid.val[1]);

		// aux = vertlist[0];
		// normal.x = (f(aux.x += dx) - f(aux.x -= dx)) / dx;
		// normal.y = (f(aux.y += dy) - f(aux.y -= dy)) / dy;
		// normal.z = (f(aux.z += dz) - f(aux.z -= dz)) / dz;
		// pd_int = normal.produto_interno(observer);

		aux_0 = grid.p[0];
		normal_0.x = (f(aux_0.x += dx) - f(aux_0.x -= dx)) / dx;
		normal_0.y = (f(aux_0.y += dy) - f(aux_0.y -= dy)) / dy;
		normal_0.z = (f(aux_0.z += dz) - f(aux_0.z -= dz)) / dz;
		pd_int0 = normal_0.produto_interno(observer);

		aux_1 = grid.p[1];
		normal_1.x = (f(aux_1.x += dx) - f(aux_1.x -= dx)) / dx;
		normal_1.y = (f(aux_1.y += dy) - f(aux_1.y -= dy)) / dy;
		normal_1.z = (f(aux_1.z += dz) - f(aux_1.z -= dz)) / dz;
		pd_int1 = normal_1.produto_interno(observer);

		normal_list[0] = LinearInterp(grid.p[0], grid.p[1], pd_int0, pd_int1, vertlist[0]);
	}
	if (edgeTable[cubeindex] & 2)
	{

		Ponto3D normal_0, normal_1, aux_0, aux_1;
		float pd_int0, pd_int1;

		vertlist[1] =
			VertexInterp(isolevel, grid.p[1], grid.p[2], grid.val[1], grid.val[2]);

		aux_0 = grid.p[1];
		normal_0.x = (f(aux_0.x += dx) - f(aux_0.x -= dx)) / dx;
		normal_0.y = (f(aux_0.y += dy) - f(aux_0.y -= dy)) / dy;
		normal_0.z = (f(aux_0.z += dz) - f(aux_0.z -= dz)) / dz;
		pd_int0 = normal_0.produto_interno(observer);

		aux_1 = grid.p[2];
		normal_1.x = (f(aux_1.x += dx) - f(aux_1.x -= dx)) / dx;
		normal_1.y = (f(aux_1.y += dy) - f(aux_1.y -= dy)) / dy;
		normal_1.z = (f(aux_1.z += dz) - f(aux_1.z -= dz)) / dz;
		pd_int1 = normal_1.produto_interno(observer);

		normal_list[1] = LinearInterp(grid.p[1], grid.p[2], pd_int0, pd_int1, vertlist[1]);
	}

	if (edgeTable[cubeindex] & 4)
	{
		Ponto3D normal_0, normal_1, aux_0, aux_1;
		float pd_int0, pd_int1;

		vertlist[2] =
			VertexInterp(isolevel, grid.p[2], grid.p[3], grid.val[2], grid.val[3]);

		aux_0 = grid.p[2];
		normal_0.x = (f(aux_0.x += dx) - f(aux_0.x -= dx)) / dx;
		normal_0.y = (f(aux_0.y += dy) - f(aux_0.y -= dy)) / dy;
		normal_0.z = (f(aux_0.z += dz) - f(aux_0.z -= dz)) / dz;
		pd_int0 = normal_0.produto_interno(observer);

		aux_1 = grid.p[3];
		normal_1.x = (f(aux_1.x += dx) - f(aux_1.x -= dx)) / dx;
		normal_1.y = (f(aux_1.y += dy) - f(aux_1.y -= dy)) / dy;
		normal_1.z = (f(aux_1.z += dz) - f(aux_1.z -= dz)) / dz;
		pd_int1 = normal_1.produto_interno(observer);

		normal_list[2] = LinearInterp(grid.p[2], grid.p[3], pd_int0, pd_int1, vertlist[2]);
	}
	if (edgeTable[cubeindex] & 8)
	{
		vertlist[3] =
			VertexInterp(isolevel, grid.p[3], grid.p[0], grid.val[3], grid.val[0]);

		float pd_int0, pd_int1;
		Ponto3D normal_0, normal_1, aux_0, aux_1;
		aux_0 = grid.p[3];

		normal_0.x = (f(aux_0.x += dx) - f(aux_0.x -= dx)) / dx;
		normal_0.y = (f(aux_0.y += dy) - f(aux_0.y -= dy)) / dy;
		normal_0.z = (f(aux_0.z += dz) - f(aux_0.z -= dz)) / dz;
		pd_int0 = normal_0.produto_interno(observer);

		aux_1 = grid.p[0];
		normal_1.x = (f(aux_1.x += dx) - f(aux_1.x -= dx)) / dx;
		normal_1.y = (f(aux_1.y += dy) - f(aux_1.y -= dy)) / dy;
		normal_1.z = (f(aux_1.z += dz) - f(aux_1.z -= dz)) / dz;
		pd_int1 = normal_1.produto_interno(observer);

		normal_list[3] = LinearInterp(grid.p[3], grid.p[0], pd_int0, pd_int1, vertlist[3]);
	}
	if (edgeTable[cubeindex] & 16)
	{
		vertlist[4] =
			VertexInterp(isolevel, grid.p[4], grid.p[5], grid.val[4], grid.val[5]);

		float pd_int0, pd_int1;
		Ponto3D normal_0, normal_1, aux_0, aux_1;
		aux_0 = grid.p[0];

		normal_0.x = (f(aux_0.x += dx) - f(aux_0.x -= dx)) / dx;
		normal_0.y = (f(aux_0.y += dy) - f(aux_0.y -= dy)) / dy;
		normal_0.z = (f(aux_0.z += dz) - f(aux_0.z -= dz)) / dz;
		pd_int0 = normal_0.produto_interno(observer);

		aux_1 = grid.p[1];
		normal_1.x = (f(aux_1.x += dx) - f(aux_1.x -= dx)) / dx;
		normal_1.y = (f(aux_1.y += dy) - f(aux_1.y -= dy)) / dy;
		normal_1.z = (f(aux_1.z += dz) - f(aux_1.z -= dz)) / dz;
		pd_int1 = normal_1.produto_interno(observer);

		normal_list[0] = LinearInterp(grid.p[4], grid.p[5], pd_int0, pd_int1, vertlist[4]);
	}
	if (edgeTable[cubeindex] & 32)
	{
		vertlist[5] =
			VertexInterp(isolevel, grid.p[5], grid.p[6], grid.val[5], grid.val[6]);

		float pd_int0, pd_int1;
		Ponto3D normal_0, normal_1, aux_0, aux_1;
		aux_0 = grid.p[5];

		normal_0.x = (f(aux_0.x += dx) - f(aux_0.x -= dx)) / dx;
		normal_0.y = (f(aux_0.y += dy) - f(aux_0.y -= dy)) / dy;
		normal_0.z = (f(aux_0.z += dz) - f(aux_0.z -= dz)) / dz;
		pd_int0 = normal_0.produto_interno(observer);

		aux_1 = grid.p[6];
		normal_1.x = (f(aux_1.x += dx) - f(aux_1.x -= dx)) / dx;
		normal_1.y = (f(aux_1.y += dy) - f(aux_1.y -= dy)) / dy;
		normal_1.z = (f(aux_1.z += dz) - f(aux_1.z -= dz)) / dz;
		pd_int1 = normal_1.produto_interno(observer);

		normal_list[5] = LinearInterp(grid.p[5], grid.p[6], pd_int0, pd_int1, vertlist[5]);
	}
	if (edgeTable[cubeindex] & 64)
	{
		vertlist[6] =
			VertexInterp(isolevel, grid.p[6], grid.p[7], grid.val[6], grid.val[7]);

		float pd_int0, pd_int1;
		Ponto3D normal_0, normal_1, aux_0, aux_1;
		aux_0 = grid.p[6];

		normal_0.x = (f(aux_0.x += dx) - f(aux_0.x -= dx)) / dx;
		normal_0.y = (f(aux_0.y += dy) - f(aux_0.y -= dy)) / dy;
		normal_0.z = (f(aux_0.z += dz) - f(aux_0.z -= dz)) / dz;
		pd_int0 = normal_0.produto_interno(observer);

		aux_1 = grid.p[7];
		normal_1.x = (f(aux_1.x += dx) - f(aux_1.x -= dx)) / dx;
		normal_1.y = (f(aux_1.y += dy) - f(aux_1.y -= dy)) / dy;
		normal_1.z = (f(aux_1.z += dz) - f(aux_1.z -= dz)) / dz;
		pd_int1 = normal_1.produto_interno(observer);

		normal_list[6] = LinearInterp(grid.p[6], grid.p[7], pd_int0, pd_int1, vertlist[6]);
	}
	if (edgeTable[cubeindex] & 128)
	{
		vertlist[7] =
			VertexInterp(isolevel, grid.p[7], grid.p[4], grid.val[7], grid.val[4]);

		float pd_int0, pd_int1;
		Ponto3D normal_0, normal_1, aux_0, aux_1;
		aux_0 = grid.p[7];

		normal_0.x = (f(aux_0.x += dx) - f(aux_0.x -= dx)) / dx;
		normal_0.y = (f(aux_0.y += dy) - f(aux_0.y -= dy)) / dy;
		normal_0.z = (f(aux_0.z += dz) - f(aux_0.z -= dz)) / dz;
		pd_int0 = normal_0.produto_interno(observer);

		aux_1 = grid.p[4];
		normal_1.x = (f(aux_1.x += dx) - f(aux_1.x -= dx)) / dx;
		normal_1.y = (f(aux_1.y += dy) - f(aux_1.y -= dy)) / dy;
		normal_1.z = (f(aux_1.z += dz) - f(aux_1.z -= dz)) / dz;
		pd_int1 = normal_1.produto_interno(observer);

		normal_list[7] = LinearInterp(grid.p[7], grid.p[4], pd_int0, pd_int1, vertlist[7]);
	}
	if (edgeTable[cubeindex] & 256)
	{
		float pd_int0, pd_int1;
		Ponto3D normal_0, normal_1, aux_0, aux_1;

		vertlist[8] =
			VertexInterp(isolevel, grid.p[0], grid.p[4], grid.val[0], grid.val[4]);

		aux_0 = grid.p[0];

		normal_0.x = (f(aux_0.x += dx) - f(aux_0.x -= dx)) / dx;
		normal_0.y = (f(aux_0.y += dy) - f(aux_0.y -= dy)) / dy;
		normal_0.z = (f(aux_0.z += dz) - f(aux_0.z -= dz)) / dz;
		pd_int0 = normal_0.produto_interno(observer);

		aux_1 = grid.p[4];
		normal_1.x = (f(aux_1.x += dx) - f(aux_1.x -= dx)) / dx;
		normal_1.y = (f(aux_1.y += dy) - f(aux_1.y -= dy)) / dy;
		normal_1.z = (f(aux_1.z += dz) - f(aux_1.z -= dz)) / dz;
		pd_int1 = normal_1.produto_interno(observer);

		normal_list[8] = LinearInterp(grid.p[0], grid.p[4], pd_int0, pd_int1, vertlist[8]);
	}
	if (edgeTable[cubeindex] & 512)
	{
		float pd_int0, pd_int1;
		Ponto3D normal_0, normal_1, aux_0, aux_1;

		vertlist[9] =
			VertexInterp(isolevel, grid.p[1], grid.p[5], grid.val[1], grid.val[5]);

		aux_0 = grid.p[1];

		normal_0.x = (f(aux_0.x += dx) - f(aux_0.x -= dx)) / dx;
		normal_0.y = (f(aux_0.y += dy) - f(aux_0.y -= dy)) / dy;
		normal_0.z = (f(aux_0.z += dz) - f(aux_0.z -= dz)) / dz;
		pd_int0 = normal_0.produto_interno(observer);

		aux_1 = grid.p[5];
		normal_1.x = (f(aux_1.x += dx) - f(aux_1.x -= dx)) / dx;
		normal_1.y = (f(aux_1.y += dy) - f(aux_1.y -= dy)) / dy;
		normal_1.z = (f(aux_1.z += dz) - f(aux_1.z -= dz)) / dz;
		pd_int1 = normal_1.produto_interno(observer);

		normal_list[9] = LinearInterp(grid.p[1], grid.p[5], pd_int0, pd_int1, vertlist[9]);
	}
	if (edgeTable[cubeindex] & 1024)
	{
		float pd_int0, pd_int1;
		Ponto3D normal_0, normal_1, aux_0, aux_1;

		vertlist[10] =
			VertexInterp(isolevel, grid.p[2], grid.p[6], grid.val[2], grid.val[6]);

		aux_0 = grid.p[2];

		normal_0.x = (f(aux_0.x += dx) - f(aux_0.x -= dx)) / dx;
		normal_0.y = (f(aux_0.y += dy) - f(aux_0.y -= dy)) / dy;
		normal_0.z = (f(aux_0.z += dz) - f(aux_0.z -= dz)) / dz;
		pd_int0 = normal_0.produto_interno(observer);

		aux_1 = grid.p[6];
		normal_1.x = (f(aux_1.x += dx) - f(aux_1.x -= dx)) / dx;
		normal_1.y = (f(aux_1.y += dy) - f(aux_1.y -= dy)) / dy;
		normal_1.z = (f(aux_1.z += dz) - f(aux_1.z -= dz)) / dz;
		pd_int1 = normal_1.produto_interno(observer);

		normal_list[10] = LinearInterp(grid.p[2], grid.p[6], pd_int0, pd_int1, vertlist[10]);
	}
	if (edgeTable[cubeindex] & 2048)
	{
		float pd_int0, pd_int1;
		Ponto3D normal_0, normal_1, aux_0, aux_1;

		vertlist[11] =
			VertexInterp(isolevel, grid.p[3], grid.p[7], grid.val[3], grid.val[7]);

		aux_0 = grid.p[3];

		normal_0.x = (f(aux_0.x += dx) - f(aux_0.x -= dx)) / dx;
		normal_0.y = (f(aux_0.y += dy) - f(aux_0.y -= dy)) / dy;
		normal_0.z = (f(aux_0.z += dz) - f(aux_0.z -= dz)) / dz;
		pd_int0 = normal_0.produto_interno(observer);

		aux_1 = grid.p[7];
		normal_1.x = (f(aux_1.x += dx) - f(aux_1.x -= dx)) / dx;
		normal_1.y = (f(aux_1.y += dy) - f(aux_1.y -= dy)) / dy;
		normal_1.z = (f(aux_1.z += dz) - f(aux_1.z -= dz)) / dz;
		pd_int1 = normal_1.produto_interno(observer);

		normal_list[11] = LinearInterp(grid.p[3], grid.p[7], pd_int0, pd_int1, vertlist[11]);
	}

	/* Create the triangle */
	ntriang = 0;
	for (i = 0; triTable[cubeindex][i] != -1; i += 3)
	{
		float normal1, normal2, normal3;
		normal1 = normal_list[triTable[cubeindex][i]];
		normal2 = normal_list[triTable[cubeindex][i + 1]];
		normal3 = normal_list[triTable[cubeindex][i + 2]];
		if ((normal1 * normal2 < 0) || (normal1 * normal3 < 0) || (normal2 * normal3 < 0))
		{
			glColor3f(0, 0, 1);
			glBegin(GL_LINE_LOOP);
			glVertex3f(vertlist[triTable[cubeindex][i]].x, vertlist[triTable[cubeindex][i]].y, vertlist[triTable[cubeindex][i]].z);
			glVertex3f(vertlist[triTable[cubeindex][i + 1]].x, vertlist[triTable[cubeindex][i + 1]].y, vertlist[triTable[cubeindex][i + 1]].z);
			glVertex3f(vertlist[triTable[cubeindex][i + 2]].x, vertlist[triTable[cubeindex][i + 2]].y, vertlist[triTable[cubeindex][i + 2]].z);
			glEnd();
			ntriang++;
		}
	}

	return (ntriang);
}

/*
   Linearly interpolate the position where an isosurface cuts
   an edge between two vertices, each with their own scalar value
*/
Ponto3D Implicito::VertexInterp(float isolevel, Ponto3D p1, Ponto3D p2, float valp1, float valp2)
{
	double mu;
	//Ponto3D p;

	if (abs(isolevel - valp1) < 0.00001)
		return (p1);
	if (abs(isolevel - valp2) < 0.00001)
		return (p2);
	if (abs(valp1 - valp2) < 0.00001)
		return (p1);
	mu = (isolevel - valp1) / (valp2 - valp1);

	Ponto3D p(p1.x + mu * (p2.x - p1.x), p1.y + mu * (p2.y - p1.y), p1.z + mu * (p2.z - p1.z));
	//p.x = p1.x + mu * (p2.x - p1.x);
	//p.y = p1.y + mu * (p2.y - p1.y);
	//p.z = p1.z + mu * (p2.z - p1.z);

	return (p);
}

float Implicito::LinearInterp(Ponto3D p1, Ponto3D p2, float val1, float val2, Ponto3D p3)
{
	if ((p1.x - p2.x) != 0)
		return (val1 * (p2.x - p3.x) + val2 * (p3.x - p1.x)) / (p2.x - p1.x);
	if ((p1.y - p2.y) != 0)
		return (val1 * (p2.y - p3.y) + val2 * (p3.y - p1.y)) / (p2.y - p1.y);
	if ((p1.z - p2.z) != 0)
		return (val1 * (p2.z - p3.z) + val2 * (p3.z - p1.z)) / (p2.z - p1.z);
}