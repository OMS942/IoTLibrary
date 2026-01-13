#pragma once
#include "Device.hpp"
#include <chrono>

namespace os
{
    class Actuator : public Device {
        protected:
            int m_power;
            float m_remainingTime;
            bool m_hasTimeout;

        public:
            Actuator();

            Actuator(int id, const std::string& name);

            /**
             * @brief Turns on device
             * @param powerLevel 0-100[%]
             */
            virtual void turnOn(int powerLevel = 100, float durationSeconds = 0);

            /**
             * @brief Turns off device
             */
            virtual void turnOff();

            /**
             * @brief Toggles device
             */
            virtual void toggle();

            /**
             * @brief Updates devices parameters
             */
            virtual void update(float dt);

            /**
             * @brief Gets device power
             */
            virtual int getPower() const;

            /**
             * @brief Sets device pwoer
             */
            virtual bool setPower(int powerLevel);
    };
    
} // namespace os
