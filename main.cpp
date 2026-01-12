/**
 * @file main.cpp
 * @brief File demonstrating functions of IoTLibrary.
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Device.hpp"
#include "Sensor.hpp"
#include "Light.hpp"
#include "Room.hpp"
#include "Termometer.hpp"
#include "Environment.hpp"
#include "HeaterActuator.hpp"

int main() {
    using namespace os;

    Environment room(20.0f, 18.0f);
    float dt = 1.0f;
    float targetTemperature = 22.0f;

    HeaterActuator heater(1, "Main heater");
    Termometer tempSensor(2, "Room thermometer", "C");

    std::cout << "Starting simulation...\n";

    heater.turnOn(80, 10);

    auto last = std::chrono::steady_clock::now();

    while (true) {
        auto now = std::chrono::steady_clock::now();
        float dt = std::chrono::duration<float>(now - last).count();
        last = now;

        heater.update(room, dt);
        room.applyCooling(dt);              
        
        tempSensor.read(room);

        if (tempSensor.getValue() > targetTemperature + 0.5f) {
            heater.turnOff();
        } else if (tempSensor.getValue() < targetTemperature - 0.5f) {
            heater.turnOn();
        }

        std::cout
            << "Temp: " << tempSensor.getValue() << " " << tempSensor.getUnit() << " | "
            << "Heater: " << (heater.getStatus() ? "ON" : "OFF") << " | "
            << "Power: " << heater.getPower() << "%\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    std::cout << "Simulation finished.\n";
    return 0;
}

