
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_Layer.h:

Program Listing for File Layer.h
================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_Layer.h>` (``SkeletonEngine\src\SkeletonEngine\Layer.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #pragma once
   
   #include "Core.h"
   #include "Events/Event.h"
   
   namespace SkeletonEngine
   {
   
       class SE_API Layer
       {
       public:
           std::string m_Name;
   
           Layer(const std::string &name = "Layer");
           virtual ~Layer();
   
           virtual void OnAttach() {}
           virtual void OnDetach() {}
           virtual void OnUpdate() {}
           virtual void OnEvent(Event &event) {}
       };
   
   }
