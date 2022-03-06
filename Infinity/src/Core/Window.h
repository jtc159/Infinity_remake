#pragma once

#include <string>

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
	};
}