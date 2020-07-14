/**
 * @file    DemoApp.cpp
 * @brief   The demo application.
 * 
 * @author  BP Harris
 * @date    July 2020
 */

#include <SkeletonEngine.h>

/** The Demo application. */
class Demo : public SkeletonEngine::Application
{
public:
    Demo()
    {
        PushOverlay(new SkeletonEngine::ImGuiLayer());
    }

    ~Demo()
    {
    }
};

/** @return SkeletonEngine::Application*    The Application to run. */
SkeletonEngine::Application *SkeletonEngine::CreateApplication()
{
    return new Demo();
}
