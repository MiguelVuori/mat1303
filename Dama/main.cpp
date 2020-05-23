#include "Tabuleiro.h"
#include <GL/glut.h>
#include "Window.h"
#include <stdlib.h>
#include <string.h>

Window w(-0.5, 5.5, -0.5, 5.5, 800, 800);
Tabuleiro tabuleiro;

bool peca_bool = false, vez = false, killing_spree = false, menu_var = true;
float mouse_x, mouse_y;
int cor_peca = 2;
int peca_x0, peca_y0;
char color;

void menu()
{
    int len, i, width;
    unsigned char palavra1[] = "MENU", palavra2[] = "PLAYER VS PLAYER", palavra3[] = "PLAYER VS COM";
    glColor3f(1, 1, 1);
    width = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, palavra1);
    glRasterPos2f(2.5 - width / 200.0, 3.5);
    len = strlen((char *)palavra1);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, palavra1[i]);
    }
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(0.25, 1.0);
        glVertex2f(0.25, 2.0);
        glVertex2f(1.25, 2.0);
        glVertex2f(1.25, 1.0);
    glEnd();
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
        glVertex2f(1.25, 2.0);
        glVertex2f(1.25, 1.0);
        glVertex2f(2.25, 1.0);
        glVertex2f(2.25, 2.0);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(2.75, 1.0);
        glVertex2f(2.75, 2.0);
        glVertex2f(3.75, 2.0);
        glVertex2f(3.75, 1.0);
    glEnd();
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
        glVertex2f(3.75, 1.0);
        glVertex2f(3.75, 2.0);
        glVertex2f(4.75, 2.0);
        glVertex2f(4.75, 1.0);
    glEnd();
    glColor3f(0, 0, 0);
    width = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, palavra2);
    cout << width << "\n";
    glRasterPos2f(1.5 - width / 200.0, 1.5);
    len = strlen((char *)palavra2);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, palavra2[i]);
    }
    width = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, palavra3);
    cout << width << "\n";
    glRasterPos2f(3.85 - width / 200.0, 1.5);
    len = strlen((char *)palavra3);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, palavra3[i]);
    }
}

void peca()
{
    float peca_x, peca_y;
    peca_x = w.getl() + mouse_x / (w.getDIMX() - 1) * (w.getr() - w.getl());
    peca_y = w.gett() + mouse_y / (w.getDIMY() - 1) * (w.getb() - w.gett());
    if (cor_peca == 0)
        glColor3f(1, 0, 0);
    else
        glColor3f(1, 1, 0);

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
    if (menu_var == true)
    {
        menu();
    }
    else
    {
        tabuleiro.mostra();
        if (peca_bool == true)
        {
            peca();
        }
    }

    glFlush();
    glutSwapBuffers();
}

