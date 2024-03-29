#include "Tabuleiro.h"
#include <GL/glut.h>
#include "Window.h"
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <thread>

Window w(-0.5, 5.5, -0.5, 5.5, 800, 800);
Tabuleiro tabuleiro;

bool peca_bool = false, vez = false, killing_spree = false, menu_var = true, acabou = false, vs_com = false;
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
    glRasterPos2f(1.5 - width / 200.0, 1.5);
    len = strlen((char *)palavra2);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, palavra2[i]);
    }
    width = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, palavra3);
    glRasterPos2f(3.85 - width / 200.0, 1.5);
    len = strlen((char *)palavra3);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, palavra3[i]);
    }
}

void COM()
{
    this_thread::sleep_for(std::chrono::milliseconds(100));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (color == 'v')
            {
                if (tabuleiro.getColor(i, j) == 1 || tabuleiro.getColor(i, j) == 4)
                {
                    bool andou = false;
                    int corpeca = tabuleiro.getColor(i, j);
                    for (int m = -1; m < 2; m++)
                    {
                        for (int n = -1; n < 2; n++)
                        {
                            if (i + m < 0 || i + m > 5)
                                break;
                            else if (tabuleiro.getColor(i + m, j + n) == 2)
                            {
                                tabuleiro.setColor(i, j, 2);
                                if (i + m == 0)
                                    tabuleiro.setColor(i + m, j + n, 4);
                                else
                                    tabuleiro.setColor(i + m, j + n, corpeca);
                                i = 5;
                                j = 5;
                                m = 2;
                                n = 2;
                                andou = true;
                            }
                        }
                    }

                    if (andou == false)
                    {
                        for (int m = -2; m < 3; m += 2)
                        {
                            for (int n = -2; n < 3; n += 2)
                            {
                                if (i + m < 0 || i + m > 5)
                                    break;
                                else if (tabuleiro.getColor(i + m, j + n) == 2)
                                {
                                    int aux1, aux2;
                                    aux1 = m;
                                    aux2 = n;
                                    if (aux1 != 0)
                                    {
                                        if (n > 0)
                                            aux1--;
                                        else
                                            aux1++;
                                    }
                                    if (aux2 != 0)
                                    {
                                        if (aux2 > 0)
                                            aux2--;
                                        else
                                            aux2++;
                                    }
                                    if (tabuleiro.getColor(i + aux1, j + aux2) != corpeca)
                                    {
                                        tabuleiro.setColor(i, j, 2);
                                        if (i + m == 0)
                                            tabuleiro.setColor(i + m, j + n, 4);
                                        else
                                            tabuleiro.setColor(i + m, j + n, corpeca);
                                        if (n != 0)
                                        {
                                            if (n > 0)
                                                n--;
                                            else
                                                n++;
                                        }
                                        if (m != 0)
                                        {
                                            if (m > 0)
                                                m--;
                                            else
                                                m++;
                                            tabuleiro.setColor(i + m, j + n, 2);
                                            tabuleiro.set_num_vermelhas(tabuleiro.get_num_vermelhas() - 1);
                                            i = 5;
                                            j = 5;
                                            m = 4;
                                            n = 4;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                bool andou = false;
                int corpeca = tabuleiro.getColor(i, j);
                if (tabuleiro.getColor(i, j) == 0 || tabuleiro.getColor(i, j) == 3)
                {
                    for (int m = -1; m < 2; m++)
                    {
                        for (int n = -1; n < 2; n++)
                        {
                            if (i + m < 0 || i + m > 5)
                                break;
                            else if (tabuleiro.getColor(i + m, j + n) == 2)
                            {
                                tabuleiro.setColor(i, j, 2);
                                if (i + m == 0)
                                    tabuleiro.setColor(i + m, j + n, 3);
                                else
                                    tabuleiro.setColor(i + m, j + n, corpeca);
                                i = 5;
                                j = 5;
                                m = 2;
                                n = 2;
                                andou = true;
                            }
                        }
                    }

                    if (andou == false)
                    {
                        for (int m = -2; m < 3; m += 2)
                        {
                            for (int n = -2; n < 3; n += 2)
                            {
                                if (i + m < 0 || i + m > 5)
                                    n = 2;
                                else if (tabuleiro.getColor(i + m, j + n) == 2)
                                {
                                    int aux1, aux2;
                                    aux1 = m;
                                    aux2 = n;
                                    if (aux1 != 0)
                                    {
                                        if (n > 0)
                                            aux1--;
                                        else
                                            aux1++;
                                    }
                                    if (aux2 != 0)
                                    {
                                        if (aux2 > 0)
                                            aux2--;
                                        else
                                            aux2++;
                                    }
                                    if (tabuleiro.getColor(i + aux1, j + aux2) != corpeca)
                                    {
                                        tabuleiro.setColor(i, j, 2);
                                        if (i + m == 0)
                                            tabuleiro.setColor(i + m, j + n, 3);
                                        else
                                            tabuleiro.setColor(i + m, j + n, corpeca);
                                        if (n != 0)
                                        {
                                            if (n > 0)
                                                n--;
                                            else
                                                n++;
                                        }
                                        if (m != 0)
                                        {
                                            if (m > 0)
                                                m--;
                                            else
                                                m++;
                                        }
                                        tabuleiro.setColor(i + m, j + n, 2);
                                        tabuleiro.set_num_amarelas(tabuleiro.get_num_amarelas() - 1);
                                        i = 5;
                                        j = 5;
                                        m = 2;
                                        n = 2;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void peca()
{
    float peca_x, peca_y;
    peca_x = w.getl() + mouse_x / (w.getDIMX() - 1) * (w.getr() - w.getl());
    peca_y = w.gett() + mouse_y / (w.getDIMY() - 1) * (w.getb() - w.gett());
    if (cor_peca == 0)
        glColor3f(1, 0, 0);
    else if (cor_peca == 1)
        glColor3f(1, 1, 0);
    else if (cor_peca == 3)
        glColor3f(0.5, 0, 0);
    else if (cor_peca == 4)
        glColor3f(0.5, 0.5, 0);

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

void volta_origem()
{
    tabuleiro.setColor(peca_y0, peca_x0, cor_peca);
    peca_bool = false;
    glutPostRedisplay();
}

void Botao_mouse(int botao, int state, int x, int y)
{
    int peca_x, peca_y;
    float clique_x, clique_y;
    mouse_x = x;
    mouse_y = y;
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
                //esse if é pra impedir que você puxe a peça clicando fora do tabuleiro <------ se der erro comenta esse if!!!!!!!
                if (clique_x >= 0.0 && clique_x <= 5.0 && clique_y >= 0.0 && clique_y <= 5.0)
                {
                    if (peca_x <= 4 && peca_y <= 4 && peca_x >= 0 && peca_y >= 0)
                    {
                        if (killing_spree == true && peca_x0 == peca_x && peca_y == peca_y0)
                        {
                            cor_peca = tabuleiro.getColor(peca_y, peca_x);
                            if ((cor_peca == 0 || cor_peca == 3) && vez == false)
                            {
                                tabuleiro.setColor(peca_y, peca_x, 2);
                                peca_bool = true;
                            }
                            else if ((cor_peca == 1 || cor_peca == 4) && vez == true)
                            {
                                tabuleiro.setColor(peca_y, peca_x, 2);
                                peca_bool = true;
                            }
                            peca_x0 = peca_x;
                            peca_y0 = peca_y;
                        }
                        else if (!killing_spree)
                        {

                            cor_peca = tabuleiro.getColor(peca_y, peca_x);
                            if ((cor_peca == 0 || cor_peca == 3) && vez == false)
                            {
                                tabuleiro.setColor(peca_y, peca_x, 2);
                                peca_bool = true;
                            }
                            else if ((cor_peca == 1 || cor_peca == 4) && vez == true)
                            {
                                tabuleiro.setColor(peca_y, peca_x, 2);
                                peca_bool = true;
                            }
                            peca_x0 = peca_x;
                            peca_y0 = peca_y;
                        }
                    }
                }
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

                        /* movimentacao de peca comum */
                        if (cor_peca == 0 or cor_peca == 1)
                        {
                            /* caso em que so se movimenta a peca */
                            if (fabs(dif_peca_x) <= 1 && fabs(dif_peca_y) <= 1 && killing_spree == false)
                            {

                                /* testo se vira rainha */
                                if ((color == 'a') && ((cor_peca == 1 && peca_y == 4) || (cor_peca == 0 && peca_y == 0)))
                                {

                                    tabuleiro.setColor(peca_y, peca_x, cor_peca + 3);
                                }
                                else if ((color == 'v') && ((cor_peca == 1 && peca_y == 0) || (cor_peca == 0 && peca_y == 4)))
                                {
                                    tabuleiro.setColor(peca_y, peca_x, cor_peca + 3);
                                }
                                else
                                {
                                    tabuleiro.setColor(peca_y, peca_x, cor_peca);
                                }

                                peca_bool = false;
                                if (!(peca_x == peca_x0 && peca_y == peca_y0))
                                {
                                    if (vs_com == true)
                                    {
                                        glutPostRedisplay();
                                        COM();
                                    }
                                    else
                                    {
                                        vez = !vez;
                                        glutPostRedisplay();
                                    }
                                }
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
                                    if (tabuleiro.get_num_vermelhas() == 0 || tabuleiro.get_num_amarelas() == 0)
                                    {
                                        if (vez == false)
                                            cout << "Vermelho vence!\n";
                                        else
                                            cout << "Amarelo vence!\n";

                                        exit(0);
                                    }
                                    tabuleiro.setColor(peca_y, peca_x, cor_peca);
                                    peca_x0 = peca_x;
                                    peca_y0 = peca_y;
                                    peca_bool = false;
                                    killing_spree = true;

                                    if ((color == 'a') && ((cor_peca == 1 && peca_y == 4) || (cor_peca == 0 && peca_y == 0)))
                                    {

                                        tabuleiro.setColor(peca_y, peca_x, cor_peca + 3);
                                    }
                                    else if ((color == 'v') && ((cor_peca == 1 && peca_y == 0) || (cor_peca == 0 && peca_y == 4)))
                                    {
                                        tabuleiro.setColor(peca_y, peca_x, cor_peca + 3);
                                    }

                                    glutPostRedisplay();
                                }
                                else
                                {
                                    tabuleiro.setColor(peca_y0, peca_x0, cor_peca);
                                    peca_bool = false;
                                    glutPostRedisplay();
                                }
                            }
                            else
                            {
                                volta_origem();
                            }
                        }
                        //trata dos casos da peça rainha
                        else if ((cor_peca == 3 || cor_peca == 4) && ((fabs(dif_peca_x) == fabs(dif_peca_y)) || (dif_peca_x == 0 && dif_peca_y <= 4) || (dif_peca_y == 0 && dif_peca_x <= 4)))
                        {
                            int localizacao;
                            int comeu = 0;

                            if (dif_peca_x > 0)
                            {
                                if (dif_peca_y > 0)
                                {
                                    localizacao = 8;
                                }
                                else if (dif_peca_y < 0)
                                {
                                    localizacao = 2;
                                }
                                else
                                {
                                    localizacao = 1;
                                }
                            }
                            else if (dif_peca_x < 0)
                            {
                                if (dif_peca_y > 0)
                                {
                                    localizacao = 6;
                                }
                                else if (dif_peca_y < 0)
                                {
                                    localizacao = 4;
                                }
                                else
                                {
                                    localizacao = 5;
                                }
                            }
                            else
                            {
                                if (dif_peca_y > 0)
                                {
                                    localizacao = 7;
                                }
                                else if (dif_peca_y < 0)
                                {
                                    localizacao = 3;
                                }
                                else
                                {
                                    localizacao = 9;
                                }
                            }

                            if (peca_x <= 4 && peca_y <= 4 && peca_x >= 0 && peca_y >= 0)
                            {
                                int comida_valida = 0;
                                int local_de_comida;

                                switch (localizacao)
                                {
                                case 1:

                                    for (int i = 1; i < fabs(dif_peca_x); i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0, peca_x0 + i);

                                        if (cor_no_meio != cor_peca && cor_no_meio != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }
                                    }
                                    if (comida_valida == 0 && killing_spree == false)
                                    {
                                        tabuleiro.setColor(peca_y, peca_x, cor_peca);
                                        peca_bool = false;
                                        if (!(peca_x == peca_x0 && peca_y == peca_y0))
                                        {
                                            if (vs_com == true)
                                            {
                                                glutPostRedisplay();
                                                COM();
                                            }
                                            else
                                            {
                                                vez = !vez;
                                                glutPostRedisplay();
                                            }
                                        }

                                    } /* so existe um elemento que pode ser comido */
                                    else if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0, peca_x0 + local_de_comida, 2);
                                        comeu = !comeu;
                                    } /* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 2:

                                    for (int i = 1; i < fabs(dif_peca_x); i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0 - i, peca_x0 + i);

                                        if (cor_no_meio != cor_peca && cor_no_meio != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }
                                    }
                                    if (comida_valida == 0 && killing_spree == false)
                                    {
                                        tabuleiro.setColor(peca_y, peca_x, cor_peca);
                                        peca_bool = false;
                                        if (!(peca_x == peca_x0 && peca_y == peca_y0))
                                        {
                                            if (vs_com == true)
                                            {
                                                glutPostRedisplay();
                                                COM();
                                            }
                                            else
                                            {
                                                vez = !vez;
                                                glutPostRedisplay();
                                            }
                                        }
                                        killing_spree = false;

                                    } /* so existe um elemento que pode ser comido */
                                    else if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0 - local_de_comida, peca_x0 + local_de_comida, 2);
                                        comeu = !comeu;
                                    } /* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 3:

                                    for (int i = 1; i < fabs(dif_peca_y); i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0 - i, peca_x0);

                                        if (cor_no_meio != cor_peca && cor_no_meio != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }
                                    }
                                    if (comida_valida == 0 && killing_spree == false)
                                    {
                                        tabuleiro.setColor(peca_y, peca_x, cor_peca);
                                        peca_bool = false;
                                        if (!(peca_x == peca_x0 && peca_y == peca_y0))
                                        {
                                            if (vs_com == true)
                                            {
                                                glutPostRedisplay();
                                                COM();
                                            }
                                            else
                                            {
                                                vez = !vez;
                                                glutPostRedisplay();
                                            }
                                        }
                                        killing_spree = false;

                                    } /* so existe um elemento que pode ser comido */
                                    else if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0 - local_de_comida, peca_x0, 2);
                                        comeu = !comeu;
                                    } /* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 4:

                                    for (int i = 1; i < fabs(dif_peca_x); i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0 - i, peca_x0 - i);

                                        if (cor_no_meio != cor_peca && cor_no_meio != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }
                                    }
                                    if (comida_valida == 0 && killing_spree == false)
                                    {
                                        tabuleiro.setColor(peca_y, peca_x, cor_peca);
                                        peca_bool = false;
                                        if (!(peca_x == peca_x0 && peca_y == peca_y0))
                                        {
                                            if (vs_com == true)
                                            {
                                                glutPostRedisplay();
                                                COM();
                                            }
                                            else
                                            {
                                                vez = !vez;
                                                glutPostRedisplay();
                                            }
                                        }
                                        killing_spree = false;

                                    } /* so existe um elemento que pode ser comido */
                                    else if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0 - local_de_comida, peca_x0 - local_de_comida, 2);
                                        comeu = !comeu;
                                    } /* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 5:

                                    for (int i = 1; i < fabs(dif_peca_x); i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0, peca_x0 - i);

                                        if (cor_no_meio != cor_peca && cor_no_meio != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }
                                    }
                                    if (comida_valida == 0 && killing_spree == false)
                                    {
                                        tabuleiro.setColor(peca_y, peca_x, cor_peca);
                                        peca_bool = false;
                                        if (!(peca_x == peca_x0 && peca_y == peca_y0))
                                        {
                                            if (vs_com == true)
                                            {
                                                glutPostRedisplay();
                                                COM();
                                            }
                                            else
                                            {
                                                vez = !vez;
                                                glutPostRedisplay();
                                            }
                                        }

                                        killing_spree = false;

                                    } /* so existe um elemento que pode ser comido */
                                    else if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0, peca_x0 - local_de_comida, 2);
                                        comeu = !comeu;
                                    } /* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 6:
                                    for (int i = 1; i < fabs(dif_peca_x); i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0 + i, peca_x0 - i);

                                        if (cor_no_meio != cor_peca && cor_no_meio != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }
                                    }
                                    if (comida_valida == 0 && killing_spree == false)
                                    {
                                        tabuleiro.setColor(peca_y, peca_x, cor_peca);
                                        peca_bool = false;
                                        if (!(peca_x == peca_x0 && peca_y == peca_y0))
                                        {
                                            if (vs_com == true)
                                            {
                                                glutPostRedisplay();
                                                COM();
                                            }
                                            else
                                            {
                                                vez = !vez;
                                                glutPostRedisplay();
                                            }
                                        }
                                        killing_spree = false;

                                    } /* so existe um elemento que pode ser comido */
                                    else if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0 + local_de_comida, peca_x0 - local_de_comida, 2);
                                        comeu = !comeu;
                                    } /* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 7:
                                    for (int i = 1; i < dif_peca_y; i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0 + i, peca_x0);

                                        if (cor_no_meio != cor_peca && cor_no_meio != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }
                                    }
                                    if (comida_valida == 0 && killing_spree == false)
                                    {
                                        tabuleiro.setColor(peca_y, peca_x, cor_peca);
                                        peca_bool = false;
                                        if (!(peca_x == peca_x0 && peca_y == peca_y0))
                                        {
                                            if (vs_com == true)
                                            {
                                                glutPostRedisplay();
                                                COM();
                                            }
                                            else
                                            {
                                                vez = !vez;
                                                glutPostRedisplay();
                                            }
                                        }
                                        killing_spree = false;

                                    } /* so existe um elemento que pode ser comido */
                                    else if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0 + local_de_comida, peca_x0, 2);
                                        comeu = !comeu;
                                    } /* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 8:
                                    for (int i = 1; i < dif_peca_x; i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0 + i, peca_x0 + i);

                                        if (cor_no_meio != cor_peca && cor_no_meio != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }
                                    }
                                    if (comida_valida == 0 && killing_spree == false)
                                    {
                                        tabuleiro.setColor(peca_y, peca_x, cor_peca);
                                        peca_bool = false;
                                        if (!(peca_x == peca_x0 && peca_y == peca_y0))
                                        {
                                            if (vs_com == true)
                                            {
                                                glutPostRedisplay();
                                                COM();
                                            }
                                            else
                                            {
                                                vez = !vez;
                                                glutPostRedisplay();
                                            }
                                        }
                                        killing_spree = false;

                                    } /* so existe um elemento que pode ser comido */
                                    else if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0 + local_de_comida, peca_x0 + local_de_comida, 2);
                                        comeu = !comeu;
                                    } /* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 9:

                                    volta_origem();
                                    break;
                                }
                                if (comeu)
                                {
                                    if (cor_peca == 4)
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
                            }
                            else
                            {
                                volta_origem();
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
            if (clique_y >= 1.0 && clique_y <= 2.0)
            {
                if (clique_x >= 0.25 && clique_x < 1.25)
                {
                    color = 'v';
                    menu_var = false;
                    Tabuleiro tab(color);
                    tabuleiro = tab;
                    glutPostRedisplay();
                }
                else if (clique_x > 1.25 && clique_x <= 2.25)
                {
                    color = 'a';
                    menu_var = false;
                    Tabuleiro tab(color);
                    tabuleiro = tab;
                    glutPostRedisplay();
                }
                else if (clique_x >= 2.75 && clique_x < 3.75)
                {
                    vs_com = true;
                    color = 'v';
                    menu_var = false;
                    Tabuleiro tab(color);
                    tabuleiro = tab;
                    glutPostRedisplay();
                }

                else if (clique_x > 3.75 && clique_x <= 4.75)
                {
                    vs_com = true;
                    color = 'a';
                    menu_var = false;
                    Tabuleiro tab(color);
                    tabuleiro = tab;
                    glutPostRedisplay();

                    COM();
                    vez = !vez;
                }
            }
        }
    }
}

void Teclado(unsigned char key, int x, int y)
{
    if ((key == 'F') || (key == 'f'))
    {
        if (vez == false)
            cout << "Amarelo vence!\n";
        else
            cout << "Vermelho vence!\n";
        exit(0);
    }
    if ((key == 'P') || (key == 'p') && (killing_spree == true))
    {
        if (vs_com == true)
        {
            killing_spree = false;
            COM();
            glutPostRedisplay();
        }
        else
        {
            vez = !vez;
            killing_spree = false;
        }
    }
}

void Botao_mov_mouse(int x, int y)
{
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
    glutKeyboardFunc(Teclado);
    glutMouseFunc(Botao_mouse);
    glutMotionFunc(Botao_mov_mouse);
    glutDisplayFunc(display);
    glutMainLoop();
}
