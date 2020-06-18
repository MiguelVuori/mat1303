#include "Implicito.h"
#include <GL/glut.h>
#include <chrono>
#include <thread>
#include <cmath>
#include <iostream>


int DIMX = 800;
int DIMY = 800;

float theta = 135;
float phi = 45;
float gama = 90;

float scale = 1.0;
int xi, yi, xf, yf;

Implicito funcao(-2.5, -2.5, -2.5, 2.3, 2.3, 2.3, 20);
vector<Triangulo> triangles;
bool states[2] = {false,false};

void config()
{
    glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(gama, 0, 0, 1);
	glRotatef(phi, 0, 1, 0);
	glRotatef(theta, 0, 0, 1);
	glScalef(scale, scale, scale);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5, -200,200);
//	gluPerspective(90, 1, 0.1, 20);
//	gluPerspective(30, 1, 0.01, 5);
	gluLookAt(5, 10, 10, 0, 0, 0, -2, -2, 3);
	triangles = funcao.calcula_triangles(5, 5, 10, true);
}


void eixos()
{
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(5, 0, 0);
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 5, 0);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 5);
	glEnd();
}

void display()
{
	GLfloat model[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, model);
	glClearColor(1.0, 1.0, 1.0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	eixos();
	// funcao.visualiza_implicito(model[2], model[6], model[10]);
	if(states[0] == true) funcao.showtriangles(triangles);
	if(states[1] == true) funcao.MarchingLines(triangles);
	glutSwapBuffers();
}

void Botao_mouse(int botao, int state, int x, int y)
{
	if (botao == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN) {
			xi = x;
			yi = y;
			cout << "botao esquerdo pressionado" << x << ", " << y << endl;
		}
		else
			if (state == GLUT_UP) {
				theta = theta + (x - xi);
				phi = phi - (y - yi);
				xf = x;
				yf = y;
				config();
				glutPostRedisplay();
				cout << "botao esquerdo Liberado " << endl;
			}
	}
	if (botao == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN) {

			cout << "botao direito pressionado" << endl;
		}
		else
			if (state == GLUT_UP)
				cout << "botao direito Liberado" << endl;
	}
}

void Botao_mov_mouse(int x, int y)
{
	//cout << "Botao Movimento " << x << ", " << y << endl;
	xf = x;
	yf = y;
	theta = theta + (xf - xi);
	phi = phi - (yf - yi);
	config();
	display();
	theta = theta - (xf - xi);
	phi = phi + (yf - yi);
}

void Teclado(unsigned char key, int x, int y)
{

    if ((key == 'C') || (key == 'c'))
    {
		states[0] = !states[0];
		glutPostRedisplay();
    }
	if ((key == 'L') || (key == 'l'))
    {
		states[1] = !states[1];
		glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Curva silhueta");
	glutMouseFunc(Botao_mouse);
    config();
    glutDisplayFunc(display);
	glutKeyboardFunc(Teclado);
	glutMotionFunc(Botao_mov_mouse);
    glutMainLoop();
}