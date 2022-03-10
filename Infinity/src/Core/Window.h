#pragma once

#include <string>
#include "Event/EventTemplate.h"
#include "Core/Log.h"
#include "GLFW//glfw3.h"

namespace Infinity
{
	struct WindowProps
	{
		std::string Title;
		int Width;
		int Height;
		WindowProps(const std::string& t = "Infinity Engine", int w = 1280, int h = 720)
			: Title(t), Width(w), Height(h) {}

	};


	class Window
	{
	public:
		//using EventCallbackFn = std::function<void(Event&)>;

		//using EventCallbackFn = IFDelegate<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;


		//virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		//static std::unique_ptr<Window> Create(const WindowProps& props = WindowProps());
		static Window* Create(const WindowProps& props = WindowProps());

		static IFDelegate<void()> OnWindowClose;
		static IFDelegate<void(int, int)> OnWindowResize;
		
		static IFDelegate<void(int)> OnKeyPress;
		static IFDelegate<void(int)> OnKeyType;
		static IFDelegate<void(int)> OnKeyRepeat;
		static IFDelegate<void(int)> OnKeyRelease;

		static IFDelegate<void(int)> OnMousePress;
		static IFDelegate<void(int)> OnMouseRepeat;
		static IFDelegate<void(int)> OnMouseRelease;
		static IFDelegate<void(float, float)> OnMouseMove;
		static IFDelegate<void(float, float)> OnMouseScroll;
	};

	class WindowResizeEvent {
	public:
		static void OnEvent(int width, int height) {
			IF_CORE_INFO("WindowResizeEvent : width({0}), height({1})", width, height);
		}
	};

	class KeyPressEvent {
	public:
		static void OnEvent(int keycode) {
			IF_CORE_INFO("KeyPressEvent : keycode({0})", keycode);
		}
	};

	class KeyTypeEvent {
	public:
		static void OnEvent(int keycode) {
			IF_CORE_ERROR("KeyTypeEvent : keycode({0})", keycode);
		}
	};

	class KeyRepeatEvent {
	public:
		static void OnEvent(int keycode) {
			IF_CORE_INFO("KeyRepeatEvent : keycode({0})", keycode);
		}
	};
	class KeyReleaseEvent {
	public:
		static void OnEvent(int keycode) {
			IF_CORE_INFO("KeyReleaseEvent : keycode({0})", keycode);
		}
	};
	class MousePressEvent {
	public:
		static void OnEvent(int mousecode) {
			IF_CORE_INFO("MousePressEvent : mousecode({0})", mousecode);
		}
	};
	class MouseRepeatEvent {
	public:
		static void OnEvent(int mousecode) {
			IF_CORE_INFO("MouseRepeatEvent : mousecode({0})", mousecode);
		}
	};
	class MouseReleaseEvent {
	public:
		static void OnEvent(int mousecode) {
			IF_CORE_INFO("MouseReleaseEvent : mousecode({0})", mousecode);
		}
	};

	class MouseScrollEvent {
	public:
		static void OnEvent(float xOffset, float yOffset) {
			IF_CORE_INFO("MouseScrollEvent : xOffset({0}), yOffset({1})", xOffset, yOffset);
		}
	};

	class MouseMoveEvent {
	public:
		static void OnEvent(float xPos, float yPos) {
			IF_CORE_INFO("MouseReleaseEvent : xPos({0}), yPos({1})", xPos, yPos);
		}
	};
}