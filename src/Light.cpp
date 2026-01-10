#include "Light.hpp"

namespace os {
    Light::Light(int id, std::string name) : Actuator(id, name), brightness(0) {}
    Light::Light(int id, std::string name, int brightness) : Actuator(id, name) {
        if (!setBrightness(brightness)) {
            brightness = 0;
        } 
    }

    bool Light::setBrightness(int level) {
        if (level < 0 || level > MAX_BRIGHTNESS) {
            throw std::out_of_range("Wrong brightness value");
            return false;
        }
        brightness = level;
        return true;
    }

    std::string Light::getDeviceInfo() const {
    return Actuator::getDeviceInfo() + " | Brightness: " + std::to_string(brightness) + "%";
    }   
    
} // namespace os