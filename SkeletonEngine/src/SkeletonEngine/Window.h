/** Window.h
 *
 * SkeletonEngine generic Window interface.
 */

#pragma once

#include "sepch.h"

#include "SkeletonEngine/Core.h"
#include "SkeletonEngine/Events/Event.h"


namespace SkeletonEngine {

	/** WindowProperties -- stores Window properties */
	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		/** Default WindowProperties constructor */
		WindowProperties(
				const std::string& title = "SkeletonEngine",
				unsigned int width = 1280,
				unsigned int height = 720
		) : Title(title), Width(width), Height(height)
		{
		}
	};


	/** Window -- Interface representing a desktop system based Window */
	class SE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProperties& p = WindowProperties());
	};
}
