/** ApplicationEvent.h
 *
 * SkeletonEngine Application events.
 */

#pragma once

#include "Event.h"


namespace SkeletonEngine {

	/** SkeletonEngine Window Closed Event class. */
	class SE_API WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() {}

		EVENT_CLASS_TYPE(WindowClosed)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	/** SkeletonEngine Window Resized Event class. */
	class SE_API WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width;  }
		inline unsigned int GetHeight() const { return m_Height; }

		/** @return string  string representation of WindowResizedEvent */
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizedEvent: (" << m_Width << ", " << m_Height << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResized)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width, m_Height;
	};


	/** SkeletonEngine Window Focused Event class. */
	class SE_API WindowFocusedEvent : public Event
	{
	public:
		WindowFocusedEvent() {}

		EVENT_CLASS_TYPE(WindowFocused)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	/** SkeletonEngine Window Lost Focus Event class. */
	class SE_API WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() {}

		EVENT_CLASS_TYPE(WindowLostFocus)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	/** SkeletonEngine Window Lost Focus Event class. */
	class SE_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(unsigned int x, unsigned int y) : m_X(x), m_Y(y) {}

		inline unsigned int GetX() const { return m_X; }
		inline unsigned int GetY() const { return m_Y; }

		/** @return string  string representation of WindowMovedEvent */
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowMovedEvent: (" << m_X << ", " << m_Y << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_X, m_Y;
	};


	/** SkeletonEngine App Tick Event class. */
	class SE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	/** SkeletonEngine App Update Event class. */
	class SE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	/** SkeletonEngine App Render Event class. */
	class SE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}
