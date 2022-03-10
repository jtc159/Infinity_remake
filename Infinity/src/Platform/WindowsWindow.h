#pragma once

#include "Core/Window.h"
#include "Core/Log.h"
#include "GLFW/glfw3.h"

namespace Infinity
{

	class WindowsWindow :
		public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;

		virtual int GetWidth() const override { return m_Data.Width; }
		virtual int GetHeight() const override { return m_Data.Height; }


		//virtual void SetEventCallback(const EventCallbackFn& callback) override;
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

		virtual void* GetNativeWindow() const override { return m_Window; }

		

	private:
		GLFWwindow* m_Window;

		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		struct WinData
		{
			std::string Title;
			int Width, Height;
			bool VSync;

			//EventCallbackFn Eventcallback;
		};

		WinData m_Data;
	};

}

