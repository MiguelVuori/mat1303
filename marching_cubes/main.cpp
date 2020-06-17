#include "Implicito.h"
#include <GL/glut.h>



Implicito funcao(-2.5, -2.5, -2.5, 2.3, 2.3, 2.3, 20);

void config()
{
    glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
//	glRotatef(90, 0, 0, 1);
//	glRotatef(45, 0, 1, 0);
//	glRotatef(135, 0, 0, 1);
//	glScalef(scale, scale, scale);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5, -200,200);
//	gluPerspective(90, 1, 0.1, 20);
//	gluPerspective(30, 1, 0.01, 5);
	gluLookAt(5, 5, 0, 0, 0, 0, 0, 0, 1);
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
	funcao.visualiza_implicito(2, 2, 2);
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Curva silhueta");
    config();
    glutDisplayFunc(display);
    glutMainLoop();
}