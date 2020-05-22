#include <iostream>
#include <GL/glut.h>
#include <cmath>
#define Pi 3.14159265359

using namespace std;
class Tabuleiro
{
private:
    int Mat_Tab[5][5];

public:
    Tabuleiro();
    void mostra();
    int getColor(int i, int j);
    void setColor(int i , int j, int color);
};

Tabuleiro::Tabuleiro()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
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
    }
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
        }
    }
    glEnd();
}

int Tabuleiro::getColor(int i, int j){
    if(i <= 4 && j <= 4 && i >= 0 && j >= 0){
        cout << i << j << "cor " << Mat_Tab[i][j] << "\n";
        return Mat_Tab[i][j];
    }
    else
    {
        cout << "ponto invalido! \n";
    }
}

void Tabuleiro::setColor(int i, int j, int color){
    if(i <= 4 && j <= 4 && i >= 0 && j >= 0){
        cout << i << j << "cor antiga" << Mat_Tab[i][j] << "\n";
        Mat_Tab[i][j] = color;
        cout << "cor nova " << color << "\n";
    }
    else
    {
        cout << "ponto invalido! \n";
    }
}
