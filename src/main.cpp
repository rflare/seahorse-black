
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GLFW/glfw3.h>

#include <shader.h>
#include <sprite.h>
#include <window.h>

int main() {
  double currentFrameTime = 0;
  double lastFrameTime;
  Window mainWindow;

  Sprite sprite;
  Shader shader("resources/vertex.glsl", "resources/fragment.glsl");

  glm::mat4 transform = glm::mat4(1.0f);

  while (!mainWindow.ShouldClose()) {
    mainWindow.Update();

    lastFrameTime = currentFrameTime;
    currentFrameTime = glfwGetTime();
    double deltaTime = lastFrameTime - currentFrameTime;

    if (mainWindow.IsKeyPressed(GLFW_KEY_SPACE)) {
      transform =
          glm::rotate(transform, (float)(1 * deltaTime), glm::vec3(0, 0, 1));
    }

    shader.Use();
    shader.SetMat4("transform", transform);
    sprite.Draw();
  }

  mainWindow.End();
}
