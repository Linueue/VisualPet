#pragma once

#include "SpriteGameObject.h"

#include <vector>
#include <memory>

namespace Engine
{
    class Scene
    {
    public:
        Scene() = default;

        template <typename T>
        void Push()
        {
            m_GameObjects.emplace_back(std::make_unique<T>());
            m_GameObjects[m_GameObjects.size() - 1]->Construct();
        }

        void Update(const float deltaTime);
        void Render();

    private:
        std::vector<std::unique_ptr<SpriteGameObject>> m_GameObjects;
    };
}
