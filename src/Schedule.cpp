#include "Schedule.hpp"

namespace os
{
    void Schedule::addEvent(const Event& e) {
        m_events.push_back(e);
        std::sort(m_events.begin(), m_events.end(),
                  [](const Event& a, const Event& b) { return a.time < b.time; });
    }

    void Schedule::update(float currentTime) {
        while (m_nextEventIndex < m_events.size() && m_events[m_nextEventIndex].time <= currentTime) {
            Event& e = m_events[m_nextEventIndex];
            if (e.turnOn) {
                if (auto act = dynamic_cast<Actuator*>(e.device)) {
                    act->turnOn(e.powerLevel, e.duration);
                } else {
                    e.device->setStatus(true);
                }
            } else {
                if (auto act = dynamic_cast<Actuator*>(e.device))
                    act->turnOff();
                else
                    e.device->setStatus(false);
            }
            m_nextEventIndex++;
        }
    }

    void Schedule::reset() { 
        m_nextEventIndex = 0; 
    }
} // namespace os
