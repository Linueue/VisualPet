#pragma once

#include "Shader.h"

#include <array>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Engine
{
    struct Bindings
    {
        uint32_t Vao, VertexVbo, TexCoordVbo;
    };

    class Renderer
    {
    public:
        static void Init();
        static void DeInit();

        static const Bindings ConstructSprite();
        static void DrawSprite(const uint32_t vao, const Shader &shader);
        static void SetSubData(const uint32_t vbo, const std::array<glm::vec2, 4> &data);
    };
}
