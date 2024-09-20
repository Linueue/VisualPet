#pragma once

#include "Engine/SpriteAnimation.h"
#include "Engine/GameLayer/SpriteGameObject.h"

enum class FrogState
{
    Idle,
};

class FrogSprite : public Engine::SpriteGameObject
{
public:
    using Engine::SpriteGameObject::SpriteGameObject;
    
    void Construct() override;
    void Update(const float deltaTime) override;

    void Idle();

private:
    FrogState m_State;
    Engine::SpriteAnimation m_IdleAnimation;
    glm::vec2 m_Velocity;
};
