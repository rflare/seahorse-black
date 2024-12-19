#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <string>
#undef ERROR

class Shader {
    private:
        unsigned int ID;
    public:
        Shader(std::string vertexPath, std::string fragmentPath);
        void Use();

        void SetMat4(const std::string &name, const glm::mat4 &mat) const;

};

#endif
