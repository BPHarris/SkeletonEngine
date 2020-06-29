/** WindowsWindow.cpp
 *
 * SkeletonEngine Windows Window implementation.
 */

#include "sepch.h"
#include "WindowsWindow.h"

#include "SkeletonEngine/Events/ApplicationEvent.h"
#include "SkeletonEngine/Events/KeyEvent.h"
#include "SkeletonEngine/Events/MouseEvent.h"


namespace SkeletonEngine {

	static bool s_GLFWInitialized = false;


	/** GLFW error callback function */
	static void GLFWErrorCallback(int error, const char* description)
	{
		SE_CORE_ERROR("GLFW Error {}:{}", error, description);
	}


	/** Create a new WindowsWindow with the given properties */
	Window* Window::Create(const WindowProperties& porperties)
	{
		return new WindowsWindow(porperties);
	}


	WindowsWindow::WindowsWindow(const WindowProperties& p) { Init(p); }
	WindowsWindow::~WindowsWindow() { Shutdown(); }


	void WindowsWindow::Init(const WindowProperties& p)
	{
		m_Data.Title = p.Title;
		m_Data.Width = p.Width;
		m_Data.Height = p.Height;

		SE_CORE_INFO("Created new window \"{}\" ({}, {})", p.Title, p.Width, p.Height);

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
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		/* Set GLFW event callbacks */
#define SIMPLE_EVENT(type, ...)					WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);\
												data.EventCallback(*(new type(__VA_ARGS__)));
#define EVENT_CASE(event_case, type, ...)		case event_case: data.EventCallback(*(new type(__VA_ARGS__))); break;

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{ SIMPLE_EVENT(WindowClosedEvent); });

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
				
				data.Width = width;
				data.Height = height;
				data.EventCallback(*(new WindowResizedEvent(width, height)));
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					EVENT_CASE(GLFW_PRESS, KeyPressedEvent, key, KeyPressedEvent::JUST_PRESSED);
					EVENT_CASE(GLFW_RELEASE, KeyReleasedEvent, key);
					// TODO: Get actual repeat count, instead of KeyPressedEvent::REPEATED placeholder
					EVENT_CASE(GLFW_REPEAT, KeyPressedEvent, key, KeyPressedEvent::REPEATED);
				}
			});
		
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					EVENT_CASE(GLFW_PRESS, MouseButtonPressedEvent, button);
					EVENT_CASE(GLFW_RELEASE, MouseButtonReleasedEvent, button);
				}
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y)
			{ SIMPLE_EVENT(MouseMovedEvent, (float)x, (float)y); });

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
			{ SIMPLE_EVENT(MouseScrolledEvent, (float)xoffset, (float)yoffset); });
	}


	/** Handle Window Shutdown Event */
	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}


	/** Handle Window Update */
	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}


	/** SetVSync to the given setting */
	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(VSYNC_ENABLED);
		else
			glfwSwapInterval(VSYNC_DISABLED);

		m_Data.VSync = enabled;
	}


	/** @return bool    true if VSync enabled, false otherwise */
	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}
