#pragma once
#include "Device.hpp"
#include <vector>
#include <algorithm>
#include <memory>

namespace os {
    /**
     * @brief Class managing devices in rooms.
     */
    class Room {
        private:
            std::string m_roomName;
            std::vector<Device*> m_devices;

        public:
            Room(const std::string& name);

            /**
             * @brief Operator for adding devices to room.
             */
            Room& operator+=(Device* newDevice);

            /**
             * @brief Operator for removing devices to room.
             */
            Room& operator-=(Device* newDevice);

            /**
             * @brief Turn on all devices in room
             */
            void turnOnAll();

            /**
             * @brief Turn off all devices in room
             */
            void shutdownAll();

            /**
             * @brief Get all devices (raw pointers)
             */
            const std::vector<Device*>& getDevices() const;

    };

} // namespace os