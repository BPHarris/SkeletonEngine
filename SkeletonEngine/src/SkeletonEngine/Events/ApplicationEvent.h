/** ApplicationEvent.h
 *
 * SkeletonEngine Application events.
 */

#pragma once

#include "Event.h"

#include <sstream>


namespace SkeletonEngine {

	/** SkeletonEngine Window Closed Event class. */
	class SE_API WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
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
			ss << "WindowResizeEvent: (" << m_Width << ", " << m_Height << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width, m_Height;
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
