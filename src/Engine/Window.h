#pragma once

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

        void SetPosition(const int32_t x, const int32_t y) const;

        static const glm::vec2 GetScreenSize();

        inline static const Window* GetCurrentWindow() { return s_CurrentWindow; }
        inline void SwapBuffers() const { glfwSwapBuffers(m_Window); }
        inline void SetShouldClose(const bool shouldClose) { glfwSetWindowShouldClose(m_Window, shouldClose); }
        inline const bool ShouldClose() const { return glfwWindowShouldClose(m_Window); }
        inline GLFWwindow* GetNativeWindow() const { return m_Window; }
        inline const int32_t GetWidth()  const { return m_Width; }
        inline const int32_t GetHeight() const { return m_Height; }

    private:
        static Window* s_CurrentWindow;
        GLFWwindow* m_Window;
        int32_t m_Width, m_Height;
    };
}
