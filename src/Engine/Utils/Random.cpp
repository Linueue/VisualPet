#include "Random.h"

namespace Engine
{
    std::random_device Random::s_Device;
    std::mt19937 Random::s_Engine(Random::s_Device());

    const float Random::Value()
    {
        static std::uniform_real_distribution<float> distribution(0.0f, 1.0f);

        return distribution(s_Engine);
    }

    const int32_t Random::RandRange(const int32_t min, const int32_t max)
    {
        std::uniform_int_distribution<int32_t> distribution(min, max);

        return distribution(s_Engine);
    }
}
