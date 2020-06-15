#include "Ponto3D.h"

class Triangulo
{
    public:
        Ponto3D p[3];

        Triangulo(Ponto3D v1, Ponto3D v2, Ponto3D v3)
        {
            p[0] = v1;
            p[1] = v2;
            p[2] = v3;
        }

        void operator=(const Triangulo& t);
}