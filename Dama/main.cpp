#include "Tabuleiro.h"
#include <GL/glut.h>
#include "Window.h"

Window w(-1, 6, -1, 6, 800, 800);
Tabuleiro tabuleiro;


bool peca_bool = false;
float mouse_x, mouse_y;
int cor_peca = 2;
float peca_x0,peca_y0;

void peca()
{
    float peca_x, peca_y;
    peca_x = w.getl() + mouse_x / (w.getDIMX() - 1) * (w.getr() - w.getl());
    peca_y = w.gett() + mouse_y / (w.getDIMY() - 1) * (w.getb() - w.gett());
    if(cor_peca == 0)
        glColor3f(1, 0, 0);
    else
        glColor3f(0, 0, 1);
    
    glEnable(GL_POINT_SMOOTH);
    glPointSize(50.0);
    glBegin(GL_POINTS);
        glVertex2f(peca_x, peca_y);
    glEnd();
}

void config()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(w.getl(), w.getr(), w.getb(), w.gett());
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    tabuleiro.mostra();
    if (peca_bool == true)
    {
        peca();
    }
    glFlush();
    glutSwapBuffers();
}

void Botao_mouse(int botao, int state, int x, int y)
{
    int peca_x, peca_y;
    mouse_x = x;
    mouse_y = y;
    if (botao == GLUT_LEFT_BUTTON)
    {
        peca_x = w.getl() + mouse_x / (w.getDIMX() - 1) * (w.getr() - w.getl());
        peca_y = w.gett() + mouse_y / (w.getDIMY() - 1) * (w.getb() - w.gett());
        if (state == GLUT_DOWN)
        {
            cor_peca = tabuleiro.getColor(peca_y, peca_x);
            tabuleiro.setColor(peca_y, peca_x, 2);
            peca_bool = true;
            cout << "botao esquerdo pressionado" << x << ", " << y << endl;
            peca_x0 = peca_x;
            peca_y0 = peca_y;
        }
        else
        {
            if (state == GLUT_UP)
            {
                if (tabuleiro.getColor(peca_y, peca_x) == 2)
                {
                    // peca_x = w.getl() + mouse_x / (w.getDIMX() - 1) * (w.getr() - w.getl());
                    // peca_y = w.gett() + mouse_y / (w.getDIMY() - 1) * (w.getb() - w.gett());
                    tabuleiro.setColor(peca_y, peca_x, cor_peca);
                    peca_bool = false;
                    glutPostRedisplay();
                }
                else
                {
                    tabuleiro.setColor(peca_y0, peca_x0, cor_peca);
                    peca_bool = false;
                    glutPostRedisplay();
                }
            }

        }
    }
}

void Botao_mov_mouse(int x, int y)
{
    cout << "Botao Movimento " << x << ", " << y << endl;
    mouse_x = x;
    mouse_y = y;
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(w.getDIMX(), w.getDIMY());
    glutCreateWindow("Damma");
    config();
    glutMouseFunc(Botao_mouse);
    glutMotionFunc(Botao_mov_mouse);
    glutDisplayFunc(display);
    glutMainLoop();
}