/** Application.cpp
 *
 * Basic SkeletonEngine Application.
 */

#include "sepch.h"
#include "Application.h"


namespace SkeletonEngine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)


	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}


	Application::~Application()
	{
	}


	/** Application Run method. */
	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}


	/** Event callback function */
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(OnWindowClose));

		SE_CORE_TRACE(e);
	}


	/** Handle WindowClosedEvent and set to handled (return true) */
	bool Application::OnWindowClose(WindowClosedEvent& e)
	{
		m_Running = false;
		return true;
	}
}
