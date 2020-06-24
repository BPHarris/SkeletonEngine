#pragma once

#ifdef SE_PLATFORM_WINDOWS

extern SkeletonEngine::Application* SkeletonEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = SkeletonEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // SE_PLATFORM_WINDOWS

