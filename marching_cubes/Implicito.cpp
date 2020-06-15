#include "pch.h"
#include "Implicito.h"
#include <glut.h>


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
void Implicito::visualiza_implicito() 
{
	float v[8][3];
	float x, y, z;
	float dx, dy, dz;
	dx = (xmax - xmin) / n;
	dy = (ymax - ymin) / n;
	dz = (zmax - zmin) / n;

	x = xmin;
	for (int i = 0; i < n; i++) {
		y = ymin;
		for (int j = 0; j < n; j++) {
			z = zmin;
			for (int k = 0; k < n; k++) {
				v[0][0] = x; v[1][0] = x+dx; v[2][0] = x;    v[3][0] = x+dx;
				v[0][1] = y; v[1][1] = y;    v[2][1] = y+dy; v[3][1] = y+dy;
				v[0][2] = z; v[1][2] = z;    v[2][2] = z;    v[3][2] = z;

				v[4][0] = x;    v[5][0] = x+dx; v[6][0] = x;    v[7][0] = x + dx;
				v[4][1] = y;    v[5][1] = y;    v[6][1] = y+dy; v[7][1] = y + dy;
				v[4][2] = z+dz; v[5][2] = z+dz; v[6][2] = z+dz; v[7][2] = z+dz;
				tetraedro(v[0], v[1], v[3], v[7]); 
				tetraedro(v[0], v[1], v[5], v[7]);
				tetraedro(v[0], v[2], v[3], v[7]);
				tetraedro(v[0], v[2], v[6], v[7]);
				tetraedro(v[0], v[4], v[5], v[7]);
				tetraedro(v[0], v[4], v[6], v[7]);
				z += dz;
			}
			y += dy;
		}
		x += dx;
	}
}

void Implicito::cubes(float *v, float dx, float dy, float dz)
{
	int ind = 0;
	int e0, e1, e2, e3;
	float pCritico; 
	float v1[3], v2[3] , v3[3] , v4[3], v5[3], v6[3], v7[3], v8[3];
	float *vList[8];
	
	for(int i = 0; i < 3; i++)
	{
		v1[i] = v[i];
		if (i == 0)
		{
			v2[i] = v[i] + dx;
			v3[i] = v[i] + dx;
			v4[i] = v[i];
			v5[i] = v[i];
			v6[i] = v[i] + dx;
			v7[i] = v[i] + dx;
			v8[i] = v[i];
		}
		else if (i == 1)
		{
			v2[i] = v[i];
			v3[i] = v[i];
			v4[i] = v[i];
			v5[i] = v[i];
			v6[i] = v[i];
			v7[i] = v[i];
			v8[i] = v[i];
		}
		else
		{
			v2[i] = v[i];
			v3[i] = v[i];
			v4[i] = v[i];
			v5[i] = v[i];
			v6[i] = v[i];
			v7[i] = v[i];
			v8[i] = v[i];
		}
	}

	float s[4];
	s[0] = f(x   , y   );
	s[1] = f(x+dx, y   );
	s[2] = f(x+dx, y + dy);
	s[3] = f(x   , y + dy);
	pCritico = ((s[0] * s[3]) - (s[2] * s[1]))/(s[0] - s[1] - s[2] + s[3]);

	ind =  (s[0] < 0) ? 1 : 0;
	ind += (s[1] < 0) ? 2 : 0;
	ind += (s[2] < 0) ? 4 : 0;
	ind += (s[3] < 0) ? 8 : 0;
}