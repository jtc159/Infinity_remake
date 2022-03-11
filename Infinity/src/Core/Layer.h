#pragma once

#include <string>
#include "Core.h"

namespace Infinity
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer")
			: m_name(name) {}

		const std::string& GetName() { return m_name; }

		virtual ~Layer() {}
		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		//virtual void OnEvent(Event& e) {};

	private:
		std::string m_name;
	};

}