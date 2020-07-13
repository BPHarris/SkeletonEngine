/**
 * @file    Application.h
 * @brief   Basic SkeletonEngine Application interface.
 * 
 * @author  Brandon Harris
 * @date    July 2020
 */

#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"




namespace SkeletonEngine {

	/** SkeletonEngine Application class. */
	class SE_API Application
	{
	private:
		bool m_Running = true;
	public:
		LayerStack m_LayerStack;
		std::unique_ptr<Window> m_Window;

	public:
		Application();
		virtual ~Application();

		/** Begin Application mainloop. */
		void Run();

		/**
		 * Dispatch the given Event e.
		 * 
		 * @param   e   The event to dispatch.
		 */
		void OnEvent(Event& e);

		/** Push the given layer to the layer stack. */
		void PushLayer(Layer* layer);

		/** Push the given overlay layer to the layer stack. */
		void PushOverlay(Layer* overlay);
	
	private:
		/**
		 * Handle a WindowClosedEvent.
		 * 
		 * @param   e   The WindowClosedEvent
		 * @return      true if the event has been handled
		 * @return      false otherwise
		 */
		bool OnWindowClose(WindowClosedEvent& e);
	};


	/**
	 * To be defined in client application.
	 * 
	 * @return  Application*    A pointer to a Application instance.
	 */
	Application* CreateApplication();

}
