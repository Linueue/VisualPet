#pragma once

#include "Engine/SpriteAnimation.h"
#include "Engine/GameLayer/SpriteGameObject.h"

enum class CatState
{
    Idle, Running,
};

class CatSprite : public Engine::SpriteGameObject
{
public:
    using Engine::SpriteGameObject::SpriteGameObject;
    
    void Construct() override;
    void Update(const float deltaTime) override;

    void Idle();
    void Running();

private:
    CatState m_State;
    Engine::SpriteAnimation m_IdleAnimation;
    Engine::SpriteAnimation m_RunningAnimation;
};
