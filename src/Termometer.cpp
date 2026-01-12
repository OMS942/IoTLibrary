#include "Termometer.hpp"
#include "Environment.hpp"

namespace os
{
    Termometer::Termometer(): Sensor(0, "Unknown Temperature Sensor", "") {}

    Termometer::Termometer(int id, const std::string& name, const std::string& unit, float minValue, float maxValue)
        : Sensor(id, name, unit, minValue, maxValue) {}
    bool Termometer::read(const Environment& env) {
        return updateValue(env.getTemperature());
    }
} // namespace os

