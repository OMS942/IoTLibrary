#pragma once
#include "Device.hpp"

namespace os {
    /**
     * @brief Template class for senors
     */
    template <typename T>
    class Sensor : public Device {
        private:
            T value;
            T minVal;
            T maxVal;

        public:
            Sensor(int id, std::string name, T min, T max) : Device(id, name), minVal(min), maxVal(max) {}

            /**
             * @brief Updates sensor values and validates data
             * @param newValue New value to save
             * @return true if value is in range
             */
            bool updateValue(T newValue) {
                if (newValue >= minVal && newValue<= maxVal) {
                    return true;
                } 
                return false;
            }

            T getValue() const {
                return value;
            }

            std::string getDeviceInfo() const override {
                return Device::getDeviceInfo() + " | Current Value: " + std::to_string(value);
            }

    };

} // namespace os