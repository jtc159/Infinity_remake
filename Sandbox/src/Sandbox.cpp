#include "Infinity.h"


class Sandbox : public Infinity::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Infinity::Application* Infinity::CreateApplication()
{
	return new Sandbox();
}