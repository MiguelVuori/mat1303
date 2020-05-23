#include "Tabuleiro.h"
#include <GL/glut.h>
#include "Window.h"

Window w(-0.5, 5.5, -0.5, 5.5, 800, 800);
Tabuleiro tabuleiro;

bool peca_bool = false, vez = false, killing_spree = false;
float mouse_x, mouse_y;
int cor_peca = 2;
int peca_x0, peca_y0;

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
    tabuleiro.mostra();
    if (peca_bool == true)
    {
        peca();
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
    mouse_x = x;
    mouse_y = y;

    if (botao == GLUT_LEFT_BUTTON)
    {
        peca_x = w.getl() + mouse_x / (w.getDIMX() - 1) * (w.getr() - w.getl());
        peca_y = w.gett() + mouse_y / (w.getDIMY() - 1) * (w.getb() - w.gett());

        /* clicou com o mouse */
        if (state == GLUT_DOWN)
        {
            if (peca_x <= 4 && peca_y <= 4 && peca_x >= 0 && peca_y >= 0)
            {
                if(killing_spree == true && peca_x0 == peca_x && peca_y == peca_y0)
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

                    if (cor_peca == 0 or cor_peca == 1)
                    {
                        /* caso em que so se movimenta a peca */
                        if (fabs(dif_peca_x) <= 1 && fabs(dif_peca_y) <= 1)
                        {
                            tabuleiro.setColor(peca_y, peca_x, cor_peca);
                            peca_bool = false;
                            if(!(peca_x == peca_x0 && peca_y == peca_y0))
                                vez = !vez;
                            glutPostRedisplay();
                            killing_spree = false;

                        }/* caso em que se come uma peca */
                        else if ((fabs(dif_peca_y) + fabs(dif_peca_x) == 2) or (fabs(dif_peca_y) + fabs(dif_peca_x) == 4))
                        {   
                            int comeu = 0;

                            switch (dif_peca_x + 3 * dif_peca_y)
                            {
                            case 2:
                                if(tabuleiro.getColor(peca_y, peca_x - 1 ) != 2 && cor_peca != tabuleiro.getColor(peca_y, peca_x - 1))
                                {
                                    tabuleiro.setColor(peca_y, peca_x - 1, 2);
                                    comeu = !comeu;
                                }
                                break;
                            case -4:
                                if(tabuleiro.getColor(peca_y + 1, peca_x - 1) != 2 && cor_peca != tabuleiro.getColor(peca_y + 1, peca_x - 1)) 
                                {
                                    tabuleiro.setColor(peca_y + 1, peca_x - 1, 2);
                                    comeu = !comeu;
                                }
                                break;
                            case -6:
                                if(tabuleiro.getColor(peca_y + 1, peca_x) != 2 && cor_peca != tabuleiro.getColor(peca_y + 1, peca_x))
                                {
                                    tabuleiro.setColor(peca_y + 1, peca_x, 2);
                                    comeu = !comeu;
                                }
                                break;
                            case -8:
                            if(tabuleiro.getColor(peca_y + 1, peca_x + 1) != 2 && cor_peca != tabuleiro.getColor(peca_y + 1, peca_x + 1))
                                {
                                    tabuleiro.setColor(peca_y + 1, peca_x + 1, 2);
                                    comeu = !comeu;
                                }
                                break;
                            case -2:
                                if(tabuleiro.getColor(peca_y, peca_x + 1) != 2 && cor_peca != tabuleiro.getColor(peca_y, peca_x + 1))
                                {
                                    tabuleiro.setColor(peca_y, peca_x + 1, 2);
                                    comeu = !comeu;
                                }
                                break;
                            case 4:
                                if(tabuleiro.getColor(peca_y - 1, peca_x + 1) != 2 && cor_peca != tabuleiro.getColor(peca_y - 1, peca_x + 1))
                                {
                                    tabuleiro.setColor(peca_y - 1, peca_x + 1, 2);
                                    comeu = !comeu;
                                }
                                break;
                            case 6:
                                if(tabuleiro.getColor(peca_y - 1, peca_x) != 2 && cor_peca != tabuleiro.getColor(peca_y - 1, peca_x))
                                {
                                    tabuleiro.setColor(peca_y - 1, peca_x, 2);
                                    comeu = !comeu;
                                }
                                break;
                            case 8:
                                if(tabuleiro.getColor(peca_y - 1, peca_x - 1) != 2 && cor_peca != tabuleiro.getColor(peca_y - 1, peca_x - 1))
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

                        }
                    }
                    else if ((cor_peca == 3 || cor_peca == 4) && ((fabs(dif_peca_x) == fabs(dif_peca_y)) || (dif_peca_x == 0 && dif_peca_y <= 4) || (dif_peca_y == 0 && dif_peca_x <= 4)))
                    {
                        //int dif_peca_x, dif_peca_y;
                        int localizacao;
                        int comeu = 0;
                        //dif_peca_x = peca_x - peca_x0;
                        //dif_peca_y = peca_y - peca_y0;

                        if (dif_peca_x > 0)
                        {
                            if(dif_peca_y > 0)
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
                            if(dif_peca_y > 0)
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
                            if(dif_peca_y > 0)
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
                            
                            switch(localizacao)
                            {
                                case 1:

                                    for(int i = 1; i < fabs(dif_peca_x) ; i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0,peca_x0 + i);

                                        if (cor_no_meio != cor_peca && cor_no_meio  != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }

                                    }/* so existe um elemento que pode ser comido */
                                    if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0, peca_x0 + local_de_comida, 2);
                                        comeu = !comeu;
                                    }/* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 2:

                                    for(int i = 1; i < fabs(dif_peca_x) ; i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0 - i,peca_x0 + i);

                                        if (cor_no_meio != cor_peca && cor_no_meio  != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }

                                    }/* so existe um elemento que pode ser comido */
                                    if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0 - local_de_comida, peca_x0 + local_de_comida, 2);
                                        comeu = !comeu;
                                    }/* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 3:

                                    for(int i = 1; i < fabs(dif_peca_y) ; i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0 - i,peca_x0);

                                        if (cor_no_meio != cor_peca && cor_no_meio  != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }

                                    }/* so existe um elemento que pode ser comido */
                                    if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0 - local_de_comida, peca_x0, 2);
                                        comeu = !comeu;
                                    }/* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 4:

                                    for(int i = 1; i < fabs(dif_peca_x) ; i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0 - i,peca_x0 - i);

                                        if (cor_no_meio != cor_peca && cor_no_meio  != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }

                                    }/* so existe um elemento que pode ser comido */
                                    if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0 - local_de_comida, peca_x0 - local_de_comida, 2);
                                        comeu = !comeu;
                                    }/* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 5:

                                    for(int i = 1; i < fabs(dif_peca_x) ; i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0,peca_x0 - i);

                                        if (cor_no_meio != cor_peca && cor_no_meio  != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }

                                    }/* so existe um elemento que pode ser comido */
                                    if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0, peca_x0 - local_de_comida, 2);
                                        comeu = !comeu;
                                    }/* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 6:
                                for(int i = 1; i < fabs(dif_peca_x) ; i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0 + i,peca_x0 - i);

                                        if (cor_no_meio != cor_peca && cor_no_meio  != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }

                                    }/* so existe um elemento que pode ser comido */
                                    if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0 + local_de_comida, peca_x0 - local_de_comida, 2);
                                        comeu = !comeu;
                                    }/* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 7:
                                for(int i = 1; i < dif_peca_y ; i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0 + i,peca_x0);

                                        if (cor_no_meio != cor_peca && cor_no_meio  != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }

                                    }/* so existe um elemento que pode ser comido */
                                    if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0 + local_de_comida, peca_x0, 2);
                                        comeu = !comeu;
                                    }/* qualquer coisa invalida */
                                    else
                                    {
                                        volta_origem();
                                    }
                                    break;
                                case 8:
                                for(int i = 1; i < dif_peca_x ; i++)
                                    {
                                        int cor_no_meio = tabuleiro.getColor(peca_y0 + i,peca_x0 + i);

                                        if (cor_no_meio != cor_peca && cor_no_meio  != cor_peca + 3 && cor_no_meio != 2)
                                        {
                                            comida_valida = comida_valida + 1;
                                            local_de_comida = i;
                                        }

                                    }/* so existe um elemento que pode ser comido */
                                    if (comida_valida == 1)
                                    {
                                        tabuleiro.setColor(peca_y0 + local_de_comida, peca_x0 + local_de_comida, 2);
                                        comeu = !comeu;
                                    }/* qualquer coisa invalida */
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

                        
                    }/* caso em que se fez um movimento invalido */
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