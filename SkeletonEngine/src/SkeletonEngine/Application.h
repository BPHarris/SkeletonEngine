#pragma once

#include "Core.h"

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
