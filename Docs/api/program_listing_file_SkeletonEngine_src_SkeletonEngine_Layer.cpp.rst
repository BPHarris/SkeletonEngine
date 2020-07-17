
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_Layer.cpp:

Program Listing for File Layer.cpp
==================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_Layer.cpp>` (``SkeletonEngine\src\SkeletonEngine\Layer.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "sepch.h"
   #include "Layer.h"
   
   namespace SkeletonEngine
   {
   
       Layer::Layer(const std::string &name)
           : m_Name(name) {}
   
       Layer::~Layer() {}
   
   }
