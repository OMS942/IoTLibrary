#include "Environment.hpp"
#include <stdexcept>

namespace os
{
    Environment::Environment() : temperature(0), ambientTemp(0), soilMoisture(0) {}

    Environment::Environment(float start, float ambient, float initMoisture)
        : temperature(start), ambientTemp(ambient) {
            if (initMoisture > 0 || initMoisture < 100) {
                soilMoisture = initMoisture;
                } else {
                    throw std::invalid_argument("Humidity must be in range 0-100!");
                }
        }

    void Environment::applyHeating(int power, float dt) {
        temperature += 0.01f * power * dt;
    }

    void Environment::applyCooling(float dt) {
        if (temperature > ambientTemp) {
            temperature -= 0.25f * dt;
        }
        if (temperature < ambientTemp) {
            temperature = ambientTemp;
        }
    }

    void Environment::applyWatering(int power, float dt) {
        soilMoisture += 0.1f * power * dt;
    }

    void Environment::applyDrying(float dt) {
        soilMoisture -= 1 * dt;
    }

    float Environment::getTemperature() const { 
        return temperature; 
    }

    void Environment::setTemperature(float temp) {
        if (temp > -273) {
        temperature = temp;
        }
    }

    float Environment::getSoilMoisture() const { 
        return soilMoisture; 
    }

    void Environment::setSoilMoisture(float moisture) {
        if (moisture > 0 || moisture < 100) {
        soilMoisture = moisture;
        }
    }


} // namespace os
