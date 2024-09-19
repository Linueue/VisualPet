#include "SpriteAnimation.h"

#include "Renderer.h"

namespace Engine
{
    SpriteAnimation::SpriteAnimation()
        : m_CurrentIdx(0)
    {
    }

    void SpriteAnimation::AddAnimation(const SpriteAnimationConfig &animation)
    {
        m_Animations.emplace_back(animation);
    }

    void SpriteAnimation::AddAnimations(const std::vector<SpriteAnimationConfig> &animations)
    {
        for(const SpriteAnimationConfig &animation : animations)
        {
            m_Animations.emplace_back(animation);
        }
    }

    const SpriteAnimationOutput SpriteAnimation::Update()
    {
        const SpriteAnimationConfig& animation = m_Animations[m_CurrentIdx];

        const float currentTime = glfwGetTime();

        bool isFinished = (m_CurrentIdx == (m_Animations.size() - 1));

        if(currentTime - m_StartTime >= animation.Duration)
        {
            m_CurrentIdx = (m_CurrentIdx + 1) % m_Animations.size();
            m_StartTime = currentTime;
        }

        return { static_cast<uint32_t>(m_CurrentIdx), isFinished };
    }

    void SpriteAnimation::Reset()
    {
        m_StartTime = 0.0f;
        m_CurrentIdx = 0;
    }
}
