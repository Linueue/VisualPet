#pragma once

#include "Texture2D.h"

#include <array>
#include <glm/glm.hpp>

namespace Engine
{
    class SpriteSheet
    {
    public:
        SpriteSheet(const uint32_t widthMaxIdx, const uint32_t heightMaxIdx, const std::shared_ptr<Texture2D> &texture);

        void UseSubTexture(const uint32_t vbo, const uint32_t widthIdx, const uint32_t heightIdx, const bool flipped);
        const std::array<glm::vec2, 4> GetOffset(const uint32_t widthIdx, const uint32_t heightIdx, const bool flipped);

        inline void UseTexture() const { m_Texture->UseTexture(); }

    private:
        float m_WidthOffset, m_HeightOffset;
        std::shared_ptr<Texture2D> m_Texture;
    };
}
