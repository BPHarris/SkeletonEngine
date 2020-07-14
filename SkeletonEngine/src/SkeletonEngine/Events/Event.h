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

    /* Events in the SkeletonEngine are currently blocking.
	 * 
	 * At some point this should be changed to be buffered and processed in the
	 * event phase of the update stage.
	 */

    /** SkeletonEngine EventType. */
    enum class EventType
    {
        None = 0,

        WindowClosed,           /**< Window closed. */
        WindowResized,          /**< Window resized. */
        WindowFocused,          /**< Window gained focused. */
        WindowLostFocus,        /**< Window lost focus. */
        WindowMoved,            /**< Window moved. */

        AppTick,                /**< Application tick. */
        AppUpdate,              /**< Application update. */
        AppRender,              /**< Application render. */

        KeyPressed,             /**< Key pressed (or repeated). */
        KeyReleased,            /**< Key released. */

        MouseButtonPressed,     /**< Mouse clicked/mouse button pressed. */
        MouseButtonReleased,    /**< Mouse unclicked/mouse button released. */
        MouseMoved,             /**< Mouse moved. */
        MouseScrolled           /**< Mouse scolled up/down. */
    };

    /** SkeletonEngine EventCategory */
    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),  /**< Application events */
        EventCategoryInput = BIT(1),        /**< Input events */
        EventCategoryKeyboard = BIT(2),     /**< Keyboard events */
        EventCategoryMouse = BIT(3),        /**< Mouse events */
        EventCategoryMouseButton = BIT(4)   /**< Mouse button events */
    };

#define EVENT_CLASS_TYPE(type)                                                  \
    static EventType GetStaticType() { return EventType::##type; }              \
    virtual EventType GetEventType() const override { return GetStaticType(); } \
    virtual const char *GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
    virtual int GetCategoryFlags() const override { return category; }

    /** SkeletonEngine Event class. */
    class SE_API Event
    {
        friend class EventDispatcher;

    public:
        bool Handled = false;

    public:
        /** @return    The Event's EventType. */
        virtual EventType GetEventType() const = 0;

        /** @return    The Event name. */
        virtual const char *GetName() const = 0;

        /** @return    The Event's GetCategoryFlags. */
        virtual int GetCategoryFlags() const = 0;

        /** @return    The string representation of the Event. */
        virtual std::string ToString() const { return GetName(); }

        /**
		 * Check if this Event is in the given category.
		 * 
		 * @param   category    The category to check against.
		 * @return              true if the Event is in the the EventCategory
		 * @return              false otherwise
		 */
        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }
    };

    /** SkeletonEngine EventDispatcher template class. */
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
