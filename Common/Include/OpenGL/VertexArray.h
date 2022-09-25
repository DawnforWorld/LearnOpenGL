#ifndef __VERTEX_ARRAY_H__
#define __VERTEX_ARRAY_H__

class VertexArray {
public:
    VertexArray(const void* vertices_data, unsigned int vertices_size, unsigned int draw_type);
    ~VertexArray();

    void Bind();

private:
    unsigned int m_VAO = 0;
    unsigned int m_VBO = 0;
};

#endif