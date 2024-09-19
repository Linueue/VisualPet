#include "CatSprite.h"

#include "Engine/Renderer.h"
#include "Engine/Utils/Random.h"

void CatSprite::Construct()
{
    AddTexture(CatState::Idle, "assets/sprites/Cats/IdleCat.png", 7, 1);
    AddTexture(CatState::Running, "assets/sprites/Cats/JumpCat.png", 13, 1);
    SetTexture(CatState::Idle);
    UseSubTexture(0, 0);
    m_State = CatState::Idle;

    for(uint32_t i = 0; i < 7; i++)
        m_IdleAnimation.AddAnimation( { i, 0.1f } );
    for(uint32_t i = 0; i < 13; i++)
        m_RunningAnimation.AddAnimation( { i, 0.1f } );
}

void CatSprite::Update(const float deltaTime)
{
    switch(m_State)
    {
        case CatState::Idle:
            Idle();
            break;
        case CatState::Running:
            Running();
            break;
    }
}

void CatSprite::Idle()
{
    if(Engine::Random::Value() > 0.99f)
    {
        SetTexture(CatState::Running);
        m_State = CatState::Running;
        m_IdleAnimation.Reset();
    }
    UseSubTexture(m_IdleAnimation.Update().State, 0);
}

void CatSprite::Running()
{
    const auto state = m_RunningAnimation.Update();

    UseSubTexture(state.State, 0);

    if(state.IsFinished)
    {
        SetTexture(CatState::Idle);
        m_State = CatState::Idle;
        m_RunningAnimation.Reset();
    }
}
