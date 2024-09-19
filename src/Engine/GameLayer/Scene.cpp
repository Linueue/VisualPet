#include "Scene.h"

namespace Engine
{
    void Scene::Update(const float deltaTime)
    {
        for(const std::unique_ptr<SpriteGameObject> &sprite : m_GameObjects)
            sprite->Update(deltaTime);
    }

    void Scene::Render()
    {
        for(const std::unique_ptr<SpriteGameObject> &sprite : m_GameObjects)
            sprite->Render();
    }
}
