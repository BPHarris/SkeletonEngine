
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
           inline int GetKeyCode() const { return m_KeyCode; }
   
           EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
       
       protected:
           int m_KeyCode;
   
           KeyEvent(int keycode) : m_KeyCode(keycode) {}
       };
   
   
       class SE_API KeyPressedEvent : public KeyEvent
       {
       public:
           static const int JUST_PRESSED = 0;
           static const int REPEATED = 1;
   
           KeyPressedEvent(int keycode, int repeatCount)
               : KeyEvent(keycode), m_RepeatCount(repeatCount) {}
   
           inline int GetRepeatCount() const { return m_RepeatCount; }
           inline bool IsJustPressed() const { return !m_RepeatCount; }
   
           std::string ToString() const override
           {
               std::stringstream ss;
               ss << "KeyPressedEvent: " << m_KeyCode << " (" << ((IsJustPressed()) ? ("IsJustPressed") : ("Repeated")) << ")";
               return ss.str();
           }
   
           EVENT_CLASS_TYPE(KeyPressed)
       private:
           int m_RepeatCount;
       };
   
   
       class SE_API KeyReleasedEvent : public KeyEvent
       {
       public:
           KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}
   
           std::string ToString() const override
           {
               std::stringstream ss;
               ss << "KeyReleasedEvent: " << m_KeyCode;
               return ss.str();
           }
   
           EVENT_CLASS_TYPE(KeyReleased)
       };
       
   }
