#include "ifpch.h"

#include "Core/Input.h"
#include "Core/Application.h"
#include "Core/Window.h"

#include "GLFW/glfw3.h"

namespace Infinity
{
	bool Input::IsKeyPressed(int keycode) {
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool Input::IsMousePressed(int mousecode){
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, mousecode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	glm::vec2 Input::GetMousePos() {
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		return { x, y };
	}


	float Input::GetMouseX(){
		return GetMousePos().x;
	}

	float Input::GetMouseY(){
		return GetMousePos().x;
	}
}