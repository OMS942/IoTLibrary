#include "Room.hpp"

namespace os {
    Room::Room() : m_roomName("Unknown") {}

    Room::Room(const std::string& name) : m_roomName(name) {}

    Room& Room::operator+=(Device* newDevice) {
        if (newDevice != nullptr) {
            m_devices.push_back(newDevice);
        }
        return *this;
    }

    Room& Room::operator-=(Device* deviceToRemove) {
        if (deviceToRemove == nullptr) {
            throw std::invalid_argument("Attempting to remove non-existing device (nullptr)!");
        }

        auto it = std::find(m_devices.begin(), m_devices.end(), deviceToRemove);

        if (it != m_devices.end()) {
            m_devices.erase(it);
        } else {
            throw std::runtime_error("Error: Device '" + deviceToRemove->getName() + "' is not in this room!");
        }

        return *this;
    }

    void Room::turnOnAll() {
        for (auto d : m_devices) {
            d->setStatus(true);
        }
    }

    void Room::shutdownAll() {
        for (auto d : m_devices) {
            d->setStatus(false);
        }
    }

    const std::vector<Device*>& Room::getDevices() const {
        return m_devices;
    }

} // namespace os