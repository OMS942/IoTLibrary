#pragma once
#include <vector>
#include <algorithm>
#include "Device.hpp"
#include "Actuator.hpp"

namespace os {

/**
 * @ Struct defining single events
 * @param time time in seconds when event will happen
 * @param device device
 * @param turnOn true = turn on, false = turn off
 * @param powerLevel optional param for actuators
 * @param duration optional param for actuators
 */
struct Event {
    float time;          
    Device* device;    
    bool turnOn;          
    int powerLevel;      
    float duration;        
};

class Schedule {
private:
    std::vector<Event> m_events;
    size_t m_nextEventIndex = 0;

public:
    Schedule() = default;

    /**
     * @brief Adds event using struct
     * @param e Struct with event details
     */
    void addEvent(const Event& e);

    /**
     * @brief Simulates time flow
     * @param currentTime Current time
     */
    void update(float currentTime);

    /**
     * @brief Reset all planned events
     */
    void reset();
};

} // namespace os
