#pragma once
#include "Actuator.hpp"
#include "Sensor.hpp"
#include "Environment.hpp"

namespace os
{
    class PlantWatering : public Sensor<float>, public Actuator {
        public:
            PlantWatering(int deviceID, int deviceSensorID, int deviceActuatorID);

            bool read(const Environment& env) override;
            
            /**
             * @brief Turns on pump
             * @param powerLevel Power level of the pump (0-100), default 100
             * @param durationSeconds Duration in seconds, defaul 0
             */
            void turnOn(int powerLevel = 100, int durationSeconds = 0) override;

            /**
             * @brief Turns off pmup
             */
            void turnOff() override;
            
            /**
             * @brief Toggles pump
             */
            void toggle() override; 

            /**
             * @brief Simulate environment
             * @param env Environment 
             * @param dt Time step in seconds
             */
            void update(Environment& env, float dt);

            

    };
} // namespace os
