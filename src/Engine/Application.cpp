#include "Application.h"

namespace Engine
{
    Application::Application()
    {
        Renderer::Init();
    }

    Application::~Application()
    {
        Renderer::DeInit();
    }

    void Application::CreateWindow(const WindowSpecs &windowSpecs)
    {
        m_Window.Create(windowSpecs);
    }
}
