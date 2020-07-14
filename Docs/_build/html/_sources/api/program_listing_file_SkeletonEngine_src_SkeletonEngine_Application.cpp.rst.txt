
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_Application.cpp:

Program Listing for File Application.cpp
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_Application.cpp>` (``SkeletonEngine\src\SkeletonEngine\Application.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "sepch.h"
   
   #include "Log.h"
   #include "Application.h"
   
   #include <GLFW/glfw3.h>
   
   namespace SkeletonEngine
   {
   
   #define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
   
       Application::Application()
       {
           m_Window = std::unique_ptr<Window>(Window::Create());
           m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
       }
   
       Application::~Application() {}
   
       void Application::Run()
       {
           while (m_Running)
           {
               glClearColor(0.827, 0.329, 0.0, 1.0);
               glClear(GL_COLOR_BUFFER_BIT);
   
               for (auto layer : m_LayerStack)
                   layer->OnUpdate();
   
               m_Window->OnUpdate();
           }
       }
   
       void Application::PushLayer(Layer *layer)
       {
           m_LayerStack.PushLayer(layer);
       }
   
       void Application::PushOverlay(Layer *overlay)
       {
           m_LayerStack.PushOverlay(overlay);
       }
   
       void Application::OnEvent(Event &e)
       {
           EventDispatcher dispatcher(e);
           dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(OnWindowClose));
   
           for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
           {
               (*--it)->OnEvent(e);
               if (e.Handled)
                   break;
           }
       }
   
       bool Application::OnWindowClose(WindowClosedEvent &e)
       {
           m_Running = false;
           return true;
       }
   }
