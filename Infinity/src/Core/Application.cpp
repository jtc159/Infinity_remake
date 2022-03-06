#include "ifpch.h"
#include "Core.h"
#include "Application.h"
#include "Window.h"



namespace Infinity
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		IF_ASSERT(!s_Instance, "Already had an application!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		//m_Window->SetEventCallback(BIND_STD_EVENT(&Application::OnEvent));
		//m_Window->SetEventCallback(IFDelegate<void(Event&)>::CreateFromMethod<Application, &Application::OnEvent>(this));
	}
	Application::~Application()
	{

	}
	void Application::Run()
	{
		while (m_Running)
		{

		}
	}
}