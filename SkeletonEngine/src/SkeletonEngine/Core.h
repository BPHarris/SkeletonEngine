#pragma once

#ifdef SE_PLATFORM_WINDOWS
	#ifdef SE_BUILD_DLL
		#define SE_API __declspec(dllexport)
	#else
		#define SE_API __declspec(dllimport)
	#endif // SE_BUILD_DLL
#else
	#error SkeletonEngine only supports windows, thus far.
#endif // SE_PLATFORM_WINDOWS


#define BIT(x) (1 << x)
