#include "ifpch.h"
#include "Log.h"


namespace Infinity
{
	Ref<spdlog::logger> Log::ms_CoreLogger;
	Ref<spdlog::logger> Log::ms_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^{%T} %n: %v%$");
		ms_CoreLogger = spdlog::stdout_color_mt("INFINITY");
		ms_CoreLogger->set_level(spdlog::level::trace);

		ms_ClientLogger = spdlog::stdout_color_mt("APPLICATION");
		ms_ClientLogger->set_level(spdlog::level::trace);
	}
}