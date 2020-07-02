
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_Core.h:

Program Listing for File Core.h
===============================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_Core.h>` (``SkeletonEngine\src\SkeletonEngine\Core.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
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
   #else
       #error SkeletonEngine only supports windows, thus far.
   #endif // SE_PLATFORM_WINDOWS
