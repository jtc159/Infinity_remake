#pragma once

#include "Core/Layer.h"
#include "Event/EventTemplate.h"
#include "Event/WindowEventMarc.h"


namespace Infinity
{
	class IF_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();

		WINDOW_CLOSE_DELEGATE OnWindowClose;
		WINDOW_RESIZE_DELEGATE OnWindowResize;

		KEY_PRESS_DELEGATE OnKeyPress;
		KEY_TYPE_DELEGATE OnKeyType;
		KEY_REPEAT_DELEGATE OnKeyRepeat;
		KEY_RELEASE_DELEGATE OnKeyRelease;

		MOUSE_PRESS_DELEGATE OnMousePress;
		MOUSE_REPEAT_DELEGATE OnMouseRepeat;
		MOUSE_RELEASE_DELEGATE OnMouseRelease;

		MOUSE_MOVE_DELEGATE OnMouseMove;
		MOUSE_SCROLL_DELEGATE OnMouseScroll;

		void WindowCloseEvent();
		void WindowResizeEvent(int width, int height) ;

		void KeyPressEvent(int keycode);
		void KeyTypeEvent(int keycode);
		void KeyReleaseEvent(int keycode);

		void MousePressEvent(int mousecode);
		void MouseReleaseEvent(int mousecode);
		void MouseMoveEvent(float xOffset, float yOffset);
		void MouseScrollEvent(float xPos, float yPos);
		//void OnEvent(Event& e);
	private:
		float m_Time = 0;
	};

}