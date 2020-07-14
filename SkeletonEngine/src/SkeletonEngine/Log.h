/**
 * @file    Log.h
 * @brief   Interface to spdlog wrapper.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace SkeletonEngine
{

    /** SkeletonEngine Log class. */
    class SE_API Log
    {
    public:
        /** Initialise core and client loggers. */
        static void Init();

        /**
		 * Core engine logger.
		 * 
		 * @see SE_CORE_FATAL
		 * @see SE_CORE_ERROR
		 * @see SE_CORE_WARN
		 * @see SE_CORE_INFO
		 * @see SE_CORE_TRACE
		 */
        static std::shared_ptr<spdlog::logger> s_CoreLogger;

        /**
		 * Client application logger.
		 * 
		 * @see SE_FATAL
		 * @see SE_ERROR
		 * @see SE_WARN
		 * @see SE_INFO
		 * @see SE_TRACE
		 */
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}

// Engine core loging macros
#define SE_CORE_FATAL(...) ::SkeletonEngine::Log::s_CoreLogger->fatal(__VA_ARGS__)  /**< Log from engine at level fatal. */
#define SE_CORE_ERROR(...) ::SkeletonEngine::Log::s_CoreLogger->error(__VA_ARGS__)  /**< Log from engine at level error. */
#define SE_CORE_WARN(...) ::SkeletonEngine::Log::s_CoreLogger->warn(__VA_ARGS__)    /**< Log from engine at level warn. */
#define SE_CORE_INFO(...) ::SkeletonEngine::Log::s_CoreLogger->info(__VA_ARGS__)    /**< Log from engine at level info. */
#define SE_CORE_TRACE(...) ::SkeletonEngine::Log::s_CoreLogger->trace(__VA_ARGS__)  /**< Log from engine at level trace. */

// Client application logging macros
#define SE_FATAL(...) ::SkeletonEngine::Log::s_ClientLogger->fatal(__VA_ARGS__)     /**< Log from client at level fatal. */
#define SE_ERROR(...) ::SkeletonEngine::Log::s_ClientLogger->error(__VA_ARGS__)     /**< Log from client at level error. */
#define SE_WARN(...) ::SkeletonEngine::Log::s_ClientLogger->warn(__VA_ARGS__)       /**< Log from client at level warn. */
#define SE_INFO(...) ::SkeletonEngine::Log::s_ClientLogger->info(__VA_ARGS__)       /**< Log from client at level info. */
#define SE_TRACE(...) ::SkeletonEngine::Log::s_ClientLogger->trace(__VA_ARGS__)     /**< Log from client at level trace. */
