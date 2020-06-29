/** Application.h
 *
 * Basic SkeletonEngine Application interface.
 */

#pragma once

#include "Core.h"
#include "SkeletonEngine/Window.h"
#include "SkeletonEngine/Events/Event.h"
#include "SkeletonEngine/Events/ApplicationEvent.h"


namespace SkeletonEngine {

	/** SkeletonEngine Log class. */
	class SE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	
	private:
		bool OnWindowClose(WindowClosedEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	/** To be defined in client application. */
	Application* CreateApplication();

}
