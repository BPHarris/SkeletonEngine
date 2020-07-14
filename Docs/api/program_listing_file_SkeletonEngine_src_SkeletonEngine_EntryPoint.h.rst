
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_EntryPoint.h:

Program Listing for File EntryPoint.h
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_EntryPoint.h>` (``SkeletonEngine\src\SkeletonEngine\EntryPoint.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
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
