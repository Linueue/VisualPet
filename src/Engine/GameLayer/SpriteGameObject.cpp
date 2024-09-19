#include "SpriteGameObject.h"

#include <Engine/Renderer.h>

namespace Engine
{
    SpriteGameObject::SpriteGameObject()
    {
        m_Vao = Renderer::ConstructSprite();
        m_Shader = Shader::GetDefault();
        m_CurrentState = -1;
    }

    void SpriteGameObject::Render()
    {
        if(m_CurrentState == -1)
        {
            std::cerr << "Current texture has not been set.\n";
            return;
        }
        m_Textures[m_CurrentState]->UseTexture();
        Renderer::DrawSprite(m_Vao, *m_Shader.get());
    }
}
