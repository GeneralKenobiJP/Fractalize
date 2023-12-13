//
// Created by Jakub Pietrzak on 13/12/2023.
//

#include "InputHandler.h"
//#include <iostream>

float InputHandler::scale = 1.0f;
float InputHandler::scaleSpeed = 0.1f;
std::pair<float, float> InputHandler::shift = {0.0, 0.0};

void InputHandler::keyInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS || action == GLFW_REPEAT || action == GLFW_RELEASE)
    {
        //std::cout << scaleSpeed << std::endl;
        switch(key)
        {
            case GLFW_KEY_Z:
                scale += scaleSpeed;
                scaleSpeed += 0.02f;
                break;
            case GLFW_KEY_X:
                scaleSpeed -= 0.01f;
                if(scaleSpeed < 0.01f)
                    scaleSpeed = 0.01f;
                scale -= scaleSpeed;
                if(scale < 0.05f)
                    scale = 0.05f;
                break;
            case GLFW_KEY_A:
                shift.first -= 0.1f/scale;
                break;
            case GLFW_KEY_D:
                shift.first += 0.1f/scale;
                break;
            case GLFW_KEY_W:
                shift.second += 0.1f/scale;
                break;
            case GLFW_KEY_S:
                shift.second -= 0.1f/scale;
                break;
            case GLFW_KEY_E:
                scaleSpeed += 2.0f;
                if(scaleSpeed > 100.0f)
                    scaleSpeed = 100.0f;
                break;
            case GLFW_KEY_Q:
                scaleSpeed -= 2.0f;
                if(scaleSpeed < 0.01f)
                    scaleSpeed = 0.01f;
                break;
            case GLFW_KEY_SPACE:
                shift = { 0.0, 0.0 };
                scale = 1.0f;
            case GLFW_KEY_C:
                scaleSpeed = 0.1f;
                break;
        }
    }
}
