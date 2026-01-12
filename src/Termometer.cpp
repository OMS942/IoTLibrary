#include "Termometer.hpp"
#include "Environment.hpp"

namespace os
{
    bool Termometer::read(const Environment& env) {
        return updateValue(env.getTemperature());
    }
} // namespace os

