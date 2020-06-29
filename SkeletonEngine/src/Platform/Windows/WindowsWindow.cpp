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

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)p.Width, (int)p.Height, p.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		/* Set GLFW Callbacks */
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.EventCallback(*(new WindowClosedEvent()));
			});

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
					case GLFW_PRESS:
						data.EventCallback(*(new KeyPressedEvent(key, KeyPressedEvent::JUST_PRESSED)));
						break;
					case GLFW_RELEASE:
						data.EventCallback(*(new KeyReleasedEvent(key)));
						break;
					case GLFW_REPEAT:
						// TODO: Get actual repeat count, instead of KeyPressedEvent::REPEATED placeholder
						data.EventCallback(*(new KeyPressedEvent(key, KeyPressedEvent::REPEATED)));
						break;
					}
			});
		
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
						data.EventCallback(*(new MouseButtonPressedEvent(button)));
						break;
					case GLFW_RELEASE:
						data.EventCallback(*(new MouseButtonReleasedEvent(button)));
						break;
				}
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.EventCallback(*(new MouseMovedEvent((float)x, (float)y)));
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.EventCallback(*(new MouseScrolledEvent((float)xoffset, (float)yoffset)));
			});
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
