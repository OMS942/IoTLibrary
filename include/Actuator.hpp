#pragma once
#include "Device.hpp"
#include <chrono>

namespace os
{
    class Actuator : public virtual Device {
        private:
            int power;
            std::chrono::steady_clock::time_point offTime;
            bool hasTimeout;

        public:
            Actuator();

            Actuator(int id, const std::string& name);

            /**
             * @brief Turns on device
             * @param powerLevel 0-100[%]
             */
            virtual void turnOn(int powerLevel = 100, int durationSeconds = 0);

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
            virtual void update();

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
