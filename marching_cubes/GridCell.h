#ifndef GRIDCELL_H
#define GRIDCELL_H

#include "Ponto3D.h"


class GridCell
{
    public:

        Ponto3D p[8];
        float val[8];

        GridCell(Ponto3D *v1, float *v2)
        {
            for(int i = 0; i < 8; i++)
            {
                p[i] = v1[i];
                val[i] = v2[i];
            }
        }

};

#endif