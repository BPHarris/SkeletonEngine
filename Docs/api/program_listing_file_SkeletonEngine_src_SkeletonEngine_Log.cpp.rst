
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_Log.cpp:

Program Listing for File Log.cpp
================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_Log.cpp>` (``SkeletonEngine\src\SkeletonEngine\Log.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "sepch.h"
   #include "Log.h"
   
   #include "spdlog/sinks/stdout_color_sinks.h"
   
   
   namespace SkeletonEngine {
   
       std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
       std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
   
       void Log::Init()
       {
           spdlog::set_pattern("%^[%T] [%n] %v%$");
   
           s_CoreLogger = spdlog::stdout_color_mt("SkeletonEngine");
           s_CoreLogger->set_level(spdlog::level::trace);
   
           s_ClientLogger = spdlog::stdout_color_mt("Application");
           s_ClientLogger->set_level(spdlog::level::trace);
       }
   
   }
