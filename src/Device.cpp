#include "Device.hpp"

namespace os {
    Device::Device() : id(0), name("Unknown"), status(false) {}

    Device::Device(int id, std::string name) : id(id), name(name), status(false) {
        if (id < 0) {
            throw std::invalid_argument("ID can't be negative!");
        }
    }

    bool Device::setStatus(bool newStatus) {
        status = newStatus;
        return true;
    }

    std::string Device::getDeviceInfo() const {
        return "ID: " + std::to_string(id) + " | Name: " + name + " | Status: " + (status ? "ON" : "OFF");
    }

}