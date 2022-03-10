#include "ifpch.h"
#include "Window.h"


namespace Infinity
{
	IFDelegate<void()> Window::OnWindowClose = IFDelegate<void()>();
	IFDelegate<void(int, int)> Window::OnWindowResize = IFDelegate<void(int, int)>::CreateFromFunc<&WindowResizeEvent::OnEvent>();
	IFDelegate<void(int)> Window::OnKeyPress = IFDelegate<void(int)>::CreateFromFunc<&KeyPressEvent::OnEvent>();
	IFDelegate<void(int)> Window::OnKeyType = IFDelegate<void(int)>::CreateFromFunc<&KeyTypeEvent::OnEvent>();
	IFDelegate<void(int)> Window::OnKeyRepeat = IFDelegate<void(int)>::CreateFromFunc<&KeyRepeatEvent::OnEvent>();
	IFDelegate<void(int)> Window::OnKeyRelease = IFDelegate<void(int)>::CreateFromFunc<&KeyReleaseEvent::OnEvent>();
						 
	IFDelegate<void(int)> Window::OnMousePress = IFDelegate<void(int)>::CreateFromFunc<&MousePressEvent::OnEvent>();
	IFDelegate<void(int)> Window::OnMouseRepeat = IFDelegate<void(int)>::CreateFromFunc<&MouseRepeatEvent::OnEvent>();
	IFDelegate<void(int)> Window::OnMouseRelease = IFDelegate<void(int)>::CreateFromFunc<&MouseReleaseEvent::OnEvent>();

	IFDelegate<void(float, float)> Window::OnMouseScroll = IFDelegate<void(float, float)>::CreateFromFunc<&MouseScrollEvent::OnEvent>();
	IFDelegate<void(float, float)> Window::OnMouseMove = IFDelegate<void(float, float)>::CreateFromFunc<&MouseMoveEvent::OnEvent>();
}