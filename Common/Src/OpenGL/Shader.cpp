#include "OpenGL/Shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

Shader::Shader(const char* vertex_file_path, const char* geometry_file_path, const char* fragment_file_path) {
    unsigned int vertex_shader = GenerateShader(vertex_file_path, GL_VERTEX_SHADER);
    unsigned int geometry_shader = GenerateShader(geometry_file_path, GL_GEOMETRY_SHADER);
    unsigned int fragment_shader = GenerateShader(fragment_file_path, GL_FRAGMENT_SHADER);

    this->m_Shader = glCreateProgram();
    glAttachShader(this->m_Shader, vertex_shader);
    glAttachShader(this->m_Shader, geometry_shader);
    glAttachShader(this->m_Shader, fragment_shader);

    glLinkProgram(this->m_Shader);

    int success;
    char info_log[512] = {};
    glGetProgramiv(this->m_Shader, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(this->m_Shader, 512, NULL, info_log);
        std::cout << "Error! Shader link failed!" << info_log << std::endl;
        this->m_Shader = 0;
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(geometry_shader);
    glDeleteShader(fragment_shader);
}   

Shader::~Shader() {
    glDeleteProgram(this->m_Shader);
}

void Shader::Use() {
    glUseProgram(this->m_Shader);
}

unsigned int Shader::GenerateShader(const char* file_path, unsigned int type) {
    if (nullptr == file_path) return 0;

    std::ifstream file(file_path, std::ifstream::in);
    if (!file.is_open()) {
        std::cout << "Failed open " << file_path << " file." << std::endl;
        return 0;
    }

    std::stringstream stream;
    stream << file.rdbuf();
    file.close();
    std::string code = stream.str();
    const char* source_code = code.c_str();

    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &source_code, nullptr);
    glCompileShader(shader);

    int success;
    char info_log[512] = {};
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, info_log);
        std::cout << "Error! Shader compile failed!" << info_log << std::endl;
        return 0;
    }   

    return shader;
}

void Shader::SetUniform(const char* name, float value) {
    this->Use();
    glUniform1f(glGetUniformLocation(this->m_Shader, name), value);
}

void Shader::SetUniform(const char* name, int value) {
    this->Use();
    glUniform1i(glGetUniformLocation(this->m_Shader, name), value);
}

void Shader::SetUniform(const char* name, glm::mat4 value) {
    this->Use();
    glUniformMatrix4fv(glGetUniformLocation(this->m_Shader, name), 1, GL_FALSE, glm::value_ptr(value));
}