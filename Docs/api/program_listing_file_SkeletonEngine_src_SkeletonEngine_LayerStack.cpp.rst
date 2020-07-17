
.. _program_listing_file_SkeletonEngine_src_SkeletonEngine_LayerStack.cpp:

Program Listing for File LayerStack.cpp
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_SkeletonEngine_src_SkeletonEngine_LayerStack.cpp>` (``SkeletonEngine\src\SkeletonEngine\LayerStack.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "sepch.h"
   #include "LayerStack.h"
   
   namespace SkeletonEngine
   {
   
       LayerStack::LayerStack()
       {
           m_LayerInsert = m_Layers.begin();
       }
   
       LayerStack::~LayerStack()
       {
           for (auto layer : m_Layers)
               delete layer;
       }
   
       void LayerStack::PushLayer(Layer *layer)
       {
           m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
       }
   
       void LayerStack::PushOverlay(Layer *overlay)
       {
           m_Layers.emplace_back(overlay);
       }
   
       void LayerStack::PopLayer(Layer *layer)
       {
           auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
   
           if (it != m_Layers.end())
           {
               m_Layers.erase(it);
               m_LayerInsert--;
           }
       }
   
       void LayerStack::PopOverlay(Layer *overlay)
       {
           auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
   
           if (it != m_Layers.end())
               m_Layers.erase(it);
       }
   
   }
