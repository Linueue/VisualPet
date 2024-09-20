#pragma once

#include "Engine/SpriteAnimation.h"
#include "Engine/GameLayer/SpriteGameObject.h"

enum class PigState
{
    Idle, Running,
};

class PigSprite : public Engine::SpriteGameObject
{
public:
    using Engine::SpriteGameObject::SpriteGameObject;
    
    void Construct() override;
    void Update(const float deltaTime) override;

    void Idle();
    void Running();

private:
    PigState m_State;
    Engine::SpriteAnimation m_IdleAnimation;
    Engine::SpriteAnimation m_RunningAnimation;
    glm::vec2 m_Velocity;
    int32_t m_RandomCycle;
};
