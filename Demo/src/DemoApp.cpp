#include <SkeletonEngine.h>

class Demo : public SkeletonEngine::Application
{
public:
	Demo()
	{

	}

	~Demo()
	{

	}

};

SkeletonEngine::Application* SkeletonEngine::CreateApplication()
{
	return new Demo();
}
