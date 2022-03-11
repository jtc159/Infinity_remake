#include "Infinity.h"
#include "Core/EntryPoint.h"


class Sandbox : public Infinity::Application
{
public:
	Sandbox()
	{
		PushOverlay(new Infinity::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Infinity::Application* Infinity::CreateApplication()
{
	return new Sandbox();
}