/**
 * @file    Layer.cpp
 * @brief   SkeletonEngine Layer base class.
 * 
 * @author  Brandon Harris (bpharris@pm.me)
 * @date    July 2020
 */

#include "sepch.h"
#include "Layer.h"

namespace SkeletonEngine
{

    Layer::Layer(const std::string &name)
        : m_Name(name) {}

    Layer::~Layer() {}

}
