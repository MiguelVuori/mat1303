#include "Ponto3D.h"

class GridCell
{
    public:

        Ponto3D p[8];
        float val[8];

        GridCell(Ponto3D *v1, float *(f)(Ponto3D))
        {
            for(int i = 0; i < 8; i++)
            {
                p[i] = v1[i];
                val[i] = f(p[i]);
            }
        }

}