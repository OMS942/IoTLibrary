#pragma once
#include "Actuator.hpp" 
#include "Environment.hpp"

namespace os
{
    class HeaterActuator : public Actuator {
        public:
            HeaterActuator(int id, const std::string& name) : Actuator(id, name) {}

            /**
             * @brief Turns on heating
             * @param powerLevel Power level of the heater (0-100), default 100
             * @param durationSeconds Duration in seconds, defaul 0
             */
            void turnOn(int powerLevel = 100, int durationSeconds = 0) override;

            /**
             * @brief Turns off heating
             */
            void turnOff() override;
            
            /**
             * @brief Toggles heating
             */
            void toggle() override; 

            /**
             * @brief Simulate heating in environment
             * @param env Environment for heating 
             * @param dt Time step in seconds
             */
            void update(Environment& env, float dt);

    };
} // namespace os



