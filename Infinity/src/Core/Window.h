#pragma once

#include <string>
#include "Event/EventTemplate.h"
#include "Event/WindowEventMarc.h"
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

		static WINDOW_CLOSE_EVENT OnWindowClose;
		static WINDOW_RESIZE_EVENT OnWindowResize;

		static KEY_PRESS_EVENT OnKeyPress;
		static KEY_TYPE_EVENT OnKeyType;
		static KEY_REPEAT_EVENT OnKeyRepeat;
		static KEY_RELEASE_EVENT OnKeyRelease;

		static MOUSE_PRESS_EVENT OnMousePress;
		static MOUSE_REPEAT_EVENT OnMouseRepeat;
		static MOUSE_RELEASE_EVENT OnMouseRelease;
		static MOUSE_MOVE_EVENT OnMouseMove;
		static MOUSE_SCROLL_EVENT OnMouseScroll;
	};
}