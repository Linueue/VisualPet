#include "Shader.h"

namespace Engine
{
    const char* Shader::s_DefaultVertexShader = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        layout (location = 1) in vec2 aTexCoord;

        out vec2 TexCoord;

        void main()
        {
            TexCoord = aTexCoord;
            gl_Position = vec4(aPos, 1.0);
        }
        )";
    const char* Shader::s_DefaultFragmentShader = R"(
        #version 330 core
        
        out vec4 FragColor;
        in vec2 TexCoord;

        uniform sampler2D u_Texture;

        void main()
        {
            FragColor = texture(u_Texture, TexCoord);
        }
        )";

    Shader::Shader(const char* vertexSource, const char* fragmentSource)
    {
        const uint32_t vertexShaderId = parseShader(vertexSource, GL_VERTEX_SHADER);
        const uint32_t fragmentShaderId = parseShader(fragmentSource, GL_FRAGMENT_SHADER);

        m_ShaderId = glCreateProgram();
        glAttachShader(m_ShaderId, vertexShaderId);
        glAttachShader(m_ShaderId, fragmentShaderId);
        glLinkProgram(m_ShaderId);

        int success = 0;
        glGetProgramiv(m_ShaderId, GL_LINK_STATUS, &success);

        if(!success)
        {
            char infoLog[512];
            glGetProgramInfoLog(m_ShaderId, 512, NULL, infoLog);

            std::cerr << "Engine (Shader): " << infoLog << "\n";
        }

        glUseProgram(m_ShaderId);
        glDeleteShader(vertexShaderId);
        glDeleteShader(fragmentShaderId);
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_ShaderId);
    }

    void Shader::UseShader() const
    {
        glUseProgram(m_ShaderId);
    }

    std::shared_ptr<Shader>& Shader::GetDefault()
    {
        static std::shared_ptr<Shader> defaultShader = std::make_shared<Shader>(s_DefaultVertexShader, s_DefaultFragmentShader);

        return defaultShader;
    }

    const uint32_t Shader::parseShader(const char* source, const GLenum shaderType)
    {
        const uint32_t shaderId = glCreateShader(shaderType);

        glShaderSource(shaderId, 1, &source, NULL);
        glCompileShader(shaderId);

        int success = 0;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

        if(!success)
        {
            char infoLog[512];
            glGetShaderInfoLog(shaderId, 512, NULL, infoLog);

            std::cerr << "Engine (Shader): " << infoLog << "\n";
        }

        return shaderId;
    }
}
