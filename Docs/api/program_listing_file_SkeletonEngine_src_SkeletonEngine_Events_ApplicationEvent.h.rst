
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_Events_ApplicationEvent.h:

Program Listing for File ApplicationEvent.h
===========================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_Events_ApplicationEvent.h>` (``SkeletonEngine\src\SkeletonEngine\Events\ApplicationEvent.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #pragma once
   
   #include "Event.h"
   
   
   namespace SkeletonEngine {
   
       class SE_API WindowClosedEvent : public Event
       {
       public:
           WindowClosedEvent() {}
   
           EVENT_CLASS_TYPE(WindowClosed)
           EVENT_CLASS_CATEGORY(EventCategoryApplication)
       };
   
   
       class SE_API WindowResizedEvent : public Event
       {
       public:
           unsigned int m_Width, m_Height;
   
       public:
           WindowResizedEvent(unsigned int width, unsigned int height)
               : m_Width(width), m_Height(height) {}
   
           std::string ToString() const override
           {
               std::stringstream ss;
               ss << "WindowResizedEvent(" << m_Width << ", " << m_Height << ")";
               return ss.str();
           }
   
           EVENT_CLASS_TYPE(WindowResized)
           EVENT_CLASS_CATEGORY(EventCategoryApplication)
       };
   
   
       class SE_API WindowFocusedEvent : public Event
       {
       public:
           WindowFocusedEvent() {}
   
           EVENT_CLASS_TYPE(WindowFocused)
           EVENT_CLASS_CATEGORY(EventCategoryApplication)
       };
   
   
       class SE_API WindowLostFocusEvent : public Event
       {
       public:
           WindowLostFocusEvent() {}
   
           EVENT_CLASS_TYPE(WindowLostFocus)
           EVENT_CLASS_CATEGORY(EventCategoryApplication)
       };
   
   
       class SE_API WindowMovedEvent : public Event
       {
       private:
           unsigned int m_X, m_Y;
   
       public:
           WindowMovedEvent(unsigned int x, unsigned int y) : m_X(x), m_Y(y) {}
   
           std::string ToString() const override
           {
               std::stringstream ss;
               ss << "WindowMovedEvent(" << m_X << ", " << m_Y << ")";
               return ss.str();
           }
   
           EVENT_CLASS_TYPE(WindowMoved)
           EVENT_CLASS_CATEGORY(EventCategoryApplication)
       };
   
   
       class SE_API AppTickEvent : public Event
       {
       public:
           AppTickEvent() {}
   
           EVENT_CLASS_TYPE(AppTick)
           EVENT_CLASS_CATEGORY(EventCategoryApplication)
       };
   
   
       class SE_API AppUpdateEvent : public Event
       {
       public:
           AppUpdateEvent() {}
   
           EVENT_CLASS_TYPE(AppUpdate)
           EVENT_CLASS_CATEGORY(EventCategoryApplication)
       };
   
   
       class SE_API AppRenderEvent : public Event
       {
       public:
           AppRenderEvent() {}
   
           EVENT_CLASS_TYPE(AppRender)
           EVENT_CLASS_CATEGORY(EventCategoryApplication)
       };
   
   }
