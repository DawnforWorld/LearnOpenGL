#ifndef __SHADER_H__
#define __SHADER_H__

class Shader {
public:
    Shader(const char* vertex_file_path, const char* geometry_file_path, const char* fragment_file_path);
    ~Shader();

    void Use();

private:
    unsigned int GenerateShader(const char* file_path, unsigned int type);
    
    unsigned int m_Shader = 0;
};

#endif