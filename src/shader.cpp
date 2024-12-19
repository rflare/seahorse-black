#include <glad/glad.h>

#include <sb_file.h>
#include <shader.h>

#include <iostream>
#include <string>
Shader::Shader(std::string vertexPath, std::string fragmentPath) {

    std::string vertexCodeStr = readFileToString(vertexPath);
    const char* vertexCode = vertexCodeStr.c_str();


    std::string fragmentCodeStr = readFileToString(fragmentPath);
    const char* fragmentCode = fragmentCodeStr.c_str();

    unsigned int vertexGLShader, fragmentGLShader;
    int success;
    char infoLog[512];

    // vertex Shader
    vertexGLShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexGLShader, 1, &vertexCode, NULL);
    glCompileShader(vertexGLShader);
    // print compile errors if any
    glGetShaderiv(vertexGLShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexGLShader, 512, NULL, infoLog);
        std::cout << "Error: Vertex shader compilation failed\n" << infoLog << "\n";
    };


    fragmentGLShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentGLShader, 1, &fragmentCode, NULL);
    glCompileShader(fragmentGLShader);
    // print compile errors if any
    glGetShaderiv(fragmentGLShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentGLShader, 512, NULL, infoLog);
        std::cout << "Error: Fragment shader compilation failed\n" << infoLog << "\n";
    };


    // shader Program
    ID = glCreateProgram();
    glAttachShader(ID, vertexGLShader);
    glAttachShader(ID, fragmentGLShader);
    glLinkProgram(ID);
    // print linking errors if any
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "Error: Shader linking failed\n" << infoLog << "\n";
    }

    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertexGLShader);
    glDeleteShader(fragmentGLShader);
}

void Shader::Use() { 
    glUseProgram(ID);
}  
