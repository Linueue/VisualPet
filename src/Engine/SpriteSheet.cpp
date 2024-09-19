#include "SpriteSheet.h"

#include "Renderer.h"

std::ostream& operator<<(std::ostream& stream, const glm::vec2 vec)
{
    stream << "glm::vec2(" << vec.x << ", " << vec.y << ")";

    return stream;
}

namespace Engine
{
    SpriteSheet::SpriteSheet(const uint32_t widthMaxIdx, const uint32_t heightMaxIdx, const std::shared_ptr<Texture2D> &texture)
        : m_Texture(std::move(texture))
    {
        const TextureSpecs textureSpecs = m_Texture->GetTextureSpecs();
        m_WidthOffset = float(textureSpecs.Width) / widthMaxIdx;
        m_HeightOffset = float(textureSpecs.Height) / heightMaxIdx;
        m_WidthOffset /= textureSpecs.Width;
        m_HeightOffset /= textureSpecs.Height;
    }

    void SpriteSheet::UseSubTexture(const uint32_t vbo, const uint32_t widthIdx, const uint32_t heightIdx)
    {
        const std::array<glm::vec2, 4> offset = GetOffset(widthIdx, heightIdx);
        for(const auto &data : offset)
        {
            std::cout << data << "\n";
        }
        Renderer::SetSubData(vbo, offset);
    }

    const std::array<glm::vec2, 4> SpriteSheet::GetOffset(const uint32_t widthIdx, const uint32_t heightIdx)
    {
        const std::array<glm::vec2, 4> offset = {
            glm::vec2(m_WidthOffset *  widthIdx,      m_HeightOffset * (heightIdx + 1)),
            glm::vec2(m_WidthOffset *  widthIdx,      m_HeightOffset *  heightIdx),
            glm::vec2(m_WidthOffset * (widthIdx + 1), m_HeightOffset *  heightIdx),
            glm::vec2(m_WidthOffset * (widthIdx + 1), m_HeightOffset * (heightIdx + 1)),
        };

        return offset;
    }
}
