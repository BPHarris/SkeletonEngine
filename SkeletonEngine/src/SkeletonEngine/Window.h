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
    using EventCallbackType = std::function<void(Event&)>;

    
    /** SkeletonEngine window properties, passed to Window::Create to create a window. */
    struct WindowProperties
    {
        std::string title;
        unsigned int width;
        unsigned int height;
        bool vsync;

        // Set in Window::Init
        EventCallbackType EventCallback = nullptr;

        WindowProperties(
            const std::string& title = "SkeletonEngine Application",
            unsigned int width = 1280,
            unsigned int height = 720,
            bool vsync = true
        ) : title(title), width(width), height(height), vsync(vsync) {}

        std::string ToString()
        {
            return "\"" + title + "\", " \
                + std::to_string(width) + ", " \
                + std::to_string(height) + ", " \
                + std::to_string(vsync);
        }
    };


    /** SkeletonEngine window abstract base class. */
    class SE_API Window
    {
    public:
        static Window* Create(const WindowProperties& p = WindowProperties());

        virtual ~Window() {}

        virtual void OnUpdate() = 0;
        virtual void Close() = 0;

        std::string  GetTitle()  const { return properties.title;  }
        unsigned int GetWidth()  const { return properties.width;  }
        unsigned int GetHeight() const { return properties.height; }

        void SetEventCallback(const EventCallbackType& callback) { properties.EventCallback = callback; }
        virtual void SetVSync(bool enabled) = 0;
        bool IsVSync() const { return properties.vsync; };

        // HACK: Only works when ((WindowProperties)properties)...
        // Why?! properties is already of type WindowProperties
        virtual std::string ToString() const
        {
            return "Window(" + ((WindowProperties)properties).ToString() + ")";
        }

    protected:
        WindowProperties properties;
        virtual void Init(const WindowProperties& window_properties) = 0;
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
