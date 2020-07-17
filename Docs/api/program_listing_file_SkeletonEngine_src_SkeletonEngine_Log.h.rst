
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
   
   namespace SkeletonEngine
   {
   
       class SE_API Log
       {
       public:
           static void Init();
   
           static std::shared_ptr<spdlog::logger> s_CoreLogger;
   
           static std::shared_ptr<spdlog::logger> s_ClientLogger;
       };
   
   }
   
   // Engine core loging macros
   #define SE_CORE_FATAL(...) ::SkeletonEngine::Log::s_CoreLogger->fatal(__VA_ARGS__)  
   #define SE_CORE_ERROR(...) ::SkeletonEngine::Log::s_CoreLogger->error(__VA_ARGS__)  
   #define SE_CORE_WARN(...) ::SkeletonEngine::Log::s_CoreLogger->warn(__VA_ARGS__)    
   #define SE_CORE_INFO(...) ::SkeletonEngine::Log::s_CoreLogger->info(__VA_ARGS__)    
   #define SE_CORE_TRACE(...) ::SkeletonEngine::Log::s_CoreLogger->trace(__VA_ARGS__)  
   // Client application logging macros
   #define SE_FATAL(...) ::SkeletonEngine::Log::s_ClientLogger->fatal(__VA_ARGS__)     
   #define SE_ERROR(...) ::SkeletonEngine::Log::s_ClientLogger->error(__VA_ARGS__)     
   #define SE_WARN(...) ::SkeletonEngine::Log::s_ClientLogger->warn(__VA_ARGS__)       
   #define SE_INFO(...) ::SkeletonEngine::Log::s_ClientLogger->info(__VA_ARGS__)       
   #define SE_TRACE(...) ::SkeletonEngine::Log::s_ClientLogger->trace(__VA_ARGS__)     
