#pragma once

#include <random>

namespace Engine
{
    class Random
    {
    public:
        static const float Value();

    private:
        static std::random_device s_Device;
        static std::mt19937 s_Engine;
    };
}
