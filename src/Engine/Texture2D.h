#pragma once

#include <iostream>

namespace Engine
{
    struct TextureSpecs
    {
        int Width, Height;
    };

    class Texture2D
    {
    public:
        Texture2D(const char* fileName);
        ~Texture2D();

        void UseTexture() const;

    private:
        uint32_t m_TextureId;
        TextureSpecs m_TextureSpecs;
    };
}
