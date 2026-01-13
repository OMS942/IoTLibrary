#include "Actuator.hpp"

namespace os {
    Actuator::Actuator() : Device(), m_power(0), m_hasTimeout(false) {}

    Actuator::Actuator(int id, const std::string& name) : Device(id, name), m_power(0), m_hasTimeout(false) {}

    void Actuator::turnOn(int powerLevel, float durationSeconds){
        if (powerLevel < 0 || powerLevel > 100) {
            throw std::out_of_range("Power must be in range 0-100!");
        } 
        m_power = powerLevel;
        setStatus(m_power > 0);

        m_remainingTime = durationSeconds;
        m_hasTimeout = durationSeconds > 0;
    }

    void Actuator::turnOff() {
        m_power = 0;
        m_hasTimeout = false;
        setStatus(false);
    }

    void Actuator::toggle() {
        if (getStatus()) {
            turnOff();
        } else {
            turnOn();
        }
    }

     void Actuator::update(float dt) {
        if (m_hasTimeout && getStatus()) {
            m_remainingTime -= dt;
            if (m_remainingTime <= 0.0f) {
                turnOff();
            }
        }
    }

    int Actuator::getPower() const {
        return m_power;
    }

    bool Actuator::setPower(int powerLevel) {
        if (powerLevel < 0 || powerLevel > 100) {
            throw std::out_of_range("Power must be in range 0-100!");      
        } else {
            m_power = powerLevel;
            return true;
        }
    }

} // namespace os