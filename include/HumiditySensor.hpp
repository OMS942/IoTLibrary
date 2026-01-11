#pragma once
#include "Sensor.hpp"

namespace os {
    class HumiditySensor : public Sensor<int> {
        public: 
            HumiditySensor(int id, const std::string& name, const std::string& unit)
                : Sensor(id, name, "%", 0, 100) {}

            /**
             * @brief Reads humitidy
             */
            bool read() override;

    };

} // namespace os