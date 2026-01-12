/**
 * @file Environment.hpp
 * @brief Defines the Environment class which simulates the room conditions.
 */
#pragma once

class Environment {
    float temperature;
    float ambientTemp;

public:
    Environment(float start, float ambient)
        : temperature(start), ambientTemp(ambient) {}

    /**
     * @brief Apply heating to the environment
     * @param power Power level of the heater (0-100)
     * @param dt Time step in seconds
     */
    void applyHeating(int power, float dt) {
        temperature += 0.01f * power * dt;
    }

    /**
     * @brief Simulate the environment cooling to ambient temperature
     * @param dt Time step in seconds
     */
    void applyCooling(float dt) {
        if (temperature > ambientTemp)
            temperature -= 0.25f * dt;
        if (temperature < ambientTemp)
            temperature = ambientTemp;
    }

    /**
     * @brief Get the current temperature
     * @return Temperature in Celsius
     */
    float getTemperature() const { 
        return temperature; 
    }
};
