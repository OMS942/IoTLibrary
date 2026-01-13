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

    public:
        Environment();    

        /**
         * @brief Parametric constructor
         * @throw std::invalid_argument if temp below absolute zero
         */
        Environment(float startTemp);

        /**
         * @brief Apply heating to the environment
         * @param power Power level of the heater (0-100)
         * @param dt Time step in seconds
         */
        void applyHeating(int power, float dt);

        /**
         * @brief Simulate the environment cooling to absolute zero
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
         * @throw std::invalid_argument if temp below absolute zero
         */
        void setTemperature(float temp);

    };
    
} // namespace os



