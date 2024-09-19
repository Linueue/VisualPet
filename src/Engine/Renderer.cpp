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

    const Bindings Renderer::ConstructSprite()
    {
        const glm::vec3 vertices[] = {
            glm::vec3(-0.5f, -0.5f, 0.0f),
            glm::vec3(-0.5f,  0.5f, 0.0f),
            glm::vec3( 0.5f,  0.5f, 0.0f),
            glm::vec3( 0.5f, -0.5f, 0.0f),
        };

        const glm::vec2 texCoords[] = {
            glm::vec2(-1.0f, -1.0f),
            glm::vec2(-1.0f,  1.0f),
            glm::vec2( 1.0f,  1.0f),
            glm::vec2( 1.0f, -1.0f),
        };

        const uint32_t indices[] = {
            0, 1, 2,
            0, 2, 3,
        };

        uint32_t vao = 0;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        uint32_t vbo[2];
        uint32_t ebo;
        glGenBuffers(1, &vbo[0]);
        glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glGenBuffers(1, &vbo[1]);
        glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_DYNAMIC_DRAW);

        glGenBuffers(1, &ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)0);
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);

        return Bindings { vao, vbo[0], vbo[1] };
    }

    void Renderer::DrawSprite(const uint32_t vao, const Shader &shader)
    {
        shader.UseShader();
        glBindVertexArray(vao);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    void Renderer::SetSubData(const uint32_t vbo, const std::array<glm::vec2, 4> &data)
    {
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(glm::vec2) * 4, data.data());
    }
}
