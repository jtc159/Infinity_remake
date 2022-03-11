#include "ifpch.h"
#include "ImGuiLayer.h"
#include "imgui.h"
#include "Core/Application.h"
#include "imgui_impl_opengl3.h"

#include "Core/Log.h"
#include "glad/glad.h"


namespace Infinity
{
	ImGuiLayer::ImGuiLayer()
	{
	}
	ImGuiLayer::~ImGuiLayer()
	{
	}
	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();

		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 130");

		Window& window = Application::Get().GetWindow();

		window.OnWindowClose += WINDOW_CLOSE_DELEGATE::CreateFromMethod<ImGuiLayer, &ImGuiLayer::WindowCloseEvent>(this);
		window.OnWindowResize += WINDOW_RESIZE_DELEGATE::CreateFromMethod<ImGuiLayer, &ImGuiLayer::WindowResizeEvent>(this);

		window.OnKeyPress += KEY_PRESS_DELEGATE::CreateFromMethod<ImGuiLayer, &ImGuiLayer::KeyPressEvent>(this);
		window.OnKeyType += KEY_TYPE_DELEGATE::CreateFromMethod<ImGuiLayer, &ImGuiLayer::KeyTypeEvent>(this);
		window.OnKeyRelease += KEY_RELEASE_DELEGATE::CreateFromMethod<ImGuiLayer, &ImGuiLayer::KeyReleaseEvent>(this);

		window.OnMousePress += MOUSE_PRESS_DELEGATE::CreateFromMethod<ImGuiLayer, &ImGuiLayer::MousePressEvent>(this);
		window.OnMouseRelease += MOUSE_RELEASE_DELEGATE::CreateFromMethod<ImGuiLayer, &ImGuiLayer::MouseReleaseEvent>(this);

		window.OnMouseMove += MOUSE_MOVE_DELEGATE::CreateFromMethod<ImGuiLayer, &ImGuiLayer::MouseMoveEvent>(this);
		window.OnMouseScroll += MOUSE_SCROLL_DELEGATE::CreateFromMethod<ImGuiLayer, &ImGuiLayer::MouseScrollEvent>(this);
	}
	void ImGuiLayer::OnDetach()
	{

	}
	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());



		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time = m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show_demo_window = true;
		static bool show_another_window = false;
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
		if (show_demo_window){
			ImGui::ShowDemoWindow(&show_demo_window);
		}

		{
			static float f = 0.0f;
			static int counter = 0;

			ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

			ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
			ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
			ImGui::Checkbox("Another Window", &show_another_window);

			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

			if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();
		}
		if (show_another_window)
		{
			ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
			ImGui::Text("Hello from another window!");
			if (ImGui::Button("Close Me"))
				show_another_window = false;
			ImGui::End();
		}

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
	void ImGuiLayer::WindowCloseEvent()
	{
		IF_ERROR("ImGuiLayer::WindowCloseEvent");
	}
	void ImGuiLayer::WindowResizeEvent(int width, int height)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(width, height);
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, width, height);
	}
	void ImGuiLayer::KeyPressEvent(int keycode)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[keycode] = true;

		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
	}
	void ImGuiLayer::KeyTypeEvent(int keycode)
	{
		ImGuiIO& io = ImGui::GetIO();
		if (keycode > 0 && keycode < 0X10000)
			io.AddInputCharacter((unsigned short)keycode);
	}

	void ImGuiLayer::KeyReleaseEvent(int keycode)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[keycode] = false;
	}
	void ImGuiLayer::MousePressEvent(int mousecode)
	{
		IF_CORE_WARN("MousePressEvent");
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[mousecode] = true;
	}
	void ImGuiLayer::MouseReleaseEvent(int mousecode)
	{
		IF_CORE_WARN("MouseReleaseEvent");

		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[mousecode] = false;
	}
	void ImGuiLayer::MouseMoveEvent(float xPos, float yPos)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(xPos, yPos);
	}
	void ImGuiLayer::MouseScrollEvent(float xOffset, float yOffset)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += xOffset;
		io.MouseWheel += yOffset;
	}
}