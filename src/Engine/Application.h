#pragma once

#include "Window.h"
#include "GameLayer/Scene.h"

namespace Engine
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void CreateWindow(const WindowSpecs &windowSpecs);
        virtual void Run() = 0;

    protected:
        Window m_Window;
        Scene m_Scene;
    };
}
