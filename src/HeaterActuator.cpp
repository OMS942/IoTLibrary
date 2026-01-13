#include "HeaterActuator.hpp"
#include "Environment.hpp"

namespace os
{
    HeaterActuator::HeaterActuator() : Actuator() {}

    HeaterActuator::HeaterActuator(int id, const std::string& name) : Actuator(id, name) {}

    void HeaterActuator::turnOn(int powerLevel, float durationSeconds) {
        Actuator::turnOn(powerLevel, durationSeconds);
        //safety mechanism
        if (powerLevel > 80) {
            m_power = 80;
        }
    }

    void HeaterActuator::turnOff() { 
        Actuator::turnOff(); 
    }

    void HeaterActuator::toggle() { 
        Actuator::toggle(); 
    }

    void HeaterActuator::update(Environment& env, float dt) {
        Actuator::update(dt);
        if (getStatus()) {
            env.applyHeating(m_power, dt);
        }
    }
} // namespace os
