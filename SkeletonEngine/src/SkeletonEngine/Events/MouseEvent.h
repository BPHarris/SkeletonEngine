/**
 * @file    MouseEvent.h
 * @brief   SkeletonEngine mouse events.
 * 
 * @author  BP Harris
 * @date    July 2020
 */

#pragma once

#include "Event.h"


namespace SkeletonEngine {

	/** SkeletonEngine MouseButtonEvent base class. */
	class SE_API MouseButtonEvent : public Event
	{
	public:
		int m_Button;

	public:
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	
	protected:
		MouseButtonEvent(int button) : m_Button(button) {}
	};


	/** SkeletonEngine MouseButtonPressedEvent class. */
	class SE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		/** @return string  string representation of MouseButtonPressedEvent */
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent(" << m_Button << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};


	/** SkeletonEngine MouseButtonReleasedEvent class. */
	class SE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		/** @return string  string representation of MouseButtonReleasedEvent */
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent(" << m_Button << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};


	/** SkeletonEngine MouseMovedEvent class. */
	class SE_API MouseMovedEvent : public Event
	{
	private:
		float m_MouseX, m_MouseY;

	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

		/** @return string  string representation of MouseMovedEvent */
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent(" << m_MouseX << ", " << m_MouseY << ")";
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};


	/** SkeletonEngine MouseScrolledEvent class. */
	class SE_API MouseScrolledEvent : public Event
	{
	private:
		float m_XOffset, m_YOffset;

	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		/** @return string  string representation of MouseScrolledEvent */
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
