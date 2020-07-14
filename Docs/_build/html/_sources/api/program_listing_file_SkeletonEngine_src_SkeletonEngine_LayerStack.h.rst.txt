
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_LayerStack.h:

Program Listing for File LayerStack.h
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_LayerStack.h>` (``SkeletonEngine\src\SkeletonEngine\LayerStack.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #pragma once
   
   #include "Core.h"
   #include "Layer.h"
   
   namespace SkeletonEngine
   {
   
       class LayerStack
       {
       public:
           LayerStack();
           ~LayerStack();
   
           void PushLayer(Layer *layer);
           void PushOverlay(Layer *overlay);
   
           void PopLayer(Layer *layer);
           void PopOverlay(Layer *overlay);
   
           std::vector<Layer *>::iterator begin() { return m_Layers.begin(); }
           std::vector<Layer *>::iterator end() { return m_Layers.end(); }
   
       private:
           std::vector<Layer *> m_Layers;
           std::vector<Layer *>::iterator m_LayerInsert;
       };
   
   }
