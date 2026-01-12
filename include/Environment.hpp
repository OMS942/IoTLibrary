#pragma once

class Environment {
    float temperature;
    float ambientTemp;

public:
    Environment(float start, float ambient)
        : temperature(start), ambientTemp(ambient) {}

    void applyHeating(float power, float dt) {
        temperature += 0.01f * power * dt;
    }

    void applyCooling(float dt) {
        if (temperature > ambientTemp)
            temperature -= 0.25f * dt;
        if (temperature < ambientTemp)
            temperature = ambientTemp;
    }

    float getTemperature() const { 
        return temperature; 
    }
};
