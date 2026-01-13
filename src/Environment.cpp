#include "Environment.hpp"
#include <stdexcept>

namespace os
{
    Environment::Environment() : m_temperature(0) {}

    Environment::Environment(float startTemp) {
        if (startTemp < -273.15f) {
            throw std::invalid_argument("Temperature below absolute zero (C)");
        }
        m_temperature = startTemp;
    }

    void Environment::applyHeating(int power, float dt) {
        m_temperature += 0.01f * power * dt;
    }

    void Environment::applyCooling(float dt) {
        if (m_temperature > -273.15f) {
            m_temperature -= 0.5f * dt;
        }
    }

    float Environment::getTemperature() const { 
        return m_temperature; 
    }

    void Environment::setTemperature(float temp) {
        if (temp < -273.15f) {
            throw std::invalid_argument("Temperature below absolute zero (C)");
        }
        m_temperature = temp;
    }

} // namespace os
