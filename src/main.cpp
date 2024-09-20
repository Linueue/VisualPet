#include <iostream>

#include "Engine/Application.h"
#include "Engine/Utils/Random.h"
#include "CatSprite.h"
#include "FrogSprite.h"
#include "PigSprite.h"

class App : public Engine::Application
{
public:
    App()
    {
        CreateWindow( { "VisualPet", 250, 250, true } );
    }

    void Run() override
    {
        const int32_t randSprite = Engine::Random::RandRange(0, 2);

        switch(randSprite)
        {
            case 0:
                m_Scene.Push<CatSprite>();
                break;
            case 1:
                m_Scene.Push<FrogSprite>();
                break;
            case 2:
                m_Scene.Push<PigSprite>();
                break;
        }
        
        float deltaTime = 0.0f;

        while(!m_Window.ShouldClose())
        {
            m_Window.Clear();
            const float startTime = glfwGetTime();

            if(glfwGetKey(m_Window.GetNativeWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
                m_Window.SetShouldClose(true);
            m_Scene.Update(deltaTime);
            m_Scene.Render();

            deltaTime = glfwGetTime() - startTime;
            m_Window.SwapBuffers();
            glfwPollEvents();
        }
    }
};

int main()
{
    std::unique_ptr<App> app = std::make_unique<App>();
    app->Run();

    return 0;
}
