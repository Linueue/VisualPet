#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Engine
{
    class Shader
    {
    public:
        Shader(const char* vertexSource, const char* fragmentSource);
        ~Shader();

        void UseShader() const;

        static std::shared_ptr<Shader>& GetDefault();

    private:
        const uint32_t parseShader(const char* source, const GLenum shaderType);

    private:
        static const char* s_DefaultVertexShader;
        static const char* s_DefaultFragmentShader;

        uint32_t m_ShaderId;
    };
}
