#include "OpenGL/VertexArray.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

VertexArray::VertexArray(const void* vertices_data, unsigned int vertices_size, unsigned int draw_type) {
  
    glGenVertexArrays(1, &(this->m_VAO));
    glGenBuffers(1, &m_VBO);

    this->Bind();

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices_size, vertices_data, GL_STATIC_DRAW);

    glBindVertexArray(0);
}

VertexArray::~VertexArray() {
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    glDeleteBuffers(1, &m_VBO);
    glDeleteVertexArrays(1, &this->m_VAO);
}

void VertexArray::Bind() {
    glBindVertexArray(this->m_VAO);
}