#include "Ponto3D.h"

class Triangulo
{
    private:
        Ponto3D v[3];

    public:

        Triangulo(Ponto3D v1, Ponto3D v2, Ponto3D v3)
        {
            v[0] = v1;
            v[1] = v2;
            v[2] = v3;
        }

        void operator=(const Triangulo& t);
}