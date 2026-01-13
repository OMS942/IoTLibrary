/**
 * @file Environment.hpp
 * @brief Defines the Environment class which simulates the room conditions.
 */
#pragma once

namespace os
{
    class Environment {
    private:
        float m_temperature;
        float m_ambientTemp;


    public:
        Environment();    

        Environment(float start, float ambient);

        /**
         * @brief Apply heating to the environment
         * @param power Power level of the heater (0-100)
         * @param dt Time step in seconds
         */
        void applyHeating(int power, float dt);

        /**
         * @brief Simulate the environment cooling to ambient temperature
         * @param dt Time step in seconds
         */
        void applyCooling(float dt);

        /**
         * @brief Get current temperature
         * @return Temperature in Celsius
         */
        float getTemperature() const;

        /**
         * @brief Sets current temperature
         */
        void setTemperature(float temp);

    };
    
} // namespace os



