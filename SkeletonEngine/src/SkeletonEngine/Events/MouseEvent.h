/**
 * @file    MouseEvent.h
 * @brief   SkeletonEngine mouse events.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#pragma once

#include "Event.h"

namespace SkeletonEngine
{

    /** SkeletonEngine MouseButtonEvent base class. */
    class SE_API MouseButtonEvent
    {
    public:
        int button;
    protected:
        MouseButtonEvent(int button) : button(button) {}
    };

    
    /** SkeletonEngine MouseButtonPressedEvent class. */
    class SE_API MouseButtonPressedEvent : public Event, public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button) :
            EVENT(MouseButtonPressed, EventCategoryMouse | EventCategoryInput),
            MouseButtonEvent(button)
        {}
        EVENT_STATIC_TYPE(MouseButtonPressed)

        /** @return string representation of MouseButtonPressedEvent */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent(" << button << ")";
            return ss.str();
        }
    };

    
    /** SkeletonEngine MouseButtonReleasedEvent class. */
    class SE_API MouseButtonReleasedEvent : public Event, public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button) :
            EVENT(MouseButtonReleased, EventCategoryMouse | EventCategoryInput),
            MouseButtonEvent(button)
        {}
        EVENT_STATIC_TYPE(MouseButtonReleased)

        /** @return string representation of MouseButtonReleasedEvent */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent(" << button << ")";
            return ss.str();
        }
    };

    
    /** SkeletonEngine MouseMovedEvent class. */
    class SE_API MouseMovedEvent : public Event
    {
    public:
        float x, y;
        
        MouseMovedEvent(float x, float y) :
            EVENT(MouseMoved, EventCategoryMouse | EventCategoryInput),
            x(x),
            y(y)
        {}
        EVENT_STATIC_TYPE(MouseMoved)

        /** @return string representation of MouseMovedEvent */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent(" << x << ", " << y << ")";
            return ss.str();
        }
    };

    
    /** SkeletonEngine MouseScrolledEvent class. */
    class SE_API MouseScrolledEvent : public Event
    {
    public:
        float x_offset, y_offset;

        MouseScrolledEvent(float x_offset, float y_offset) :
            EVENT(MouseScrolled, EventCategoryMouse | EventCategoryInput),
            x_offset(x_offset),
            y_offset(y_offset)
        {}
        EVENT_STATIC_TYPE(MouseScrolled)

        /** @return string representation of MouseScrolledEvent */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent(" << x_offset << ", " << y_offset << ")";
            return ss.str();
        }
    };

}
