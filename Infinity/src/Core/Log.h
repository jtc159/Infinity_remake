#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Infinity
{
	class IF_API Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return ms_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return ms_ClientLogger; }

	private:
		static Ref<spdlog::logger> ms_CoreLogger;
		static Ref<spdlog::logger> ms_ClientLogger;

	};
}



#define IF_CORE_ERROR(...)	::Infinity::Log::GetCoreLogger()->error(__VA_ARGS__)
#define IF_CORE_WARN(...)	::Infinity::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define IF_CORE_INFO(...)	::Infinity::Log::GetCoreLogger()->info(__VA_ARGS__)
#define IF_CORE_TRACE(...)	::Infinity::Log::GetCoreLogger()->trace(__VA_ARGS__)


#define IF_ERROR(...)		::Infinity::Log::GetClientLogger()->error(__VA_ARGS__)
#define IF_WARN(...)		::Infinity::Log::GetClientLogger()->warn(__VA_ARGS__)
#define IF_INFO(...)		::Infinity::Log::GetClientLogger()->info(__VA_ARGS__)
#define IF_TRACE(...)		::Infinity::Log::GetClientLogger()->trace(__VA_ARGS__)
