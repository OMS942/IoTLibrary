#pragma once
#include "Sensor.hpp"

namespace os {
    class Termometer : public Sensor<float> {
        public: 
            Termometer(int id, const std::string& name, const std::string& unit)
                : Sensor(id, name, "C", -273.0f, 500.0f) {}

            /**
             * @brief Reads temperature
             */
            bool read(const Environment& env) override;

    };

} // namespace os