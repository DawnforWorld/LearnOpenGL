#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "glm/glm.hpp"

class Material {
public:
    Material(unsigned int ambient, unsigned int diffuse, unsigned int specular, float shininess);

    const unsigned int& GetAmbient() { return this->m_Ambient; }
    const unsigned int& GetDiffuse() { return this->m_Diffuse; }
    const unsigned int& GetSpecular() { return this->m_Specular; }
    const float& GetShininess() { return this->m_Shininess; }

    void SetAmbient(const unsigned int& value) { this->m_Ambient = value; }
    void SetDiffuse(const unsigned int& value) { this->m_Diffuse = value; }
    void SetSpecular(const unsigned int& value) { this->m_Specular = value; }
    void SetShininess(const float& value) { this->m_Shininess = value; }

    static unsigned int LoadTexture(const char* fileName);
private:
    unsigned int m_Ambient;
    unsigned int m_Diffuse;
    unsigned int m_Specular;
    float m_Shininess;
};

#endif