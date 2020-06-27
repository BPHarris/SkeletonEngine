/** Event.h
 *
 * SkeletonEngine event system.
 */

#pragma once

#include "SkeletonEngine/Core.h"

#include <string>
#include <functional>


namespace SkeletonEngine {

	/* Events in the SkeletonEngine are currently blocking.
	 * 
	 * At some point this should be changed to be buffered and processed in the
	 * event phase of the update stage.
	 */

	/** SkeletonEngine Event Type */
	enum class EventType
	{
		None = 0,
		
		/* Window Events */
		WindowClosed,
		WindowResized,
		WindowFocused,		/* TODO: Create event class */
		WindowLostFocus,	/* TODO: Create event class */
		WindowMoved,		/* TODO: Create event class */

		/* Application Events */
		AppTick,
		AppUpdate,
		AppRender,

		/* Keyboard Events */
		KeyPressed,
		KeyReleased,

		/* Mouse Events */
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};


	/** SkeletonEngine Event Category */
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication    = BIT(0),
		EventCategoryInput	        = BIT(1),
		EventCategoryKeyboard       = BIT(2),
		EventCategoryMouse          = BIT(3),
		EventCategoryMouseButton    = BIT(4)
	};


#define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


	/** SkeletonEngine Event class. */
	class SE_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		/** @return bool    true if in given category, false otherwise */
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		bool m_Handled = false;
	};


	/** SkeletonEngine Event Dispatcher class. */
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event) : m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	
	private:
		Event& m_Event;
	};


	/** To string operator overloading. */
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}
