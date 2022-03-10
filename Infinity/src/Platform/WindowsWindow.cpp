#include "ifpch.h"
#include "WindowsWindow.h"

#include <glad/glad.h>

namespace Infinity
{
	static bool s_bGLFWInitialized = false;

	//std::unique_ptr<Window> Window::Create(const WindowProps& props)
	//{
	//	return std::make_unique<Window>(new WindowsWindow(props));
	//}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	//void WindowsWindow::SetEventCallback(const EventCallbackFn& callback)
	//{
	//	m_Data.Eventcallback = callback;
	//}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}


	static void GLFWErrorCallback(int error, const char* description)
	{
		IF_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}


	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		IF_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_bGLFWInitialized)
		{
			int success = glfwInit();
			IF_CORE_ASSERT(success, "Could not initalize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_bGLFWInitialized = true;
		}
		m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		IF_ASSERT(status, "Failed to initialize Glad");

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
				WinData& windata = *(WinData*)glfwGetWindowUserPointer(window);
				OnWindowClose();
				});



		//// Set GLFW Callback
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			WinData& windata = *(WinData*)glfwGetWindowUserPointer(window);
			windata.Width = width;
			windata.Height = height;
			OnWindowResize(width, height);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WinData& windata = *(WinData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
				{
					OnKeyPress(key);
					break;
				}
				case GLFW_REPEAT:
				{
					OnKeyRepeat(key);
					break;
				}
				case GLFW_RELEASE:
				{
					OnKeyRelease(key);
					break;
				}
				default:
					break;
				}
			});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode) {
			WinData& windata = *(WinData*)glfwGetWindowUserPointer(window);
			OnKeyType(keycode);
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WinData& windata = *(WinData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
			case GLFW_PRESS:
			{
				OnMousePress(button);
				break;
			}
			case GLFW_REPEAT:
			{
				OnMouseRepeat(button);
				break;
			}
			case GLFW_RELEASE:
			{
				OnMouseRelease(button);
				break;
			}
			default:
				break;
			}
			});
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WinData& windata = *(WinData*)glfwGetWindowUserPointer(window);
				OnMouseScroll(xOffset, yOffset);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WinData& windata = *(WinData*)glfwGetWindowUserPointer(window);
				OnMouseMove(xPos, yPos);
			});
	}
}