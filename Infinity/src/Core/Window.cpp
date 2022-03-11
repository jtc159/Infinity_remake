#include "ifpch.h"
#include "Window.h"


namespace Infinity
{
	WINDOW_CLOSE_EVENT Window::OnWindowClose = WINDOW_CLOSE_EVENT();
	WINDOW_RESIZE_EVENT Window::OnWindowResize = WINDOW_RESIZE_EVENT();

	KEY_PRESS_EVENT Window::OnKeyPress = KEY_PRESS_EVENT();
	KEY_TYPE_EVENT Window::OnKeyType = KEY_TYPE_EVENT();
	KEY_REPEAT_EVENT Window::OnKeyRepeat = KEY_REPEAT_EVENT();
	KEY_RELEASE_EVENT Window::OnKeyRelease = KEY_RELEASE_EVENT();

	MOUSE_PRESS_EVENT Window::OnMousePress = MOUSE_PRESS_EVENT();
	MOUSE_REPEAT_EVENT Window::OnMouseRepeat = MOUSE_REPEAT_EVENT();
	MOUSE_RELEASE_EVENT Window::OnMouseRelease = MOUSE_RELEASE_EVENT();

	MOUSE_MOVE_EVENT Window::OnMouseScroll = MOUSE_MOVE_EVENT();
	MOUSE_SCROLL_EVENT Window::OnMouseMove = MOUSE_SCROLL_EVENT();
}