#include "Texture2D.h"

#include "Renderer.h"
#include <stb_image.h>

namespace Engine
{
    Texture2D::Texture2D(const char* fileName)
    {
        glGenTextures(1, &m_TextureId);
        glBindTexture(GL_TEXTURE_2D, m_TextureId);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        int32_t channels = 0;

        uint8_t* imageData = stbi_load(fileName, &m_TextureSpecs.Width, &m_TextureSpecs.Height, &channels, 0);

        if(!imageData)
        {
            std::cerr << "Engine (Texture2D): Could not load file " << fileName << "\n";
        }

        if(channels != 4)
        {
            std::cerr << "Engine (Texture2D): Expected 4 channels (RGBA) but got " << channels << " channels instead.\n";
        } else
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_TextureSpecs.Width, m_TextureSpecs.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
        }

        stbi_image_free(imageData);
    }

    Texture2D::~Texture2D()
    {
        glDeleteTextures(1, &m_TextureId);
    }

    void Texture2D::UseTexture() const
    {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_TextureId);
    }
}
