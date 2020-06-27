/** WindowsWindow.cpp
 *
 * SkeletonEngine Windows Window implementation.
 */

#include "sepch.h"
#include "WindowsWindow.h"


namespace SkeletonEngine {

	static bool s_GLFWInitialized = false;


	/** Create a new WindowsWindow with the given properties */
	Window* Window::Create(const WindowProperties& porperties)
	{
		return new WindowsWindow(porperties);
	}


	WindowsWindow::WindowsWindow(const WindowProperties& p) { Init(p); }
	WindowsWindow::~WindowsWindow() { Shutdown(); }


	void WindowsWindow::Init(const WindowProperties& properties)
	{
		m_Data.Title = properties.Title;
		m_Data.Width = properties.Width;
		m_Data.Height = properties.Height;

		SE_CORE_INFO("Created new window \"{}\" ({}, {})",
			m_Data.Title, m_Data.Width, m_Data.Height);

		// Initalise GLFW
		if (!s_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			SE_CORE_ASSERT(success, "Could not initialise GLFW.");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(
			(int)m_Data.Width,
			(int)m_Data.Height,
			m_Data.Title.c_str(),
			nullptr,
			nullptr
		);

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
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
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}


	/** @return bool    true if VSync enabled, false otherwise */
	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}
