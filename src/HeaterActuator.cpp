#include "HeaterActuator.hpp"
#include "Environment.hpp"

namespace os
{
    HeaterActuator::HeaterActuator() : Actuator() {}

    HeaterActuator::HeaterActuator(int id, const std::string& name) : Actuator(id, name) {}

    void HeaterActuator::turnOn(int powerLevel, int durationSeconds) {
        Actuator::turnOn(powerLevel, durationSeconds);
        if (powerLevel > 80) {
            powerLevel = 80;
        }
        Actuator::turnOn(powerLevel, durationSeconds);
    }

    void HeaterActuator::turnOff() { 
        Actuator::turnOff(); 
    }

    void HeaterActuator::toggle() { 
        Actuator::toggle(); 
    }

    void HeaterActuator::update(Environment& env, float dt) {
        Actuator::update();
        if (getStatus()) {
            env.applyHeating(getPower(), dt);
        }
    }
} // namespace os
