#include "Room.hpp"

namespace os {
    Room::Room(std::string name) : roomName(name) {}

    Room::~Room() {
        for (auto d : devices) delete d;
    }

    Room& Room::operator+(Device* newDevice) {
        if (newDevice != nullptr) {
            devices.push_back(newDevice);
        }
        return *this;
    }

    void Room::shutdownAll() {
        for (auto d : devices) {
            d->setStatus(false);
        }
    }

    std::string Room::showStatus() const {
        std::string report = "Status pokoju: " + roomName + "\n";
        for (auto d : devices) {
           report += d->getDeviceInfo() + "\n";
        }
        return report;
    }

} // namespace os