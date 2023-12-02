#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
    std::cout << "Hello, World" << std::endl;

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK)
        std::cout << "Error. glewInit() != GLEW_OK" << std::endl;
    else
        std::cout << glGetString(GL_VERSION) << std::endl;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // // // MY CODE STARTS HERE

        glBegin(GL_TRIANGLES);
        glVertex2f(0.0f,0.5f);
        glVertex2f(0.5f,0.5f);
        glVertex2f(-0.5f,0.0f);
        glEnd();

        // // // MY CODE ENDS HERE

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
