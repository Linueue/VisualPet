#pragma once

#include <Engine/Shader.h>
#include <Engine/Texture2D.h>
#include <Engine/SpriteSheet.h>
#include <Engine/Renderer.h>

#include <unordered_map>
#include <vector>

namespace Engine
{
    class SpriteGameObject
    {
    public:
        SpriteGameObject();
        virtual ~SpriteGameObject() = default;

        virtual void Construct() {}
        virtual void Update(const float deltaTime) {}
        virtual void Render();

        void UseSubTexture(const uint32_t widthIdx, const uint32_t heightIdx);

        template <typename T>
        void AddTexture(const T state, const char* fileName, const uint32_t widthMaxIdx, const uint32_t heightMaxIdx)
        {
            m_Textures[static_cast<int32_t>(state)] = std::make_unique<SpriteSheet>(widthMaxIdx, heightMaxIdx, std::make_shared<Texture2D>(fileName));
        }

        template <typename T>
        void SetTexture(const T state)
        {
            const auto& val = m_Textures.find(static_cast<int32_t>(state));

            if(val == m_Textures.end())
            {
                std::cerr << "Engine (SpriteGameObject): Texture could not be set.\n";
                return;
            }

            m_CurrentState = static_cast<int32_t>(state);
        }

    protected:
        Bindings m_Bindings;
        std::shared_ptr<Shader> m_Shader;
        int32_t m_CurrentState;
        std::unordered_map<int32_t, std::unique_ptr<SpriteSheet>> m_Textures;
        glm::vec2 m_Position;
        glm::vec2 m_ScreenBounds;
        bool m_Flipped;
    };
}
