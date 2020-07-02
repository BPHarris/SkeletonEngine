
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_Events_KeyEvent.h:

Program Listing for File KeyEvent.h
===================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_Events_KeyEvent.h>` (``SkeletonEngine\src\SkeletonEngine\Events\KeyEvent.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #pragma once
   
   #include "Event.h"
   
   
   namespace SkeletonEngine {
   
       class SE_API KeyEvent : public Event
       {
       public:
           int m_Keycode;
   
       public:
           EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
       
       protected:
           KeyEvent(int keycode) : m_Keycode(keycode) {}
       };
   
   
       class SE_API KeyPressedEvent : public KeyEvent
       {
       public:
           int m_RepeatCount;
   
       public:
           static const int JUST_PRESSED = 0;
           static const int REPEATED = 1;
   
           KeyPressedEvent(int keycode, int repeatCount)
               : KeyEvent(keycode), m_RepeatCount(repeatCount) {}
   
           inline bool IsJustPressed() const { return !m_RepeatCount; }
   
           std::string ToString() const override
           {
               std::stringstream ss;
   
               if (IsJustPressed())
                   ss << "KeyPressedEvent(" << m_Keycode << ", IsJustPressed)";
               else
                   ss << "KeyPressedEvent(" << m_Keycode << ", Repeats=" << m_RepeatCount << ")";
   
               return ss.str();
           }
   
           EVENT_CLASS_TYPE(KeyPressed)
       };
   
   
       class SE_API KeyReleasedEvent : public KeyEvent
       {
       public:
           KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}
   
           std::string ToString() const override
           {
               std::stringstream ss;
               ss << "KeyReleasedEvent(" << m_Keycode << ")";
               return ss.str();
           }
   
           EVENT_CLASS_TYPE(KeyReleased)
       };
       
   }
