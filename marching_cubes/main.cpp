#include "Implicito.h"
#include <GL/glut.h>



Implicito funcao(-1.5, -1.5, -1.5, 1.5, 1.5, 1.5, 5);

void config()
{
    glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(90, 0, 0, 1);
	glRotatef(45, 0, 1, 0);
	glRotatef(135, 0, 0, 1);
//	glScalef(scale, scale, scale);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-2, 2, -2, 2, -200,200);
//	gluPerspective(90, 1, 0.1, 20);
//	gluPerspective(30, 1, 0.01, 5);
//	gluLookAt(2, 2, 2, -1, -1, -1, 0, 0, 1);
}


void eixos()
{
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1);
	glEnd();
}

void display()
{
	glClearColor(1.0, 1.0, 1.0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	eixos();
    funcao.visualiza_implicito();
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Curva silhueta");
    config();
    glutDisplayFunc(display);
    glutMainLoop();
}