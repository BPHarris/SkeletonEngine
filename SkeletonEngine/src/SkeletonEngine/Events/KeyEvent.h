/**
 * @file    KeyEvent.h
 * @brief   SkeletonEngine keyboard events.
 * 
 * @author  BP Harris
 * @date    July 2020
 */

#pragma once

#include "Event.h"


namespace SkeletonEngine {

	/** SkeletonEngine KeyEvent base class. */
	class SE_API KeyEvent : public Event
	{
	public:
		int m_Keycode;

	public:
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	
	protected:
		KeyEvent(int keycode) : m_Keycode(keycode) {}
	};


	/** SkeletonEngine KeyPressedEvent class. */
	class SE_API KeyPressedEvent : public KeyEvent
	{
	public:
		int m_RepeatCount;

	public:
		static const int JUST_PRESSED = 0;
		static const int REPEATED = 1;

		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		/**
		 * Check if the key has just been pressed or if it is a repeated key.
		 * 
		 * @return  true if the key was just pressed.
		 * @return  false otherwise (key is a repeat).
		 */
		inline bool IsJustPressed() const { return !m_RepeatCount; }

		/** @return string  string representation of KeyPressedEvent */
		std::string ToString() const override
		{
			std::stringstream ss;

			if (IsJustPressed())
				ss << "KeyPressedEvent(" << m_Keycode << ", IsJustPressed)";
			else
				ss << "KeyPressedEvent(" << m_Keycode << ", Repeats=" << m_RepeatCount << ")";

			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};


	/** SkeletonEngine KeyPressedEvent class. */
	class SE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		/** @return string  string representation of KeyReleasedEvent */
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent(" << m_Keycode << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
	
}
