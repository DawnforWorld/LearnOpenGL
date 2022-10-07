#ifndef __SHADER_H__
#define __SHADER_H__

#include "glm/glm.hpp"

#include "GLFW/glfw3.h"

class Shader {
public:
    Shader(const char* vertex_file_path, const char* geometry_file_path, const char* fragment_file_path);
    ~Shader();

    void Use();

    void SetUniform(const char* name, float value);
    void SetUniform(const char* name, int value);
    void SetUniform(const char* name, unsigned int value);
    void SetUniform(const char* name, const glm::mat4& value);
    void SetUniform(const char* name, const glm::vec3& value);

private:
    unsigned int GenerateShader(const char* file_path, unsigned int type);
    
    unsigned int m_Shader = 0;
};

#endif