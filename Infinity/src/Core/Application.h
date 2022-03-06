#include "Core.h"
#include "Window.h"
#include <memory>

namespace Infinity
{
	class IF_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		static Application& Get() { return *s_Instance; }
		Window& GetWindow() { return *m_Window; }
	private:
		static Application* s_Instance;

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be define in CLIENT
	Application* CreateApplication();
}