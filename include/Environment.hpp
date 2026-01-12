/**
 * @file Environment.hpp
 * @brief Defines the Environment class which simulates the room conditions.
 */
#pragma once

namespace os
{
    class Environment {
    private:
        float temperature;
        float ambientTemp;
        float soilMoisture;

    public:
        Environment();    

        Environment(float start, float ambient, float initMoisture);

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
         * @brief Simulate watering
         */
        void applyWatering(int power, float dt);

        /**
         * @brief Simulate drying of soil
         * @param dt Time step in seconds
         */
        void applyDrying(float dt);

        /**
         * @brief Get current temperature
         * @return Temperature in Celsius
         */
        float getTemperature() const;

        /**
         * @brief Sets current temperature
         */
        void setTemperature(float temp);

        /**
         * @brief Get current soil moisture
         * @return soil moisture 
         */
        float getSoilMoisture() const;

        /**
         * @brief Sets current soil moisture
         */
        void setSoilMoisture(float moisture);


    };
} // namespace os



