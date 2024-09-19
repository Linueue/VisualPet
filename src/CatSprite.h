#pragma once

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

private:
    CatState m_State;
    uint32_t idx;
};
