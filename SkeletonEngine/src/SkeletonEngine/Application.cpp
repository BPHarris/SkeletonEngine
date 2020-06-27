#include "sepch.h"
#include "Application.h"

#include "SkeletonEngine/Events/ApplicationEvent.h"


namespace SkeletonEngine {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}


	/** Application Run method. */
	void Application::Run()
	{
		/* Event log example */
		WindowResizedEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SE_TRACE(e);
		}

		while (true);
	}
}
