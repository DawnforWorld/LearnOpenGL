#include "OpenGL/Material.h"

#include "stb_image.h"
#include "glad/glad.h"

#include <iostream>

Material::Material(unsigned int ambient, unsigned int diffuse, unsigned int specular, float shininess) :
    m_Ambient(ambient),
    m_Diffuse(diffuse),
    m_Specular(specular),
    m_Shininess(shininess) {
    
}

unsigned int Material::LoadTexture(const char* fileName) {
    unsigned int texture = 0;

    int width, height, nrChannels;
    unsigned char* data = stbi_load(fileName, &width, &height, &nrChannels, 0);

    if (data) {
        GLenum format;
        if (nrChannels == 1) {
            format = GL_RED;
        }
        else if (nrChannels == 3) {
            format = GL_RGB;
        }
        else if (nrChannels == 4) {
            format = GL_RGBA;
        }

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }

    stbi_image_free(data);

    return texture;
}