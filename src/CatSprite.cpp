#include "CatSprite.h"

#include "Engine/Renderer.h"

void CatSprite::Construct()
{
    AddTexture(CatState::Idle, "assets/sprites/Cats/IdleCat.png");
    SetTexture(CatState::Idle);
    m_State = CatState::Idle;
}

void CatSprite::Update(const float deltaTime)
{
}
