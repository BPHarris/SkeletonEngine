/** Application.cpp
 *
 * Basic SkeletonEngine Application.
 */

#include "sepch.h"
#include "Application.h"

#include "SkeletonEngine/Events/ApplicationEvent.h"


namespace SkeletonEngine {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
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
}
