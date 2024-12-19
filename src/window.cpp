#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <window.h>

Window::Window() {

    if(!glfwInit()) {
        throw "";
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1920, 1080, "GLFW CMake starter", NULL, NULL);
    if (!window) {
        glfwTerminate();
        throw "";
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        throw "";
    }

    printf("OpenGL version: %s\n", glGetString(GL_VERSION));

}

void Window::Update() {

    
    /* Swap front and back buffers */
    glfwSwapBuffers(window);
    /* Poll for and process events */
    glfwPollEvents();

    //Clear color stuff 
    glClearColor( 0.4f, 0.3f, 0.4f, 0.0f );
    glClear(GL_COLOR_BUFFER_BIT);


}

void Window::End() {
    glfwTerminate();
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(window);
}
