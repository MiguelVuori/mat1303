#include "Triangulo.h"

void Triangulo::operator=(const Triangulo& t)
{
    p[0] = t.p[0];
    p[1] = t.p[1];
    p[2] = t.p[2];
}