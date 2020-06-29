/** WindowsWindow.h
 *
 * SkeletonEngine Windows Window interface.
 */

#pragma once

#include "SkeletonEngine/Window.h"

#include <GLFW/glfw3.h>


namespace SkeletonEngine {

	/** SkeletonEngine WindowsWindow class. */
	class WindowsWindow : public Window
	{
	public:
		static const int VSYNC_ENABLED = 1;
		static const int VSYNC_DISABLED = 0;


		WindowsWindow(const WindowProperties& properties);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width;  }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProperties& properties);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}
