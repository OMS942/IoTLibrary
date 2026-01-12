#pragma once

#include <string>
#include <stdexcept>

namespace os {

    /**
     * @brief Class representing generic IoT device.
     */
    class Device {
        private:
            int id;
            std::string name;
            bool status;

        public:
            /**
             * @brief Default constructor
             */
            Device();

            /** 
             * @brief Parametric constructor
             * @param id uniqe device id
             * @param name device name
             * @throw std::invalid_argument if id < 0
             */
            Device(int id, std::string name);

            /**
             * @brief Virtual destructor 
             */
            virtual ~Device() = default;

            /**
             * @brief Returns device ID
             */
            int getId() const;

            /**
             * @brief Sets device ID
             */
            void setId(int newID);

            /**
             * @brief Returns device name
             */
            const std::string& getName() const;

            /**
             * @brief Sets device name
             */
            void setName(std::string name);
            
            /**
             * @brief Returns device status
             */
            bool getStatus() const;

            /**
             * @brief Sets device status
             */
            void setStatus(bool newStatus);

            /**
             * @brief Seting compare operator
             */
            bool operator==(const Device& other) const;

    };

} // namespace os