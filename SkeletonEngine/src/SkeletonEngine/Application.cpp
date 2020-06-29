/** Application.cpp
 *
 * Basic SkeletonEngine Application.
 */

#include "sepch.h"
#include "Application.h"

#include "SkeletonEngine/Events/ApplicationEvent.h"


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
		// Log example
		SE_CORE_INFO("An example INFO level log from engine code.");

		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}


	/** Event callback function */
	void Application::OnEvent(Event& e)
	{
		SE_CORE_INFO(e);
	}
}
