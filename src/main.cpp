#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "BufferLayout.h"

int main()
{
    std::cout << "Hello, World" << std::endl;

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Fractalize", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    if(glewInit() != GLEW_OK)
        std::cout << "Error. glewInit() != GLEW_OK" << std::endl;
    else
        std::cout << glGetString(GL_VERSION) << std::endl;

    {

        float positions[] = {
                0.0f, 0.5f,
                0.5f, 0.5f,
                -0.5f, 0.0f,
                -0.5f, -0.5f
        };

        unsigned int indices[] = {
                0, 1, 2,
                2, 3, 0
        };

        unsigned int vertexArrayObjects;
        GLCall(glGenVertexArrays(1, &vertexArrayObjects));
        GLCall(glBindVertexArray(vertexArrayObjects));

        VertexArray vertexArray;
        VertexBuffer vertexBuffer(positions, sizeof (positions));

        BufferLayout bufferLayout;
        bufferLayout.push<float>(2);
        vertexArray.addBuffer(vertexBuffer, bufferLayout);

        IndexBuffer indexBuffer(indices, 6);

        Shader shader("../res/shaders/basic.shader");
        shader.bind();
        shader.setUniform4f("u_Color", 0.25f, 0.75f, 0.1f, 1.0f);

        vertexArray.unbind();
        vertexBuffer.unbind();
        indexBuffer.unbind();
        shader.unbind();

        Renderer renderer;

        float r = 0.0f;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            // // // MY CODE STARTS HERE
            renderer.clear();

            r += 0.02f;
            if (r > 1.0f)
                r = 0.0f;

            shader.bind();
            shader.setUniform4f("u_Color", r, 0.75f, 0.2f, 1.0f );

            renderer.draw(vertexArray, indexBuffer, shader);

            // // // MY CODE ENDS HERE

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }

    }

    glfwTerminate();
    return 0;
}
