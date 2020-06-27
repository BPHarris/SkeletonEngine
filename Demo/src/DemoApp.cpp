#include <SkeletonEngine.h>

class Demo : public SkeletonEngine::Application
{
public:
	Demo()
	{
		// Log example
		SE_WARN("An example WARN level log from client code.");
	}

	~Demo()
	{

	}

};

SkeletonEngine::Application* SkeletonEngine::CreateApplication()
{
	return new Demo();
}
