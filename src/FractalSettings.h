//
// Created by Jakub Pietrzak on 15/12/2023.
//

#pragma once

#include <glm/glm/glm.hpp>

class FractalSettings
{
private:
public:
    const static int MAX_ITER = 1400;
    static glm::vec4 colors[MAX_ITER];
    static void setupColors();
};
