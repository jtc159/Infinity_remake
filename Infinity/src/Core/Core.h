#pragma once

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