/**
 * @file    KeyEvent.h
 * @brief   SkeletonEngine keyboard events.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#pragma once

#include "Event.h"

namespace SkeletonEngine
{

    /** SkeletonEngine KeyEvent "interface". */
    class SE_API KeyEvent
    {
    public:
        int keycode;
    protected:
        KeyEvent(int keycode) : keycode(keycode) {}
    };

    
    /** SkeletonEngine KeyPressedEvent class. */
    class SE_API KeyPressedEvent : public Event, public KeyEvent
    {
    public:
        int repeat_count;

        static const int JUST_PRESSED = 0;
        static const int REPEATED = 1;

        KeyPressedEvent(int keycode, int repeat_count) :
            EVENT(KeyPressed, EventCategoryKeyboard | EventCategoryInput),
            KeyEvent(keycode),
            repeat_count(repeat_count)
        {}
        EVENT_STATIC_TYPE(KeyPressed)

        /** @return true if the key was just pressed, false otherwise. */
        inline bool IsJustPressed() const { return !repeat_count; }

        /** @return string representation of KeyPressedEvent */
        std::string ToString() const override
        {
            std::stringstream ss;

            if (IsJustPressed())
                ss << "KeyPressedEvent(" << keycode << ", IsJustPressed)";
            else
                ss << "KeyPressedEvent(" << keycode << ", Repeats=" << repeat_count << ")";

            return ss.str();
        }
    };


    /** SkeletonEngine KeyPressedEvent class. */
    class SE_API KeyReleasedEvent : public Event, public KeyEvent
    {
    public:
        KeyReleasedEvent(int keycode) :
            EVENT(KeyReleased, EventCategoryKeyboard | EventCategoryInput),
            KeyEvent(keycode)
        {}
        EVENT_STATIC_TYPE(KeyReleased)

        /** @return string representation of KeyReleasedEvent */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent(" << keycode << ")";
            return ss.str();
        }
    };

}
