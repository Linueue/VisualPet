#include "Renderer.h"

#include <iostream>

namespace Engine
{
    struct WindowSpecs
    {
        const char* Title;
        const int32_t Width, Height;
        const bool Transparent;
    };

    class Window
    {
    public:
        Window() = default;
        ~Window();
        void Create(const WindowSpecs &windowSpecs);
        void Close();

        void Clear() const;

        inline void SwapBuffers() const { glfwSwapBuffers(m_Window); }
        inline const bool ShouldClose() const { return glfwWindowShouldClose(m_Window); }

    private:
        GLFWwindow* m_Window;
    };
}
