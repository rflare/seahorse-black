#include <window.h>

int main(void)
{

    Window* mainWindow = new Window();

    /* Loop until the user closes the window */
    while (!mainWindow->ShouldClose()) {
        mainWindow->Update();
    }

    mainWindow->End();

    return 0;
}
