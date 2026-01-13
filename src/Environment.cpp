#include "Environment.hpp"
#include <stdexcept>

namespace os
{
    Environment::Environment() : m_temperature(0), m_ambientTemp(0) {}

    Environment::Environment(float start, float ambient)
        : m_temperature(start), m_ambientTemp(ambient) {}

    void Environment::applyHeating(int power, float dt) {
        m_temperature += 0.01f * power * dt;
    }

    void Environment::applyCooling(float dt) {
        if (m_temperature > m_ambientTemp) {
            m_temperature -= 0.5f * dt;
        }
        if (m_temperature < m_ambientTemp) {
            m_temperature = m_ambientTemp;
        }
    }

    float Environment::getTemperature() const { 
        return m_temperature; 
    }

    void Environment::setTemperature(float temp) {
        if (temp > -273) {
        m_temperature = temp;
        }
    }

} // namespace os
