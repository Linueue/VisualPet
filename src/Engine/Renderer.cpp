#include "Renderer.h"

#include "Shader.h"

#include <iostream>

namespace Engine
{
    void Renderer::Init()
    {
        if(!glfwInit())
        {
            std::cerr << "Engine (Renderer): Could not load GLFW.\n";
        }
    }

    void Renderer::DeInit()
    {
        glfwTerminate();
    }

    const int32_t Renderer::ConstructSprite()
    {
        const Vertex vertices[] = {
            { glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(-1.0f, -1.0f) },
            { glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec2(-1.0f,  1.0f) },
            { glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec2( 1.0f,  1.0f) },
            { glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec2( 1.0f, -1.0f) },
        };

        const uint32_t indices[] = {
            0, 1, 2,
            0, 2, 3,
        };

        uint32_t vao = 0;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        uint32_t vbo = 0, ebo = 0;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glGenBuffers(1, &ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        glEnableVertexAttribArray(0);
        
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoord));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);

        return vao;
    }

    void Renderer::DrawSprite(const uint32_t vao, const Shader &shader)
    {
        shader.UseShader();
        glBindVertexArray(vao);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
}
