/**
 * @file    ImGuiLayer.h
 * @brief   
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#pragma once

#include "SkeletonEngine/Layer.h"


namespace SkeletonEngine
{

    /** SkeletonEngine ImGuiLayer. */
    class SE_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& event);

    private:
        float m_Time = 0.0f;
    };

}
