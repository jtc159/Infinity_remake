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


		static void WindowResizeEvent(int width, int height) {
			IF_CORE_INFO("WindowResizeEvent : width({0}), height({1})", width, height);
		}

		static void KeyPressEvent(int keycode) {
			IF_CORE_INFO("KeyPressEvent : keycode({0})", keycode);
		}

		static void KeyTypeEvent(int keycode) {
			IF_CORE_ERROR("KeyTypeEvent : keycode({0})", keycode);
		}

		static void KeyRepeatEvent(int keycode) {
			IF_CORE_INFO("KeyRepeatEvent : keycode({0})", keycode);
		}
		static void KeyReleaseEvent(int keycode) {
			IF_CORE_INFO("KeyReleaseEvent : keycode({0})", keycode);
		}
		static void MousePressEvent(int mousecode) {
			IF_CORE_INFO("MousePressEvent : mousecode({0})", mousecode);
		}
		static void MouseRepeatEvent(int mousecode) {
			IF_CORE_INFO("MouseRepeatEvent : mousecode({0})", mousecode);
		}
		static void MouseReleaseEvent(int mousecode) {
			IF_CORE_INFO("MouseReleaseEvent : mousecode({0})", mousecode);
		}

		static void MouseScrollEvent(float xOffset, float yOffset) {
			IF_CORE_INFO("MouseScrollEvent : xOffset({0}), yOffset({1})", xOffset, yOffset);
		}

		static void MouseMoveEvent(float xPos, float yPos) {
			IF_CORE_INFO("MouseMoveEvent : xPos({0}), yPos({1})", xPos, yPos);
		}


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

