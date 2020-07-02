
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_Application.h:

Program Listing for File Application.h
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_Application.h>` (``SkeletonEngine\src\SkeletonEngine\Application.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #pragma once
   
   #include "Core.h"
   #include "SkeletonEngine/Window.h"
   #include "SkeletonEngine/Events/Event.h"
   #include "SkeletonEngine/Events/ApplicationEvent.h"
   
   
   namespace SkeletonEngine {
   
       class SE_API Application
       {
       private:
           bool m_Running = true;
       public:
           std::unique_ptr<Window> m_Window;
   
       public:
           Application();
           virtual ~Application();
   
           void Run();
   
           void OnEvent(Event& e);
       
       private:
           bool OnWindowClose(WindowClosedEvent& e);
       };
   
   
       Application* CreateApplication();
   
   }
