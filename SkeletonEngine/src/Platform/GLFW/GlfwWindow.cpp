/**
 * @file    GlfwWindow.cpp
 * @brief   
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#include "sepch.h"
#include "GlfwWindow.h"

#include "SkeletonEngine/Events/ApplicationEvent.h"
#include "SkeletonEngine/Events/KeyEvent.h"
#include "SkeletonEngine/Events/MouseEvent.h"

#include "glad/glad.h"


namespace SkeletonEngine
{
    Window* Window::Create(const WindowProperties& p)
    {
        return new GlfwWindow(p);
    }


    GlfwWindow::GlfwWindow(const WindowProperties& p) { Init(p); }
    GlfwWindow::~GlfwWindow() { Close(); }
    

    void GlfwWindow::Init(const WindowProperties& p)
    {
        properties = WindowProperties(p.title, p.width, p.height);
        SE_CORE_INFO("Created Window: {}", ToString());

        if (!g_GLFWInitialized)
        {
            // TODO: glfwTerminate on system shutdown
            SE_CORE_ASSERT(glfwInit(), "Could not initialise GLFW.");
            glfwSetErrorCallback(GLFWErrorCallback);
            g_GLFWInitialized = true;
        }

        glfw_window = glfwCreateWindow(
            (int)p.width, (int)p.height, p.title.c_str(), nullptr, nullptr);

        glfwMakeContextCurrent(glfw_window);
        SE_CORE_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress),
            "Failed to initialise Glad.");
        glfwSetWindowUserPointer(glfw_window, &properties);

        SetVSync(p.vsync);
        SetGlfwEventCallbacks();
    }
    

    void GlfwWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(glfw_window);
    }
    

    void GlfwWindow::Close()
    {
        SE_CORE_INFO("Closed Window {0}", ToString());
        glfwDestroyWindow(glfw_window);
    }
    

    void GlfwWindow::SetEventCallback(const EventCallbackType& callback)
    { 
        properties.EventCallback = callback;
    }
    
    void GlfwWindow::SetVSync(bool enabled)
    {
        glfwSwapInterval((int)(properties.vsync = enabled));
    }
    
    bool GlfwWindow::IsVSync() const { return properties.vsync; }
    WindowProperties GlfwWindow::GetProperties() const { return properties; }


    void GlfwWindow::SetGlfwEventCallbacks()
    {
        // I AM THE META PROGRAMMER HAHAHAHHAHAHAHAHAAHAHAH
        // TODO: Maybe make this tolerable code, eh?
#define GET_WINDOW_PROPERTIES_AS(properties)        \
        WindowProperties& properties = *(WindowProperties*)glfwGetWindowUserPointer(window);

#define SET_EVENT_CALLBACK(Type, properties, ...)   \
        Type event(__VA_ARGS__);                    \
        properties.EventCallback(event);
#define SET_SIMPLE_EVENT_CALLBACK(Type, properties) \
        Type event;                                 \
        properties.EventCallback(event);

#define EVENT_CALLBACK(Type, properties, ...)       \
        GET_WINDOW_PROPERTIES_AS(properties)        \
        SET_EVENT_CALLBACK(Type, properties, __VA_ARGS__)
#define SIMPLE_EVENT_CALLBACK(Type, properties)     \
        GET_WINDOW_PROPERTIES_AS(properties)        \
        SET_SIMPLE_EVENT_CALLBACK(Type, properties)

        glfwSetWindowCloseCallback(glfw_window, [](GLFWwindow* window) {
                SIMPLE_EVENT_CALLBACK(WindowClosedEvent, window_properties)
            });
        
        glfwSetWindowSizeCallback(glfw_window, [](GLFWwindow* window, int width, int height) {
                GET_WINDOW_PROPERTIES_AS(window_properties)

                window_properties.width = width;
                window_properties.height = height;

                SET_EVENT_CALLBACK(WindowResizedEvent, window_properties, width, height)
            });

        glfwSetWindowFocusCallback(glfw_window, [](GLFWwindow* window, int focused) {
                GET_WINDOW_PROPERTIES_AS(window_properties)

                if (focused) { SET_SIMPLE_EVENT_CALLBACK(WindowFocusedEvent, window_properties)   }
                else         { SET_SIMPLE_EVENT_CALLBACK(WindowLostFocusEvent, window_properties) }
            });

        glfwSetWindowPosCallback(glfw_window, [](GLFWwindow* window, int x, int y) {
                EVENT_CALLBACK(WindowMovedEvent, window_properties, x, y)
            });

        glfwSetKeyCallback(
            glfw_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
                GET_WINDOW_PROPERTIES_AS(wp);

                switch (action)
                {
                    case GLFW_PRESS: {
                        SET_EVENT_CALLBACK(KeyPressedEvent, wp, key, KeyPressedEvent::JUST_PRESSED);
                        break;
                    }
                    case GLFW_RELEASE: {
                        SET_EVENT_CALLBACK(KeyReleasedEvent, wp, key);
                        break;
                    }
                    case GLFW_REPEAT: {
                        // TODO: Get actual repeat count, not just 1.
                        SET_EVENT_CALLBACK(KeyPressedEvent, wp, key, KeyPressedEvent::REPEATED);
                        break;
                    }
                }
            });

        glfwSetMouseButtonCallback(
            glfw_window, [](GLFWwindow* window, int button, int action, int mods) {
                GET_WINDOW_PROPERTIES_AS(window_properties)

                switch (action)
                {
                    case GLFW_PRESS: {
                        SET_EVENT_CALLBACK(MouseButtonPressedEvent, window_properties, button);
                        break;
                    }
                    case GLFW_RELEASE: {
                        SET_EVENT_CALLBACK(MouseButtonReleasedEvent, window_properties, button);
                        break;
                    }
                }
            });

        glfwSetCursorPosCallback(glfw_window, [](GLFWwindow* window, double x, double y) {
                EVENT_CALLBACK(MouseMovedEvent, window_properties, (float)x, (float)y)
            });

        glfwSetScrollCallback(glfw_window, [](GLFWwindow* window, double x_offset, double y_offset) {
                EVENT_CALLBACK(MouseScrolledEvent, window_properties, (float)x_offset, (float)y_offset)
            });
    }
}
