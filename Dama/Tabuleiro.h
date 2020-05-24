#include <iostream>
#include <GL/glut.h>
#include <cmath>
#define Pi 3.14159265359

using namespace std;
class Tabuleiro
{
private:
    int Mat_Tab[5][5];
    int num_pecas_vermelhas;
    int num_pecas_amarelas;

public:
    Tabuleiro(char color);
    Tabuleiro(const Tabuleiro &tab);
    void mostra();
    int getColor(int i, int j);
    void setColor(int i, int j, int color);
    int get_num_amarelas(void);
    int get_num_vermelhas(void);
    void set_num_amarelas(int n);
    void set_num_vermelhas(int n);
};

Tabuleiro::Tabuleiro(char color = 'a')
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (color == 'a')
            {

                if (i < 2)
                    Mat_Tab[i][j] = 1;
                else if (i > 2)
                    Mat_Tab[i][j] = 0;
                else
                {
                    Mat_Tab[i][0] = 1;
                    Mat_Tab[i][1] = 1;
                    Mat_Tab[i][2] = 2;
                    Mat_Tab[i][3] = 0;
                    Mat_Tab[i][4] = 0;
                    j = 5;
                }
            }
            else
            {
                if (i < 2)
                    Mat_Tab[i][j] = 0;
                else if (i > 2)
                    Mat_Tab[i][j] = 1;
                else
                {
                    Mat_Tab[i][0] = 0;
                    Mat_Tab[i][1] = 0;
                    Mat_Tab[i][2] = 2;
                    Mat_Tab[i][3] = 1;
                    Mat_Tab[i][4] = 1;
                    j = 5;
                }
            }
            
        }
    }
    num_pecas_amarelas = 12;
    num_pecas_vermelhas = 12;
}

Tabuleiro::Tabuleiro(const Tabuleiro &tab){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            Mat_Tab[i][j] = tab.Mat_Tab[i][j];
        }
        
    }
    num_pecas_amarelas = tab.num_pecas_amarelas;
    num_pecas_vermelhas = tab.num_pecas_vermelhas;
}

void Tabuleiro::mostra()
{
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    for (int i = 0; i <= 5; i++)
    {
        glVertex2f(0, i);
        glVertex2f(5, i);
        glVertex2f(i, 0);
        glVertex2f(i, 5);
    }
    glEnd();

    glEnable(GL_POINT_SMOOTH);
    glPointSize(50.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (Mat_Tab[i][j] == 0)
            {
                glColor3f(1, 0, 0);
                glVertex2f(0.5 + j, 0.5 + i);
            }
            else if (Mat_Tab[i][j] == 1)
            {
                glColor3f(1, 1, 0);
                glVertex2f(0.5 + j, 0.5 + i);
            }
            else if (Mat_Tab[i][j] == 3)
            {
                glColor3f(0.5, 0, 0);
                glVertex2f(0.5 + j, 0.5 + i);
            }
            else if (Mat_Tab[i][j] == 4)
            {
                glColor3f(0.5, 0.5, 0);
                glVertex2f(0.5 + j, 0.5 + i);
            }
            
        }
    }
    glEnd();
}

int Tabuleiro::getColor(int i, int j)
{
    if (i <= 4 && j <= 4 && i >= 0 && j >= 0)
    {
        cout << i << j << "cor " << Mat_Tab[i][j] << "\n";
        return Mat_Tab[i][j];
    }
    else
    {
        return 3;
    }
}

int Tabuleiro::get_num_vermelhas(void)
{
    return num_pecas_vermelhas;
}

int Tabuleiro::get_num_amarelas(void)
{
    return num_pecas_amarelas;
}

void Tabuleiro::set_num_vermelhas(int n)
{
    num_pecas_vermelhas = n;
}

void Tabuleiro::set_num_amarelas(int n)
{
    num_pecas_amarelas = n;
}

void Tabuleiro::setColor(int i, int j, int color)
{
    if (i <= 4 && j <= 4 && i >= 0 && j >= 0)
    {
        cout << i << j << "cor antiga" << Mat_Tab[i][j] << "\n";
        Mat_Tab[i][j] = color;
        cout << "cor nova " << color << "\n";
    }
    else
    {
        cout << "ponto invalido! \n";
    }
}
