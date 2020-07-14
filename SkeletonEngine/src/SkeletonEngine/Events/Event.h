/**
 * @file    Event.h
 * @brief   SkeletonEngine event system.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#pragma once

#include "sepch.h"
#include "SkeletonEngine/Core.h"


namespace SkeletonEngine
{
    // NOTE: Events in the SkeletonEngine are currently blocking.
    // TODO: Buffer events and process in event phase of update.
	

    /** SkeletonEngine EventType. */
    enum class EventType
    {
        None = 0,
        WindowClosed, WindowResized, WindowFocused, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
    };


    /** SkeletonEngine EventCategory, not mutually exclusive. */
    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),  /**< Application/window events */
        EventCategoryInput = BIT(1),        /**< Input events */
        EventCategoryKeyboard = BIT(2),     /**< Keyboard events */
        EventCategoryMouse = BIT(3),        /**< Mouse events */
        EventCategoryMouseButton = BIT(4)   /**< Mouse button events */
    };


#define EVENT(event_type, category)     Event(EventType::event_type, #event_type, category)
#define EVENT_STATIC_TYPE(event_type)   static EventType GetStaticType() { return EventType::event_type; }


    /** SkeletonEngine Event "interface". */
    class SE_API Event
    {
        friend class EventDispatcher;

    public:
        bool is_handled = false;

        EventType type;
        std::string name;
        int category_flags;

        Event(EventType type, std::string name, int category_flags)
            : type(type), name(name), category_flags(category_flags) {}

        /** @return true if the Event is in the given EventCategory, false otherwise. */
        inline bool IsInCategory(EventCategory category) { return category_flags & category; }

        /** @return string representation of the Event. */
        virtual std::string ToString() const { return name; }
    };


    /** SkeletonEngine EventDispatcher template class. */
    class EventDispatcher
    {
        template <typename T>
        using EventFn = std::function<bool(T &)>;

    private:
        Event &event;

    public:
        EventDispatcher(Event &event) : event(event) {}

        template <typename T>
        bool Dispatch(EventFn<T> func)
        {
            if (event.type == T::GetStaticType())
            {
                event.is_handled = func(*(T *)&event);
                return true;
            }
            return false;
        }
    };


    /**
	 * Operator overload for << and Event.
	 * 
	 * @param os    Left-hand side.
	 * @param e     An Event instance.
	 * @return      String concatination of os and e.
	 */
    inline std::ostream &operator<<(std::ostream &os, const Event &e)
    {
        return os << e.ToString();
    }

}
