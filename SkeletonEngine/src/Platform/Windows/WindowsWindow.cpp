/**
 * @file    WindowsWindow.cpp
 * @brief   WindowsWindow implementation.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#include "sepch.h"
#include "Platform/Windows/WindowsWindow.h"

#include "SkeletonEngine/Events/ApplicationEvent.h"
#include "SkeletonEngine/Events/KeyEvent.h"
#include "SkeletonEngine/Events/MouseEvent.h"

#include "glad/glad.h"


namespace SkeletonEngine
{

    /** State of GLFW initialisation. */
    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char *description)
    {
        SE_CORE_ERROR("GLFW Error {}:{}", error, description);
    }

    void WindowsWindow::Init(const WindowProperties &p)
    {
        m_Data.Title = p.Title;
        m_Data.Width = p.Width;
        m_Data.Height = p.Height;

        SE_CORE_INFO("Created new window {}", ToString());

        // Initalise GLFW
        if (!s_GLFWInitialized)
        {
            // TODO: glfwTerminate on system shutdown
            int success = glfwInit();
            SE_CORE_ASSERT(success, "Could not initialise GLFW.");

            glfwSetErrorCallback(GLFWErrorCallback);

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)p.Width, (int)p.Height, p.Title.c_str(), nullptr, nullptr);
        
        glfwMakeContextCurrent(m_Window);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        SE_CORE_ASSERT(status, "Failed to initialise Glad.");
        
        glfwSetWindowUserPointer(m_Window, &m_Data);

        SetVSync(true);

        /* GLFW Window callback macros */
#define GET_WINDOW_DATA_AS(data) WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
#define SET_EVENT_CALLBACK(Type, data, ...) \
    Type event(__VA_ARGS__);                \
    data.EventCallback(event);
#define SET_SIMPLE_CALLBACK(Type, data) \
    Type event;                         \
    data.EventCallback(event);

        /* Set GLFW event callbacks */
        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window) {
            GET_WINDOW_DATA_AS(data);
            SET_SIMPLE_CALLBACK(WindowClosedEvent, data);
        });

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) {
            GET_WINDOW_DATA_AS(data);

            // Set width/height before callback so that handler has correct values
            data.Width = width;
            data.Height = height;

            SET_EVENT_CALLBACK(WindowResizedEvent, data, width, height);
        });

        glfwSetWindowFocusCallback(m_Window, [](GLFWwindow *window, int focused) {
            GET_WINDOW_DATA_AS(data);

            if (focused)
            {
                SET_SIMPLE_CALLBACK(WindowFocusedEvent, data);
            }
            else
            {
                SET_SIMPLE_CALLBACK(WindowLostFocusEvent, data);
            }
        });

        glfwSetWindowPosCallback(m_Window, [](GLFWwindow *window, int x, int y) {
            GET_WINDOW_DATA_AS(data);
            SET_EVENT_CALLBACK(WindowMovedEvent, data, x, y);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            GET_WINDOW_DATA_AS(data);

            switch (action)
            {
            case GLFW_PRESS:
            {
                SET_EVENT_CALLBACK(KeyPressedEvent, data, key, KeyPressedEvent::JUST_PRESSED);
                break;
            }
            case GLFW_RELEASE:
            {
                SET_EVENT_CALLBACK(KeyReleasedEvent, data, key);
                break;
            }
            case GLFW_REPEAT:
            {
                // TODO: Get actual repeat count, instead of KeyPressedEvent::REPEATED placeholder
                SET_EVENT_CALLBACK(KeyPressedEvent, data, key, KeyPressedEvent::REPEATED);
                break;
            }
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods) {
            GET_WINDOW_DATA_AS(data);

            switch (action)
            {
            case GLFW_PRESS:
            {
                SET_EVENT_CALLBACK(MouseButtonPressedEvent, data, button);
                break;
            }
            case GLFW_RELEASE:
            {
                SET_EVENT_CALLBACK(MouseButtonReleasedEvent, data, button);
                break;
            }
            }
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double x, double y) {
            GET_WINDOW_DATA_AS(data);
            SET_EVENT_CALLBACK(MouseMovedEvent, data, (float)x, (float)y)
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xoffset, double yoffset) {
            GET_WINDOW_DATA_AS(data);
            SET_EVENT_CALLBACK(MouseScrolledEvent, data, (float)xoffset, (float)yoffset)
        });
    }

    Window *Window::Create(const WindowProperties &porperties)
    {
        return new WindowsWindow(porperties);
    }

    WindowsWindow::WindowsWindow(const WindowProperties &p) { Init(p); }
    WindowsWindow::~WindowsWindow() { Close(); }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        glfwSwapInterval(enabled ? VSYNC_ENABLED : VSYNC_DISABLED);
        m_Data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return m_Data.VSync;
    }

    void WindowsWindow::Close()
    {
        SE_CORE_INFO("Closed window {}", ToString());
        glfwDestroyWindow(m_Window);
    }
}
