
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_Log.h:

Program Listing for File Log.h
==============================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_Log.h>` (``SkeletonEngine\src\SkeletonEngine\Log.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #pragma once
   
   #include "Core.h"
   #include "spdlog/spdlog.h"
   #include "spdlog/fmt/ostr.h"
   
   
   namespace SkeletonEngine {
   
       class SE_API Log
       {
       public:
           static void Init();
   
           inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
           inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
       private:
           static std::shared_ptr<spdlog::logger> s_CoreLogger;
           static std::shared_ptr<spdlog::logger> s_ClientLogger;
       };
   
   }
   
   
   // Engine core loging macros
   #define SE_CORE_FATAL(...)  ::SkeletonEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)
   #define SE_CORE_ERROR(...)  ::SkeletonEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
   #define SE_CORE_WARN(...)   ::SkeletonEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
   #define SE_CORE_INFO(...)   ::SkeletonEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
   #define SE_CORE_TRACE(...)  ::SkeletonEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
   
   // Client application logging macros
   #define SE_FATAL(...)       ::SkeletonEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
   #define SE_ERROR(...)       ::SkeletonEngine::Log::GetClientLogger()->error(__VA_ARGS__)
   #define SE_WARN(...)        ::SkeletonEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
   #define SE_INFO(...)        ::SkeletonEngine::Log::GetClientLogger()->info(__VA_ARGS__)
   #define SE_TRACE(...)       ::SkeletonEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
   
