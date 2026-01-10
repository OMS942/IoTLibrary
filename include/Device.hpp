#pragma once

#include <string>
#include <stdexcept>

namespace os {

    /**
     * @brief Class representing genergic IoT device.
     */
    class Device {
        protected:
            int id;
            std::string name;
            bool status;

        public:
            /**
             * Default constructor
             */
            Device();

            /** 
             * @brief Parametric constructor
             * @param id uniqe device id
             * @param name device name
             */
            Device(int id, std::string name);

            /**
             * @brief Virtual destructor 
             */
            virtual ~Device() = default;

            /**
             * @brief Id getter
             */
            int getId() const {
                return id;
            }
            
            /**
             * @brief Status getter
             */
            bool getStatus() const {
                return status;
            }

            /**
             * @brief Sets device status
             * @return true if success
             */
            bool setStatus(bool newStatus);

            virtual std::string getDeviceInfo() const;

            bool operator==(const Device& other) const {
                return this->id == other.id;
            }

    };

} // namespace os