/** Application.h
 *
 * Basic SkeletonEngine Application interface.
 */

#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"


namespace SkeletonEngine {

	/** SkeletonEngine Log class. */
	class SE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	/** To be defined in client application. */
	Application* CreateApplication();

}
