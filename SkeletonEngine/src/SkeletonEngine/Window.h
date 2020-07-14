/**
 * @file    Window.h
 * @brief   SkeletonEngine generic Window interface.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#pragma once

#include "sepch.h"

#include "SkeletonEngine/Core.h"
#include "SkeletonEngine/Events/Event.h"

namespace SkeletonEngine
{

    /** Stores Window properties. */
    struct WindowProperties
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProperties(
                const std::string &title = "SkeletonEngine",
                unsigned int width = 1280,
                unsigned int height = 720)
            : Title(title), Width(width), Height(height) {}
    };

    /** Interface representing a desktop system based Window. */
    class SE_API Window
    {
    public:
        using EventCallbackFn = std::function<void(Event &)>;

        static Window *Create(const WindowProperties &p = WindowProperties());
        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual std::string GetTitle() const = 0;
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        /** @return string representaiton of the window. */
        virtual std::string ToString() const { return "Window(\"" + GetTitle() + "\")"; }

        virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;
    };

    /**
	 * Operator overload for << and Window.
	 * 
	 * @param	os  Left-hand side.
	 * @param	w   A Window instance
	 * @return      String concatination of os and w.
	 */
    inline std::ostream &operator<<(std::ostream &os, const Window &w)
    {
        return os << w.ToString();
    }
}
