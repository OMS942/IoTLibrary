#include "HeaterActuator.hpp"
#include "Environment.hpp"

namespace os
{
    void HeaterActuator::turnOn(int powerLevel, int durationSeconds) {
        /// Safty power limiter
        if (powerLevel > 80) powerLevel = 80;
        Actuator::turnOn(powerLevel, durationSeconds);
    }

    void HeaterActuator::turnOff() { 
        Actuator::turnOff(); 
    }

    void HeaterActuator::toggle() { 
        Actuator::toggle(); 
    }

    std::string HeaterActuator::getDeviceInfo() const {
        return Actuator::getDeviceInfo() + " | Power: " + std::to_string(getPower());
    }

    void HeaterActuator::update(Environment& env, float dt) {
        Actuator::update();
        if (getStatus()) {
            env.applyHeating(getPower(), dt);
        }
    }
} // namespace os
