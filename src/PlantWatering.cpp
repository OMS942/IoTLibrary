#include "PlantWatering.hpp"

namespace os
{
    PlantWatering::PlantWatering(int deviceID, int deviceSensorID, int deviceActuatorID) 
        : Device(deviceID, "Plant Watering System"), 
        Actuator(deviceSensorID, "Water Pump"), 
        Sensor<float>(deviceActuatorID, "Soil Sensor", "%", 0, 100) {}

    bool PlantWatering::read(const Environment& env) {
        return updateValue(env.getSoilMoisture());
    }

    void PlantWatering::turnOn(int powerLevel, int durationSeconds) {
        Actuator::turnOn(powerLevel, durationSeconds);
        
        if (powerLevel > 80) powerLevel = 80;
        Actuator::turnOn(powerLevel, durationSeconds);
    }

    void PlantWatering::turnOff() { 
        Actuator::turnOff(); 
    }

    void PlantWatering::toggle() { 
        Actuator::toggle(); 
    }

    void PlantWatering::update(Environment& env, float dt) {
        Actuator::update();
        if (getStatus()) {
            env.applyWatering(getPower(), dt);
        }
    }

} // namespace os


