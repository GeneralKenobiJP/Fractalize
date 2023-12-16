//
// Created by Jakub Pietrzak on 15/12/2023.
//

#include "FractalSettings.h"
#include <cmath>

glm::vec4 FractalSettings::colors[FractalSettings::MAX_ITER];

void FractalSettings::setupColors()
{
    for(int i=0;i<MAX_ITER;i++)
    {
        float iter = (float)(i)/MAX_ITER;
        colors[i][0] = 0.5f*sin(M_PI*(10*iter-0.5))+0.5;
        colors[i][1] = colors[i].x;
        colors[i][2] = tan(0.25*M_PI*iter);
        colors[i][3] = 1.0;
    }
}
