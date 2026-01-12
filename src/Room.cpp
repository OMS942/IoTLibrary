#include "Room.hpp"

namespace os {
    Room::Room(std::string name) : roomName(name) {}

    Room::~Room() {
        for (auto d : devices) delete d;
    }

    Room& Room::operator+=(Device* newDevice) {
        if (newDevice != nullptr) {
            devices.push_back(newDevice);
        }
        return *this;
    }

    Room& Room::operator-=(Device* deviceToRemove) {
        if (deviceToRemove == nullptr) {
            throw std::invalid_argument("Attempting to remove non-existing device (nullptr)!");
        }

        auto it = std::find(devices.begin(), devices.end(), deviceToRemove);

        if (it != devices.end()) {
            devices.erase(it);
        } else {
            throw std::runtime_error("Error: Device '" + deviceToRemove->getName() + "' is not in this room!");
        }

        return *this;
    }

    void Room::shutdownAll() {
        for (auto d : devices) {
            d->setStatus(false);
        }
    }

    /*

    std::string Room::showStatus() const {
        std::string report = "Room status: " + roomName + "\n";
        for (auto d : devices) {
           report += d->getDeviceInfo() + "\n";
        }
        return report;
    }

    */

} // namespace os