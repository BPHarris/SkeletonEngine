/**
 * @file    Application.h
 * @brief   Basic SkeletonEngine Application interface.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"


namespace SkeletonEngine
{
    /** SkeletonEngine Application class. */
    class SE_API Application
    {
    public:
        Window* window;

        Application();
        virtual ~Application();

        /** Begin Application mainloop. */
        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

        inline static Application& Get() { return *application_singleton; }

    private:
        bool running = true;
        LayerStack layer_stack;
        static Application* application_singleton;

        /**
         * Handle a WindowClosedEvent.
         *
         * @return true if the event has been handled, false otherwise
         */
        bool OnWindowClose(WindowClosedEvent& e);
    };

    
    /** To be defined in client application. */
    Application *CreateApplication();

    
    /** @return a pointer to the main application window. */
    inline static Window* GetMainWindow()
    {
        return Application::Get().window;
    }

}
