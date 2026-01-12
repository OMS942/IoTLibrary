#include "Actuator.hpp"

namespace os {
    void Actuator::turnOn(int powerLevel, int durationSeconds){
        if (powerLevel < 0 || powerLevel > 100) {
            throw std::out_of_range("Power must be in range 0-100!");
        } 
        power = powerLevel;
        setStatus(power > 0);

        if (durationSeconds > 0) {
            hasTimeout = true;
            offTime = std::chrono::steady_clock::now() + std::chrono::seconds(durationSeconds);
        } else {
            hasTimeout = false;
        }
    }

    void Actuator::turnOff() {
        power = 0;
        hasTimeout = false;
        setStatus(false);
    }

    void Actuator::toggle() {
        if (getStatus()) {
            turnOff();
        } else {
            turnOn();
        }
    }

     void Actuator::update() {
        if (hasTimeout && getStatus()) {
            if (std::chrono::steady_clock::now() >= offTime) {
                turnOff();
            }
        }
    }

    int Actuator::getPower() const {
        return power;
    }

    bool Actuator::setPower(int powerLevel) {
        if (powerLevel < 0 || powerLevel > 100) {
            power = powerLevel;
            return true;
        } else {
            throw std::out_of_range("Power must be in range 0-100!");
            return false;
        }
    }

} // namespace os