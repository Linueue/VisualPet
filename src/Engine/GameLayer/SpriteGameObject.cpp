#include "SpriteGameObject.h"

#include <Engine/Renderer.h>
#include <Engine/Window.h>

namespace Engine
{
    SpriteGameObject::SpriteGameObject()
        : m_Position(0.0f)
    {
        m_Bindings = Renderer::ConstructSprite();
        m_Shader = Shader::GetDefault();
        m_CurrentState = -1;
        m_ScreenBounds = Window::GetScreenSize();
        const Window* window = Window::GetCurrentWindow();
        const int32_t width = window->GetWidth();
        const int32_t height = window->GetHeight();
        m_ScreenBounds -= glm::vec2(float(width), float(height));
        m_Flipped = false;
    }

    void SpriteGameObject::Render()
    {
        if(m_CurrentState == -1)
        {
            std::cerr << "Current texture has not been set.\n";
            return;
        }
        m_Textures[m_CurrentState]->UseTexture();
        Renderer::DrawSprite(m_Bindings.Vao, *m_Shader.get());
        Window::GetCurrentWindow()->SetPosition(int32_t(m_Position.x), int32_t(m_Position.y));
    }

    void SpriteGameObject::UseSubTexture(const uint32_t widthIdx, const uint32_t heightIdx)
    {
        if(m_CurrentState == -1)
        {
            std::cerr << "Current texture has not been set.\n";
            return;
        }
        m_Textures[m_CurrentState]->UseSubTexture(m_Bindings.TexCoordVbo, widthIdx, heightIdx, m_Flipped);
    }
}
