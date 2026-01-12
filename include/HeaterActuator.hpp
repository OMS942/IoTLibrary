#pragma once
#include "Actuator.hpp" 
#include "Environment.hpp"

namespace os
{
    class HeaterActuator : public Actuator {
        public:
            HeaterActuator(int id, const std::string& name)
                : Actuator(id, name) {}

            void turnOn(int powerLevel = 100, int durationSeconds = 0) override;

            void turnOff() override;
            
            void toggle() override; 
            
            std::string getDeviceInfo() const override;

            void update(Environment& env, float dt);

    };
} // namespace os



