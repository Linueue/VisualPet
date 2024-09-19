#include "CatSprite.h"

#include "Engine/Renderer.h"

void CatSprite::Construct()
{
    idx = 0;
    AddTexture(CatState::Idle, "assets/sprites/Cats/IdleCat.png", 7, 1);
    SetTexture(CatState::Idle);
    UseSubTexture(idx, 0);
    m_State = CatState::Idle;
}

void CatSprite::Update(const float deltaTime)
{
    UseSubTexture(idx % 7, 0);
    idx++;
}
