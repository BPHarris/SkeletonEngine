/**
 * @file    LayerStack.h
 * @brief   SkeletonEngine layer stack interface.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#pragma once

#include "Core.h"
#include "Layer.h"

namespace SkeletonEngine
{

    /** SkeletonEngine LayerStack class. */
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
