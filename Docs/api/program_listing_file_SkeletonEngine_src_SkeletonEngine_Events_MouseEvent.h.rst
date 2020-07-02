
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_Events_MouseEvent.h:

Program Listing for File MouseEvent.h
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_Events_MouseEvent.h>` (``SkeletonEngine\src\SkeletonEngine\Events\MouseEvent.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #pragma once
   
   #include "Event.h"
   
   
   namespace SkeletonEngine {
   
       class SE_API MouseButtonEvent : public Event
       {
       public:
           int m_Button;
   
       public:
           EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
       
       protected:
           MouseButtonEvent(int button) : m_Button(button) {}
       };
   
   
       class SE_API MouseButtonPressedEvent : public MouseButtonEvent
       {
       public:
           MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}
   
           std::string ToString() const override
           {
               std::stringstream ss;
               ss << "MouseButtonPressedEvent(" << m_Button << ")";
               return ss.str();
           }
   
           EVENT_CLASS_TYPE(MouseButtonPressed)
       };
   
   
       class SE_API MouseButtonReleasedEvent : public MouseButtonEvent
       {
       public:
           MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}
   
           std::string ToString() const override
           {
               std::stringstream ss;
               ss << "MouseButtonReleasedEvent(" << m_Button << ")";
               return ss.str();
           }
   
           EVENT_CLASS_TYPE(MouseButtonReleased)
       };
   
   
       class SE_API MouseMovedEvent : public Event
       {
       private:
           float m_MouseX, m_MouseY;
   
       public:
           MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}
   
           std::string ToString() const override
           {
               std::stringstream ss;
               ss << "MouseMovedEvent(" << m_MouseX << ", " << m_MouseY << ")";
               return ss.str();
           }
           
           EVENT_CLASS_TYPE(MouseMoved)
           EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
       };
   
   
       class SE_API MouseScrolledEvent : public Event
       {
       private:
           float m_XOffset, m_YOffset;
   
       public:
           MouseScrolledEvent(float xOffset, float yOffset)
               : m_XOffset(xOffset), m_YOffset(yOffset) {}
   
           std::string ToString() const override
           {
               std::stringstream ss;
               ss << "MouseScrolledEvent(" << m_XOffset << ", " << m_YOffset << ")";
               return ss.str();
           }
   
           EVENT_CLASS_TYPE(MouseScrolled)
           EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
       };
   
   }
