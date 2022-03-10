#include "ifpch.h"
#include "Application.h"

#include <glad/glad.h>


namespace Infinity
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		IF_ASSERT(!s_Instance, "Already had an application!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->OnWindowClose = IFDelegate<void()>::CreateFromMethod<Application, &Application::OnWindowClose>(this);
		//m_Window->windowClose = IFDelegate<void(GLFWwindow*)>::CreateFromMethod<Application, &Application::OnWindowClose>(this);
		//m_Window->SetEventCallback(BIND_STD_EVENT(&Application::OnEvent));
		//m_Window->SetEventCallback(IFDelegate<void(Event&)>::CreateFromMethod<Application, &Application::OnEvent>(this));
	}
	Application::~Application()
	{

	}

	//void Application::OnWindowClose(GLFWwindow* w)
	//{
	//	m_Running = false;
	//}

	void Application::OnWindowClose()
	{
		m_Running = false;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 1, 0, 0.5);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->OnUpdate();
		}
	}
}