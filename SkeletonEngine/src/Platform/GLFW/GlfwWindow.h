/**
 * @file    GlfwWindow.h
 * @brief   
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#pragma once

#include "GLFW/glfw3.h"
#include "SkeletonEngine/Window.h"


namespace SkeletonEngine
{
    static bool g_GLFWInitialized = false;

    
    /** Error call back function, used by GLFW. */
    static void GLFWErrorCallback(int error, const char* description)
    {
        SE_CORE_ERROR("GLFW Error {}:{}", error, description);
    }

    
    class GlfwWindow : public Window
    {
    public:
        static const int VSYNC_ENABLED = 1;
        static const int VSYNC_DISABLED = 0;

        GlfwWindow(const WindowProperties& window_properties);
        virtual ~GlfwWindow();

        void OnUpdate() override;
        void Close() override;

        void SetEventCallback(const EventCallbackType& callback) override;
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;
        WindowProperties GetProperties() const override;

        std::string ToString() const override
        { 
            return "GlfwWindow(" + GetProperties().ToString() + ")";
        }

    private:
        GLFWwindow* glfw_window;
        void Init(const WindowProperties& p) override;

        void SetGlfwEventCallbacks();
    };

}
