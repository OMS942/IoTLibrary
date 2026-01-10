#pragma once
#include "Device.hpp"

namespace os
{
    class Actuator : public Device {
        public:
            Actuator(int id, std::string name) : Device(id, name) {}

            virtual void turnOn(){
                setStatus(true);
            }

            virtual void turnOff() {
                setStatus(false);
            }

            virtual void toogle() {
                if (getStatus()) {
                    setStatus(false);
                } else {
                    setStatus(true);
                }
            }
    };
    
} // namespace os
