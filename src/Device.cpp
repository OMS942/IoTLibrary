#include "Device.hpp"

namespace os {
    Device::Device() : id(0), name("Unknown"), status(false) {}

    Device::Device(int id, std::string name) : Device() {
        if (id < 0) {
            throw std::invalid_argument("ID can't be negative!");
        }
        this->id = id;
        this->name = name;
    }
    int Device::getId() const {
        return id;
    }

    void Device::setId(int newID) {
        if (id < 0) {
            throw std::invalid_argument("ID cannot be negative!");
        }
        id = newID;
    }

    const std::string& Device::getName() const {
        return name;
    }

    void Device::setName(std::string newName) {
        name = newName;
    }

    bool Device::getStatus() const {
        return status;
    }

    void Device::setStatus(bool newStatus) {
        status = newStatus;
    }

    bool Device::operator==(const Device& other) const {
        return this->id == other.id;
    }

}