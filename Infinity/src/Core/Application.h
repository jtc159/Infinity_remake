#pragma once

#include "Core.h"
#include "Window.h"
#include "GLFW/glfw3.h"
#include "LayerStack.h"
#include <memory>

namespace Infinity
{
	class IF_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		//void OnWindowClose(GLFWwindow*);
		void OnWindowClose();

		static Application& Get() { return *s_Instance; }
		Window& GetWindow() { return *m_Window; }

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		static Application* s_Instance;

		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		bool m_Running = true;
	};

	//To be define in CLIENT
	Application* CreateApplication();
}