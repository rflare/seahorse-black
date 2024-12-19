#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

class Window {
    public:
        GLFWwindow* window;

        Window();
        void Update();
        void End();
        bool ShouldClose(); 

        bool IsKeyPressed(int key);
};

#endif // !WINDOW_H
