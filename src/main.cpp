#include <iostream>

#include "Engine/Application.h"
#include "CatSprite.h"

class App : public Engine::Application
{
public:
    App()
    {
        CreateWindow( { "VisualPet", 800, 700, true } );
    }

    void Run() override
    {
        m_Scene.Push<CatSprite>();
        
        float deltaTime = 0.0f;

        while(!m_Window.ShouldClose())
        {
            m_Window.Clear();
            const float startTime = glfwGetTime();

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
