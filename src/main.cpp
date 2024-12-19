
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <window.h>
#include <sprite.h>
#include <shader.h>


int main()
{

    Window mainWindow;

    Sprite sprite;
    Shader shader("resources/vertex.glsl", "resources/fragment.glsl");


    
    while(!mainWindow.ShouldClose()) {

        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0, 0.0, 1.0));

        mainWindow.Update();
        shader.Use();
        shader.SetMat4("transform", transform);
        sprite.Draw();
    }

    mainWindow.End();


}
