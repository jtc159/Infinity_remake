#pragma once

#include <glm/glm.hpp>


namespace Infinity
{
	class Input
	{
	public :
		static bool IsKeyPressed(int keycode);
		static bool IsMousePressed(int mousecode);

		static glm::vec2 GetMousePos();
		static float GetMouseX();
		static float GetMouseY();

	};
}