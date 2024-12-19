#include <window.h>
#include <sprite.h>
#include <shader.h>

int main()
{

    Window mainWindow;

    Sprite sprite;
    Shader shader("resources/vertex.glsl", "resources/fragment.glsl");
    
    while(!mainWindow.ShouldClose()) {
        mainWindow.Update();
        shader.Use();
        sprite.Draw();
    }

    mainWindow.End();


}
