
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_Events_Event.h:

Program Listing for File Event.h
================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_Events_Event.h>` (``SkeletonEngine\src\SkeletonEngine\Events\Event.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #pragma once
   
   #include "sepch.h"
   #include "SkeletonEngine/Core.h"
   
   namespace SkeletonEngine
   {
   
       /* Events in the SkeletonEngine are currently blocking.
        * 
        * At some point this should be changed to be buffered and processed in the
        * event phase of the update stage.
        */
   
       enum class EventType
       {
           None = 0,
   
           WindowClosed,           
           WindowResized,          
           WindowFocused,          
           WindowLostFocus,        
           WindowMoved,            
           AppTick,                
           AppUpdate,              
           AppRender,              
           KeyPressed,             
           KeyReleased,            
           MouseButtonPressed,     
           MouseButtonReleased,    
           MouseMoved,             
           MouseScrolled           
       };
   
       enum EventCategory
       {
           None = 0,
           EventCategoryApplication = BIT(0),  
           EventCategoryInput = BIT(1),        
           EventCategoryKeyboard = BIT(2),     
           EventCategoryMouse = BIT(3),        
           EventCategoryMouseButton = BIT(4)   
       };
   
   #define EVENT_CLASS_TYPE(type)                                                  \
       static EventType GetStaticType() { return EventType::##type; }              \
       virtual EventType GetEventType() const override { return GetStaticType(); } \
       virtual const char *GetName() const override { return #type; }
   
   #define EVENT_CLASS_CATEGORY(category) \
       virtual int GetCategoryFlags() const override { return category; }
   
       class SE_API Event
       {
           friend class EventDispatcher;
   
       public:
           bool Handled = false;
   
       public:
           virtual EventType GetEventType() const = 0;
   
           virtual const char *GetName() const = 0;
   
           virtual int GetCategoryFlags() const = 0;
   
           virtual std::string ToString() const { return GetName(); }
   
           inline bool IsInCategory(EventCategory category)
           {
               return GetCategoryFlags() & category;
           }
       };
   
       class EventDispatcher
       {
           template <typename T>
           using EventFn = std::function<bool(T &)>;
   
       private:
           Event &m_Event;
   
       public:
           EventDispatcher(Event &event) : m_Event(event) {}
   
           template <typename T>
           bool Dispatch(EventFn<T> func)
           {
               if (m_Event.GetEventType() == T::GetStaticType())
               {
                   m_Event.Handled = func(*(T *)&m_Event);
                   return true;
               }
               return false;
           }
       };
   
       inline std::ostream &operator<<(std::ostream &os, const Event &e)
       {
           return os << e.ToString();
       }
   
   }
