/**
 * @file    EntryPoint.h
 * @brief   Contains SkeletonEngine program entry point.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#pragma once


#ifdef SE_PLATFORM_WINDOWS

extern SkeletonEngine::Application *SkeletonEngine::CreateApplication();

int main(int argc, char **argv)
{
    SkeletonEngine::Log::Init();

    auto app = SkeletonEngine::CreateApplication();
    app->Run();
    delete app;
}

#endif
