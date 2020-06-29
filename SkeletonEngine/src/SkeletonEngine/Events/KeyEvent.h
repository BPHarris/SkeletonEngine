/** KeyEvent.h
 *
 * SkeletonEngine keyboard events.
 */

#pragma once

#include "Event.h"


namespace SkeletonEngine {

	/** SkeletonEngine Key Event base class. */
	class SE_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	
	protected:
		int m_KeyCode;

		KeyEvent(int keycode) : m_KeyCode(keycode) {}
	};


	/** SkeletonEngine Key Pressed Event class. */
	class SE_API KeyPressedEvent : public KeyEvent
	{
	public:
		static const int JUST_PRESSED = 0;
		static const int REPEATED = 1;

		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }
		inline bool IsJustPressed() const { return !m_RepeatCount; }

		/** @return string  string representation of KeyPressedEvent */
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


	/** SkeletonEngine Key Pressed Event class. */
	class SE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		/** @return string  string representation of KeyReleasedEvent */
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
	
}
