#pragma once

#include "Core.h"
#include "Events/Event.h"


namespace SkeletonEngine {

	/** SkeletonEngine Log class. */
	class SE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	/** To be defined in client application. */
	Application* CreateApplication();

}
