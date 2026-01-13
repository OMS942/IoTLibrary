#pragma once
#include "Sensor.hpp"

namespace os {
    class Termometer : public Sensor<float> {
        public: 
            Termometer();
            
            Termometer(int id, const std::string& name, const std::string& unit, float minValue, float maxValue);

            /**
             * @brief Reads temperature
             */
            bool read(const Environment& env) override;

    };

} // namespace os