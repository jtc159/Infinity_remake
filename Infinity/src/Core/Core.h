#pragma once

#include <memory>

#ifdef IF_BUILD_DLL
#define IF_API __declspec(dllexport)
#else
#define IF_API __declspec(dllimport)
#endif

#ifdef IF_ENABLE_ASSERT
#define IF_ASSERT(X, ...) { if(!(X)) { IF_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak; } }
#define IF_CORE_ASSERT(X, ...) { if(!(X)) { IF_CORE_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak; } }
#else
#define IF_ASSERT(X, ...)
#define IF_CORE_ASSERT(X, ...)
#endif

namespace Infinity
{
	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}