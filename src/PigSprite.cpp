#include "PigSprite.h"

#include "Engine/Renderer.h"
#include "Engine/Utils/Random.h"
#include "Engine/Window.h"

void PigSprite::Construct()
{
    AddTexture(0, "assets/sprites/Pig/Pig.png", 5, 2);
    SetTexture(PigState::Idle);
    UseSubTexture(0, 0);
    m_State = PigState::Idle;

    for(uint32_t i = 0; i < 5; i++)
        m_IdleAnimation.AddAnimation( { i, 0.1f } );
    for(uint32_t i = 0; i < 4; i++)
        m_RunningAnimation.AddAnimation( { i, 0.1f } );

    m_Position.x = Engine::Random::RandRange(0, int32_t(m_ScreenBounds.x));
    m_Position.y = 0.0f;
    m_Flipped = false;
}

void PigSprite::Update(const float deltaTime)
{
    switch(m_State)
    {
        case PigState::Idle:
            Idle();
            break;
        case PigState::Running:
            Running();
            break;
    }

    const float GROUND_HEIGHT = m_ScreenBounds.y / 8.0f * 7.0f;
    constexpr float GRAVITY = 0.298f;

    m_Velocity.y += GRAVITY;

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

void PigSprite::Idle()
{
    if(m_RandomCycle == 0)
    {
        if(Engine::Random::Value() > 0.9f)
        {
            SetTexture(0);
            m_State = PigState::Running;
            UseSubTexture(0, 0);
            m_IdleAnimation.Reset();
            m_Velocity.x = 2.0f;
            return;
        }
    }
    constexpr int32_t RANDOM_CYCLE_FRAMES = 25;
    m_RandomCycle = (m_RandomCycle + 1) % RANDOM_CYCLE_FRAMES;

    UseSubTexture(m_IdleAnimation.Update().State, 0);

    m_Velocity.x = 0.0f;
}

void PigSprite::Running()
{
    if(m_RandomCycle == 0)
    {
        if(Engine::Random::Value() > 0.9f)
        {
            SetTexture(0);
            m_State = PigState::Idle;
            UseSubTexture(0, 0);
            m_RunningAnimation.Reset();
            m_Velocity.x = 0.0f;
            return;
        }
    }
    constexpr int32_t RANDOM_CYCLE_FRAMES = 25;
    m_RandomCycle = (m_RandomCycle + 1) % RANDOM_CYCLE_FRAMES;

    const auto state = m_RunningAnimation.Update();

    UseSubTexture(state.State, 1);
}
