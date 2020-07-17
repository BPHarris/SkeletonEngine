/**
 * @file    Application.cpp
 * @brief   Basic SkeletonEngine Application.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#include "sepch.h"

#include "Log.h"
#include "Application.h"

#include <glad/glad.h>


namespace SkeletonEngine
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application* Application::application_singleton = nullptr;

    Application::Application()
    {
        SE_CORE_ASSERT(application_singleton == nullptr, "Application already exists!");
        application_singleton = this;

        window = Window::Create();
        window ->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application() { delete window; }

    void Application::Run()
    {
        while (running)
        {
            glClearColor(0.827, 0.329, 0.0, 1.0);
            glClear(GL_COLOR_BUFFER_BIT);

            for (auto layer : layer_stack)
                layer->OnUpdate();

            window->OnUpdate();
        }
    }

    void Application::PushLayer(Layer *layer)
    {
        layer_stack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *overlay)
    {
        layer_stack.PushOverlay(overlay);
        overlay->OnAttach();
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(OnWindowClose));

        for (auto it = layer_stack.end(); it != layer_stack.begin();)
        {
            (*--it)->OnEvent(e);
            if (e.is_handled)
                break;
        }
    }

    bool Application::OnWindowClose(WindowClosedEvent &e)
    {
        running = false;
        return true;
    }
}
