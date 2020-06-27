/** EntryPoint.h -- Contains SkeletonEngine program entry point. */

#pragma once


#ifdef SE_PLATFORM_WINDOWS

extern SkeletonEngine::Application* SkeletonEngine::CreateApplication();

int main(int argc, char** argv)
{
	SkeletonEngine::Log::Init();
	SE_CORE_WARN("Initialised!");
	SE_ERROR("An error occurdedd.");

	auto app = SkeletonEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // SE_PLATFORM_WINDOWS

