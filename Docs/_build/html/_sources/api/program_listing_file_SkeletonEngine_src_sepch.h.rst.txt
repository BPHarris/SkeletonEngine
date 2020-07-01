
.. _program_listing_file_SkeletonEngine_src_sepch.h:

Program Listing for File sepch.h
================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_sepch.h>` (``SkeletonEngine\src\sepch.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
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
