/**
 * @file    WindowsWindow.h
 * @brief   SkeletonEngine Windows Window interface.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#pragma once

#include "SkeletonEngine/Window.h"

#include <GLFW/glfw3.h>

namespace SkeletonEngine
{

    /** SkeletonEngine WindowsWindow class. */
    class WindowsWindow : public Window
    {
    public:
        static const int VSYNC_ENABLED = 1;
        static const int VSYNC_DISABLED = 0;

        /** Pointer to underlying GLFW Window. */
        GLFWwindow* m_Window;

    private:
        struct WindowData
        {
            std::string Title;
            unsigned int Width;
            unsigned int Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;

    private:
        virtual void Init(const WindowProperties &properties);

    public:
        WindowsWindow(const WindowProperties &properties);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        virtual std::string GetTitle() const override { return m_Data.Title; }
        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }

        /** @return string  string representation of the window */
        std::string ToString() const override
        {
            std::stringstream ss;

            ss << "WindowsWindow("
               << "\"" << GetTitle() << "\""
               << ", "
               << GetWidth() << ", "
               << GetHeight()
               << (IsVSync() ? ", VSync" : "")
               << ")";

            return ss.str();
        }

        inline void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

        virtual void Close();
    };

}
