#include "FrogSprite.h"

#include "Engine/Renderer.h"
#include "Engine/Utils/Random.h"
#include "Engine/Window.h"

void FrogSprite::Construct()
{
    AddTexture(FrogState::Idle, "assets/sprites/Frog/IdleFrog.png", 2, 1);
    SetTexture(FrogState::Idle);
    UseSubTexture(0, 0);
    m_State = FrogState::Idle;

    for(uint32_t i = 0; i < 2; i++)
        m_IdleAnimation.AddAnimation( { i, 0.25f } );

    m_Position.x = Engine::Random::RandRange(0, int32_t(m_ScreenBounds.x));
    m_Position.y = 0.0f;
    m_Flipped = false;
}

void FrogSprite::Update(const float deltaTime)
{
    switch(m_State)
    {
        case FrogState::Idle:
            Idle();
            break;
    }

    const float GROUND_HEIGHT = m_ScreenBounds.y / 8.0f * 7.0f;
    constexpr float GRAVITY = 0.298f;
    constexpr float AIR_RESISTANCE = 10.0f;

    m_Velocity.y += GRAVITY;
    m_Velocity = glm::mix(m_Velocity, glm::vec2(0.0f), deltaTime * AIR_RESISTANCE);

    m_Position.x += m_Velocity.x;
    m_Position.y += m_Velocity.y;

    if(m_Position.y >= GROUND_HEIGHT)
    {
        m_Position.y = GROUND_HEIGHT;
        m_Velocity.y = 0.0f;
    }
}

void FrogSprite::Idle()
{
    UseSubTexture(m_IdleAnimation.Update().State, 0);

    m_Velocity.x = 0.0f;
}
