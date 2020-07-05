/**
 * @file    Core.h
 * @brief   Core defines for SkeletonEngine.
 * 
 * @author  BP Harris
 * @date    July 2020
 */

#pragma once


#define BIT(x) (1 << x)


#ifdef SE_ENABLE_ASSERTS
	#define SE_ASSERT(x, ...) { if(!(x)) { SE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SE_CORE_ASSERT(x, ...) { if(!(x)) { SE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SE_ASSERT(x, ...)
	#define SE_CORE_ASSERT(x, ...)
#endif // SE_ENABLE_ASSERTS



/* SharedLib/DLL declspecs */
#ifdef SE_PLATFORM_WINDOWS
	#ifdef SE_BUILD_DLL
		#define SE_API __declspec(dllexport)
	#else
		#define SE_API __declspec(dllimport)
	#endif // SE_BUILD_DLL
#endif

#ifdef SE_PLATFORM_LINUX
	#define SE_API __attribute__ ((visibility ("default")))
#endif

#ifndef SE_API
	#error SkeletonEngine only supports Windows/Linux thus far.
#endif // SE_PLATFORM_WINDOWS