void Botao_mouse(int botao, int state, int x, int y)
{
    int peca_x, peca_y;
    mouse_x = x;
    mouse_y = y;
    float clique_x, clique_y;
    clique_x = w.getl() + mouse_x / (w.getDIMX() - 1) * (w.getr() - w.getl());
    clique_y = w.gett() + mouse_y / (w.getDIMY() - 1) * (w.getb() - w.gett());

    if (botao == GLUT_LEFT_BUTTON)
    {
        if (menu_var == false)
        {
            peca_x = w.getl() + mouse_x / (w.getDIMX() - 1) * (w.getr() - w.getl());
            peca_y = w.gett() + mouse_y / (w.getDIMY() - 1) * (w.getb() - w.gett());

            /* clicou com o mouse */
            if (state == GLUT_DOWN)
            {
                if (peca_x <= 4 && peca_y <= 4 && peca_x >= 0 && peca_y >= 0)
                {
                    if (killing_spree == true && peca_x0 == peca_x && peca_y == peca_y0)
                    {
                        cout << "peguei!";
                        cor_peca = tabuleiro.getColor(peca_y, peca_x);
                        if (cor_peca == 0 && vez == false)
                        {
                            tabuleiro.setColor(peca_y, peca_x, 2);
                            peca_bool = true;
                        }
                        else if (cor_peca == 1 && vez == true)
                        {
                            tabuleiro.setColor(peca_y, peca_x, 2);
                            peca_bool = true;
                        }
                        cout << "botao esquerdo pressionado" << x << ", " << y << endl;
                        peca_x0 = peca_x;
                        peca_y0 = peca_y;
                    }
                    else if (!killing_spree)
                    {
                        cout << "peguei!";
                        cor_peca = tabuleiro.getColor(peca_y, peca_x);
                        if (cor_peca == 0 && vez == false)
                        {
                            tabuleiro.setColor(peca_y, peca_x, 2);
                            peca_bool = true;
                        }
                        else if (cor_peca == 1 && vez == true)
                        {
                            tabuleiro.setColor(peca_y, peca_x, 2);
                            peca_bool = true;
                        }
                        cout << "botao esquerdo pressionado" << x << ", " << y << endl;
                        peca_x0 = peca_x;
                        peca_y0 = peca_y;
                    }
                }
                //cout << "botao esquerdo pressionado" << x << ", " << y << endl;
                //peca_x0 = peca_x;
                //peca_y0 = peca_y;
            }
            else
            {
                /* soltou a peca */
                if (state == GLUT_UP && peca_bool == true)
                {
                    /* soltou em um espaco vazio */
                    if (tabuleiro.getColor(peca_y, peca_x) == 2)
                    {
                        int dif_peca_x, dif_peca_y;
                        dif_peca_x = peca_x - peca_x0;
                        dif_peca_y = peca_y - peca_y0;

                        /* caso em que so se movimenta a peca */
                        if (fabs(dif_peca_x) <= 1 && fabs(dif_peca_y) <= 1)
                        {
                            tabuleiro.setColor(peca_y, peca_x, cor_peca);
                            peca_bool = false;
                            if (!(peca_x == peca_x0 && peca_y == peca_y0))
                                vez = !vez;
                            glutPostRedisplay();
                            killing_spree = false;

                        } /* caso em que se come uma peca */
                        else if ((fabs(dif_peca_y) + fabs(dif_peca_x) == 2) or (fabs(dif_peca_y) + fabs(dif_peca_x) == 4))
                        {
                            int comeu = 0;

                            switch (dif_peca_x + 3 * dif_peca_y)
                            {
                            case 2:
                                if (tabuleiro.getColor(peca_y, peca_x - 1) != 2 && cor_peca != tabuleiro.getColor(peca_y, peca_x - 1))
                                {
                                    tabuleiro.setColor(peca_y, peca_x - 1, 2);
                                    comeu = !comeu;
                                }
                                break;
                            case -4:
                                if (tabuleiro.getColor(peca_y + 1, peca_x - 1) != 2 && cor_peca != tabuleiro.getColor(peca_y + 1, peca_x - 1))
                                {
                                    tabuleiro.setColor(peca_y + 1, peca_x - 1, 2);
                                    comeu = !comeu;
                                }
                                break;
                            case -6:
                                if (tabuleiro.getColor(peca_y + 1, peca_x) != 2 && cor_peca != tabuleiro.getColor(peca_y + 1, peca_x))
                                {
                                    tabuleiro.setColor(peca_y + 1, peca_x, 2);
                                    comeu = !comeu;
                                }
                                break;
                            case -8:
                                if (tabuleiro.getColor(peca_y + 1, peca_x + 1) != 2 && cor_peca != tabuleiro.getColor(peca_y + 1, peca_x + 1))
                                {
                                    tabuleiro.setColor(peca_y + 1, peca_x + 1, 2);
                                    comeu = !comeu;
                                }
                                break;
                            case -2:
                                if (tabuleiro.getColor(peca_y, peca_x + 1) != 2 && cor_peca != tabuleiro.getColor(peca_y, peca_x + 1))
                                {
                                    tabuleiro.setColor(peca_y, peca_x + 1, 2);
                                    comeu = !comeu;
                                }
                                break;
                            case 4:
                                if (tabuleiro.getColor(peca_y - 1, peca_x + 1) != 2 && cor_peca != tabuleiro.getColor(peca_y - 1, peca_x + 1))
                                {
                                    tabuleiro.setColor(peca_y - 1, peca_x + 1, 2);
                                    comeu = !comeu;
                                }
                                break;
                            case 6:
                                if (tabuleiro.getColor(peca_y - 1, peca_x) != 2 && cor_peca != tabuleiro.getColor(peca_y - 1, peca_x))
                                {
                                    tabuleiro.setColor(peca_y - 1, peca_x, 2);
                                    comeu = !comeu;
                                }
                                break;
                            case 8:
                                if (tabuleiro.getColor(peca_y - 1, peca_x - 1) != 2 && cor_peca != tabuleiro.getColor(peca_y - 1, peca_x - 1))
                                {
                                    tabuleiro.setColor(peca_y - 1, peca_x - 1, 2);
                                    comeu = !comeu;
                                }
                                break;
                            }
                            if (comeu)
                            {
                                if (cor_peca)
                                {
                                    tabuleiro.set_num_vermelhas(tabuleiro.get_num_vermelhas() - 1);
                                }
                                else
                                {
                                    tabuleiro.set_num_amarelas(tabuleiro.get_num_amarelas() - 1);
                                }

                                /* nao existe pecas de uma cor. Jogo acabou */
                                if (tabuleiro.get_num_vermelhas() == 0 or tabuleiro.get_num_amarelas() == 0)
                                {
                                    exit(0);
                                }
                                tabuleiro.setColor(peca_y, peca_x, cor_peca);
                                peca_x0 = peca_x;
                                peca_y0 = peca_y;
                                peca_bool = false;
                                killing_spree = true;
                                glutPostRedisplay();
                            }
                            else
                            {
                                tabuleiro.setColor(peca_y0, peca_x0, cor_peca);
                                peca_bool = false;
                                glutPostRedisplay();
                            }
                        } /* caso em que se fez um movimento invalido */
                        else
                        {
                            tabuleiro.setColor(peca_y0, peca_x0, cor_peca);
                            peca_bool = false;
                            glutPostRedisplay();
                        }
                    }
                    else
                    {
                        tabuleiro.setColor(peca_y0, peca_x0, cor_peca);
                    }
                    peca_bool = false;
                    glutPostRedisplay();
                }
            }
        }
        if (menu_var == true)
        {
            if (clique_y >= 1.0 && clique_y <= 2.0){
                if ((clique_x >= 0.25 && clique_x < 1.25) || (clique_x >= 2.75 && clique_x < 3.75))
                {
                    color = 'v';
                    menu_var = false;
                    Tabuleiro tab(color);
                    tabuleiro = tab;
                    glutPostRedisplay();
                }
                else if((clique_x > 1.25 && clique_x <= 2.25) || (clique_x > 3.75 && clique_x <= 4.75))
                {
                    color = 'a';
                    menu_var = false;
                    Tabuleiro tab(color);
                    tabuleiro = tab;
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