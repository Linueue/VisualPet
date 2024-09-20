#pragma once

#include <random>

namespace Engine
{
    class Random
    {
    public:
        static const float Value();
        static const int32_t RandRange(const int32_t min, const int32_t max);

    private:
        static std::random_device s_Device;
        static std::mt19937 s_Engine;
    };
}
