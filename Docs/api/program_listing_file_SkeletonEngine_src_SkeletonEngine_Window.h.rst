
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_Window.h:

Program Listing for File Window.h
=================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_Window.h>` (``SkeletonEngine\src\SkeletonEngine\Window.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #pragma once
   
   #include "sepch.h"
   
   #include "SkeletonEngine/Core.h"
   #include "SkeletonEngine/Events/Event.h"
   
   namespace SkeletonEngine
   {
   
       struct WindowProperties
       {
           std::string Title;
           unsigned int Width;
           unsigned int Height;
   
           WindowProperties(
                   const std::string &title = "SkeletonEngine",
                   unsigned int width = 1280,
                   unsigned int height = 720)
               : Title(title), Width(width), Height(height) {}
       };
   
       class SE_API Window
       {
       public:
           using EventCallbackFn = std::function<void(Event &)>;
   
           static Window *Create(const WindowProperties &p = WindowProperties());
           virtual ~Window() {}
   
           virtual void OnUpdate() = 0;
   
           virtual std::string GetTitle() const = 0;
           virtual unsigned int GetWidth() const = 0;
           virtual unsigned int GetHeight() const = 0;
   
           virtual std::string ToString() const { return "Window(\"" + GetTitle() + "\")"; }
   
           virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
           virtual void SetVSync(bool enabled) = 0;
           virtual bool IsVSync() const = 0;
       };
   
       inline std::ostream &operator<<(std::ostream &os, const Window &w)
       {
           return os << w.ToString();
       }
   }
