#include "HumiditySensor.hpp"
#include <random>

namespace os
{
    bool HumiditySensor::read() {
                ///simulation of humidity readings
                static std::random_device rd;
                static std::mt19937 gen(rd());
                std::uniform_int_distribution<int> dist(0, 100);
                int humidity = dist(gen);
                return updateValue(humidity);
                
            }
} // namespace os

