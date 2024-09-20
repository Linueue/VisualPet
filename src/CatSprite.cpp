#include "CatSprite.h"

#include "Engine/Renderer.h"
#include "Engine/Utils/Random.h"
#include "Engine/Window.h"

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

    m_Position.x = Engine::Random::RandRange(0, int32_t(m_ScreenBounds.x));
    m_Position.y = 0.0f;
    m_Flipped = (Engine::Random::Value() > 0.5f);
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

    const float GROUND_HEIGHT = m_ScreenBounds.y / 8.0f * 7.0f;
    constexpr float GRAVITY = 0.298f;
    constexpr float AIR_RESISTANCE = 10.0f;

    m_Velocity.y += GRAVITY;
    m_Velocity = glm::mix(m_Velocity, glm::vec2(0.0f), deltaTime * AIR_RESISTANCE);

    m_Position.x += !m_Flipped ? m_Velocity.x : -m_Velocity.x;
    m_Position.y += m_Velocity.y;

    if(m_Position.y >= GROUND_HEIGHT)
    {
        m_Position.y = GROUND_HEIGHT;
        m_Velocity.y = 0.0f;
    }

    if(m_Position.x >= m_ScreenBounds.x)
    {
        m_Flipped = true;
    } else if(m_Position.x <= 0.0f)
    {
        m_Flipped = false;
    }
}

void CatSprite::Idle()
{
    if(m_RandomCycle == 0)
    {
        if(Engine::Random::Value() > 0.9f)
        {
            SetTexture(CatState::Running);
            m_State = CatState::Running;
            UseSubTexture(0, 0);
            m_IdleAnimation.Reset();
            return;
        }
    }
    constexpr int32_t RANDOM_CYCLE_FRAMES = 25;
    m_RandomCycle = (m_RandomCycle + 1) % RANDOM_CYCLE_FRAMES;

    UseSubTexture(m_IdleAnimation.Update().State, 0);

    m_Velocity.x = 0.0f;
}

void CatSprite::Running()
{
    const auto state = m_RunningAnimation.Update();

    UseSubTexture(state.State, 0);

    if(state.IsFinished)
    {
        SetTexture(CatState::Idle);
        m_State = CatState::Idle;
        UseSubTexture(0, 0);
        m_RunningAnimation.Reset();
    }

    switch(state.State)
    {
        case 3:
            m_Velocity.x = 10.0f;
            m_Velocity.y = -5.0f;
            break;
        case 10:
            m_Velocity.x = 0.0f;
            m_Velocity.y = 0.0f;
            break;
    }
}
