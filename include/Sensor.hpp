#pragma once
#include "Device.hpp"
#include "Environment.hpp"

namespace os {
    /**
     * @brief Template class for senors
     */
    template <typename T>
    class Sensor : public Device {
        protected:
            T value;
            T minVal;
            T maxVal;
            std::string unit;
            bool hasMin;
            bool hasMax;

            /**
             * @brief Updates sensor values and validates data
             * @param newValue New value to save
             * @return true if value is in range
             */
            bool updateValue(T newValue) {
                if ((newValue >= minVal || !hasMin) && (newValue<= maxVal || !hasMax)) {
                    value = newValue;
                    return true;
                } 
                return false;
            }

        public:
            /**
             * @brief Parametrized constructors
             */
            Sensor(int id, const std::string& name, std::string unit) 
                : Device(id, name), value(0), unit(unit), hasMin(false), hasMax(false) {}

            Sensor(int id, const std::string& name, std::string unit, T min, T max) 
                : Device(id, name), value(0), unit(unit), minVal(min), maxVal(max), hasMin(true), hasMax(true) {}

            /**
             * @brief Returns sensor value
             */
            T getValue() const {
                return value;
            }

            /**
             * @brief Returns sensor unit
             */
            std::string getUnit() const {
                return unit;
            }

            /**
             * @brief Returns true if read succesfully
             */
            virtual bool read(const Environment& env) = 0;

            std::string getDeviceInfo() const override {
                return Device::getDeviceInfo() + " | Current Value: " + std::to_string(value) + unit;
            }

    };

} // namespace os