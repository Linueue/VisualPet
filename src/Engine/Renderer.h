#pragma once

#include "Shader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Engine
{
    struct Vertex
    {
        glm::vec3 Position;
        glm::vec2 TexCoord;
    };

    class Renderer
    {
    public:
        static void Init();
        static void DeInit();

        static const int32_t ConstructSprite();
        static void DrawSprite(const uint32_t vao, const Shader &shader);
    };
}
