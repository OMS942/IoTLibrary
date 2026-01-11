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
            std::string roomName;
            std::vector<Device*> devices;

        public:
            Room(std::string name);

            ~Room();

            /**
             * @brief Operator for adding devices to room.
             */
            Room& operator+=(Device* newDevice);

            /**
             * @brief Operator for removing devices to room.
             */
            Room& operator-=(Device* newDevice);

            /**
             * @brief Turn off all devices in room
             */
            void shutdownAll();

            /**
             * @brief Shows status of all devices in room.
             */
            std::string showStatus() const;

    };

} // namespace os