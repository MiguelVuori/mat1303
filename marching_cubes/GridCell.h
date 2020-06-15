#include "Ponto3D.h"

class GridCell
{
    private:
        Ponto3D v[8];
        float fv[8];

    public:

        GridCell(Ponto3D *v1, float *(f)(Ponto3D))
        {
            for(int i = 0; i < 8; i++)
            {
                v[i] = v1[i];
                fv[i] = f(v[i]);
            }
        }

}