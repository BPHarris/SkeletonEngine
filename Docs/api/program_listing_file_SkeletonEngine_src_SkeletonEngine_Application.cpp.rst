
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_Application.cpp:

Program Listing for File Application.cpp
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_Application.cpp>` (``SkeletonEngine\src\SkeletonEngine\Application.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "sepch.h"
   #include "Application.h"
   
   
   namespace SkeletonEngine {
   
   #define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
   
   
       Application::Application()
       {
           m_Window = std::unique_ptr<Window>(Window::Create());
           m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
       }
   
   
       Application::~Application()
       {
       }
   
   
       void Application::Run()
       {
           while (m_Running)
           {
               m_Window->OnUpdate();
           }
       }
   
   
       void Application::OnEvent(Event& e)
       {
           EventDispatcher dispatcher(e);
   
           dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(OnWindowClose));
       }
   
   
       bool Application::OnWindowClose(WindowClosedEvent& e)
       {
           m_Running = false;
           return true;
       }
   }
