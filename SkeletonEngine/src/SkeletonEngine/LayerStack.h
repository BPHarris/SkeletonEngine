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

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return layers.begin(); }
        std::vector<Layer*>::iterator end()   { return layers.end();   }

    private:
        std::vector<Layer*> layers;
        std::vector<Layer*>::iterator layer_insert;
    };

}
