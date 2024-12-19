#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader {
    private:
        unsigned int ID;
    public:
        Shader(std::string vertexPath, std::string fragmentPath);
        void Use();

};

#endif // !WINDOW_H
