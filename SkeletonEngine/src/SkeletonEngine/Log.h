#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace SkeletonEngine
{

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

// Client application loging macros
#define SE_FATAL(...)       ::SkeletonEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define SE_ERROR(...)       ::SkeletonEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SE_WARN(...)        ::SkeletonEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SE_INFO(...)        ::SkeletonEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SE_TRACE(...)       ::SkeletonEngine::Log::GetClientLogger()->trace(__VA_ARGS__)

