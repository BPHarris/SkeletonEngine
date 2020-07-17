/**
 * @file    ApplicationEvent.h
 * @brief   SkeletonEngine Application and Window events.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#pragma once

#include "Event.h"


namespace SkeletonEngine
{

    /** SkeletonEngine WindowClosedEvent class. */
    class SE_API WindowClosedEvent : public Event
    {
    public:
        WindowClosedEvent()
            : EVENT(WindowClosed, EventCategoryApplication) {}
        EVENT_STATIC_TYPE(WindowClosed)
    };


    /** SkeletonEngine WindowResizedEvent class. */
    class SE_API WindowResizedEvent : public Event
    {
    public:
        unsigned int width, height;

        WindowResizedEvent(unsigned int width, unsigned int height)
            : EVENT(WindowResized, EventCategoryApplication), width(width), height(height) {}
        EVENT_STATIC_TYPE(WindowResized)

        /** @return string representation of WindowResizedEvent. */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizedEvent(" << width << ", " << height << ")";
            return ss.str();
        }
    };


    /** SkeletonEngine WindowFocusedEvent class. */
    class SE_API WindowFocusedEvent : public Event
    {
    public:
        WindowFocusedEvent()
            : EVENT(WindowFocused, EventCategoryApplication) {}
        EVENT_STATIC_TYPE(WindowFocused)
    };


    /** SkeletonEngine WindowLostFocusEvent class. */
    class SE_API WindowLostFocusEvent : public Event
    {
    public:
        WindowLostFocusEvent()
            : EVENT(WindowLostFocus, EventCategoryApplication) {}
        EVENT_STATIC_TYPE(WindowLostFocus)
    };


    /** SkeletonEngine WindowLostFocusEvent class. */
    class SE_API WindowMovedEvent : public Event
    {
    public:
        unsigned int x, y;

        WindowMovedEvent(unsigned int x, unsigned int y)
            : EVENT(WindowMoved, EventCategoryApplication), x(x), y(y) {}
        EVENT_STATIC_TYPE(WindowMoved)

        /** @return string  string representation of WindowMovedEvent */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowMovedEvent(" << x << ", " << y << ")";
            return ss.str();
        }
    };


    /** SkeletonEngine AppTickEvent class. */
    class SE_API AppTickEvent : public Event
    {
    public:
        AppTickEvent()
            : EVENT(AppTick, EventCategoryApplication) {}
        EVENT_STATIC_TYPE(AppTick)
    };


    /** SkeletonEngine AppUpdateEvent class. */
    class SE_API AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent()
            : EVENT(AppUpdate, EventCategoryApplication) {}
        EVENT_STATIC_TYPE(AppUpdate)
    };


    /** SkeletonEngine AppRenderEvent class. */
    class SE_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent()
            : EVENT(AppRender, EventCategoryApplication) {}
        EVENT_STATIC_TYPE(AppRender)
    };

}
