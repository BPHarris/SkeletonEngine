/**
 * @file    DemoApp.cpp
 * @brief   The demo application.
 * 
 * @author  BP Harris
 * @date    July 2020
 */

#include <SkeletonEngine.h>


class DebugLayer : public SkeletonEngine::Layer
{
public:
    DebugLayer() : Layer("DebugLayer") {}

    
    ~DebugLayer() {}


    void OnEvent(SkeletonEngine::Event &event) override
    {
        SE_TRACE("{0}", event);
    }

};


/** The Demo application. */
class Demo : public SkeletonEngine::Application
{
public:
    Demo()
    {
        PushLayer(new DebugLayer());
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
