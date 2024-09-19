#include "Window.h"

namespace Engine
{
    Window::~Window()
    {
        Close();
    }

    void Window::Create(const WindowSpecs &windowSpecs)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        if(windowSpecs.Transparent)
        {
            glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
            glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
        }

        m_Window = glfwCreateWindow(windowSpecs.Width, windowSpecs.Height, windowSpecs.Title, NULL, NULL);

        if(m_Window == NULL)
        {
            std::cerr << "Engine (Window): Could not create Window.\n";
            Renderer::DeInit();
        }

        glfwMakeContextCurrent(m_Window);

        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        glfwSwapInterval(1);
    }

    void Window::Close()
    {
        glfwDestroyWindow(m_Window);
    }

    void Window::Clear() const
    {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}
