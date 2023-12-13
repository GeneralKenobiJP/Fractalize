//
// Created by Jakub Pietrzak on 13/12/2023.
//

#pragma once


#include <glfw3.h>
#include <tuple>

class InputHandler
{
private:
    static float scaleSpeed;
public:
    static float scale;
    static std::pair<float, float> shift;

    static void keyInput(GLFWwindow* window, int key, int scancode, int action, int mods);

};
