/** sepch.h -- SkeletonEngine precompiled header file */

#pragma once


#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>


// Data Structures
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>


// Engine (should only be log)
#include "SkeletonEngine/Log.h"


// Platform specific
#ifdef SE_PLATFORM_WINDOWS
	#include <Windows.h>
#endif // SE_PLATFORM_WINDOWS
