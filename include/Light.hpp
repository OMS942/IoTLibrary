#pragma once
#include "Actuator.hpp"

namespace os {
    class Light : public Actuator {
        private: 
            int brightness;
            static constexpr int MAX_BRIGHTNESS = 100;

        public:
            Light(int id, std::string name);
            Light(int id, std::string name, int initialBrightness);

            /**
             * @brief Sets brightness and validates data
             */
            bool setBrightness(int brightness);

            std::string getDeviceInfo() const override;
    };

} // namespace os