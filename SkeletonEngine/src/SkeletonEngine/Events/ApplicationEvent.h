/**
 * @file    ApplicationEvent.h
 * @brief   SkeletonEngine Application events.
 * 
 * @author  BP Harris
 * @date    July 2020
 */

#pragma once

#include "Event.h"


namespace SkeletonEngine {

	/** SkeletonEngine WindowClosedEvent class. */
	class SE_API WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() {}

		EVENT_CLASS_TYPE(WindowClosed)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	/** SkeletonEngine WindowResizedEvent class. */
	class SE_API WindowResizedEvent : public Event
	{
	public:
		unsigned int m_Width, m_Height;

	public:
		WindowResizedEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		/** @return std::string     string representation of WindowResizedEvent. */
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizedEvent(" << m_Width << ", " << m_Height << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResized)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	/** SkeletonEngine WindowFocusedEvent class. */
	class SE_API WindowFocusedEvent : public Event
	{
	public:
		WindowFocusedEvent() {}

		EVENT_CLASS_TYPE(WindowFocused)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	/** SkeletonEngine WindowLostFocusEvent class. */
	class SE_API WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() {}

		EVENT_CLASS_TYPE(WindowLostFocus)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	/** SkeletonEngine WindowLostFocusEvent class. */
	class SE_API WindowMovedEvent : public Event
	{
	private:
		unsigned int m_X, m_Y;

	public:
		WindowMovedEvent(unsigned int x, unsigned int y) : m_X(x), m_Y(y) {}

		/** @return string  string representation of WindowMovedEvent */
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowMovedEvent(" << m_X << ", " << m_Y << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	/** SkeletonEngine AppTickEvent class. */
	class SE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	/** SkeletonEngine AppUpdateEvent class. */
	class SE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	/** SkeletonEngine AppRenderEvent class. */
	class SE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}
