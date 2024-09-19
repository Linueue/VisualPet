#pragma once

#include <iostream>
#include <vector>

namespace Engine
{
    struct SpriteAnimationConfig
    {
        uint32_t State;
        float Duration;
    };

    struct SpriteAnimationOutput
    {
        uint32_t State;
        bool IsFinished;
    };

    class SpriteAnimation
    {
    public:
        SpriteAnimation();

        void AddAnimation(const SpriteAnimationConfig &animation);
        void AddAnimations(const std::vector<SpriteAnimationConfig> &animations);
        const SpriteAnimationOutput Update();

        void Reset();

    private:
        std::vector<SpriteAnimationConfig> m_Animations;
        float m_StartTime;
        size_t m_CurrentIdx;
    };
}
