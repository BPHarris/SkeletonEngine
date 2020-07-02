/**
 * @file    sepch.h
 * @brief   SkeletonEngine precompiled header file.
 * 
 * @author  BP Harris
 * @date    July 2020
 */

#pragma once


/* -------------------------------- General -------------------------------- */
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>


/* ---------------------------- Data Structures ---------------------------- */
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>


/* -------------------------------- Engine --------------------------------- */
#include "SkeletonEngine/Log.h"


/* ------------------------------- Platform -------------------------------- */
#ifdef SE_PLATFORM_WINDOWS
	#include <Windows.h>
#endif // SE_PLATFORM_WINDOWS
