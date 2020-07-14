/**
 * @file    Layer.h
 * @brief   SkeletonEngine layer interface.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace SkeletonEngine
{

    /** SkeletonEngine Layer class. */
    class SE_API Layer
    {
    public:
        /** Layer name (for debug). */
        std::string m_Name;

        Layer(const std::string &name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event &event) {}
    };

}
