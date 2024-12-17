#include <GLFW/glfw3.h>
#include <iostream>

#include <window.h>

Window::Window() {
    if (!glfwInit())
        std::cout << "frick";

    /* Create a windowed mode window and its OpenGL context */
    this->window = glfwCreateWindow(640, 480, "GLFW CMake starter", NULL, NULL);
    if (!this->window) {
        glfwTerminate();
        std::cout << "frick";
    }

    glfwMakeContextCurrent(this->window);
}

void Window::Update() {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor( 0.4f, 0.3f, 0.4f, 0.0f );

    /* Swap front and back buffers */
    glfwSwapBuffers(this->window);
    /* Poll for and process events */
    glfwPollEvents();
}

void Window::End() {
    glfwTerminate();
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(this->window);
}
