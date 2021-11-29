//
// Created by Pablo Deputter on 11/11/2021.
//

#include "util/Random.h"

using namespace Utils;

float Random::IRandom(float a, float b) const
{
        std::random_device random_device;
        std::mt19937 random_engine(random_device());
        std::binomial_distribution();
        std::uniform_real_distribution<float> uniformRealDistribution(a, b);

        return uniformRealDistribution(random_engine);
}

Random& Random::Get()
{
        static Random instance;
        return instance;
}

Random& Random::GetInstance() { return Get(); }

float Random::GetRandom(float a, float b) { return Get().IRandom(a, b); }
