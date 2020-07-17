/**
 * @file    Log.cpp
 * @brief   Wrapper to spdlog.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#include "sepch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"


namespace SkeletonEngine
{
    std::shared_ptr<spdlog::logger> Log::g_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::g_ClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] [%n] %v%$");

        g_CoreLogger = spdlog::stdout_color_mt("SkeletonEngine");
        g_CoreLogger->set_level(spdlog::level::trace);

        g_ClientLogger = spdlog::stdout_color_mt("Application");
        g_ClientLogger->set_level(spdlog::level::trace);
    }
}
