#include "Device.hpp"

namespace os {
    Device::Device() : m_id(0), m_name("Unknown"), m_status(false) {}

    Device::Device(int id, std::string name) {
        if (id < 0) {
            throw std::invalid_argument("ID can't be negative!");
        }
        this->m_id = id;
        this->m_name = name;
    }

    int Device::getId() const {
        return m_id;
    }

    void Device::setId(int newID) {
        if (newID < 0) {
            throw std::invalid_argument("ID cannot be negative!");
        }
        m_id = newID;
    }

    const std::string& Device::getName() const {
        return m_name;
    }

    void Device::setName(std::string newName) {
        m_name = newName;
    }

    bool Device::getStatus() const {
        return m_status;
    }

    void Device::setStatus(bool newStatus) {
        m_status = newStatus;
    }

    bool Device::operator==(const Device& other) const {
        return this->m_id == other.m_id;
    }

}