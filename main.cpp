/**
 * @file main.cpp
 * @brief Demo of IoTLibrary features: sensors, actuators, environment simulation and exceptions.
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>

#include "Environment.hpp"
#include "HeaterActuator.hpp"
#include "Termometer.hpp"
#include "PlantWatering.hpp"

int main() {
    try {
        std::cout << "=== IoT Library Simulation Demo ===\n\n";

        // --- Initial conditions ---
        float targetTemperature = 22.0f;
        float ambientTemperature = 18.0f;
        float initialTemperature = 20.0f;
        float initialMoisture = 50.0f;

        float minMoisture = 20.0f;
        float maxMoisture = 80.0f;

        // --- Create environment ---
        os::Environment room(initialTemperature, ambientTemperature, initialMoisture);

        // --- Create devices ---
        os::HeaterActuator heater(1, "Main heater");
        os::Termometer tempSensor(2, "Room thermometer", "C", -50.0f, 100.0f);
        os::PlantWatering plant(3, 4, 5); // pump id, sensor id, device id (as you designed)

        std::cout << "Initial state:\n";
        std::cout << "Temperature: " << room.getTemperature() << " C\n";
        std::cout << "Soil moisture: " << room.getSoilMoisture() << " %\n\n";

        // --- Exception demo ---
        std::cout << "Testing exception handling:\n";
        try {
            std::cout << "Trying to set heater power to 200%...\n";
            heater.turnOn(200); // should throw
        }
        catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << "\n\n";
        }

        // --- Start normal operation ---
        std::cout << "Starting simulation loop...\n\n";

        heater.turnOn(70); // safe value

        auto last = std::chrono::steady_clock::now();

        const int SIMULATION_TIME = 60; // seconds
        float elapsed = 0.0f;

        while (elapsed < SIMULATION_TIME) {
            auto now = std::chrono::steady_clock::now();
            float dt = std::chrono::duration<float>(now - last).count();
            last = now;
            elapsed += dt;

            // --- Update world ---
            heater.update(room, dt);
            plant.update(room, dt);

            room.applyCooling(dt);
            room.applyDrying(dt);

            // --- Read sensors ---
            tempSensor.read(room);
            plant.read(room);

            // --- Temperature control ---
            if (tempSensor.getValue() > targetTemperature + 0.5f) {
                heater.turnOff();
            }
            else if (tempSensor.getValue() < targetTemperature - 0.5f) {
                heater.turnOn(70);
            }

            // --- Watering control ---
            if (plant.getValue() > maxMoisture) {
                plant.turnOff();
            }
            else if (plant.getValue() < minMoisture) {
                plant.turnOn(100, 5); // water for 5 seconds
            }

            // --- Print status ---
            std::cout << std::fixed << std::setprecision(2);
            std::cout
                << "Time: " << elapsed << " s | "
                << "Temp: " << tempSensor.getValue() << " " << tempSensor.getUnit() << " | "
                << "Heater: " << (heater.getStatus() ? "ON" : "OFF")
                << " (" << heater.getPower() << "%) | "
                << "Soil: " << plant.getValue() << " " << plant.getUnit() << " | "
                << "Watering: " << (plant.getStatus() ? "ON" : "OFF")
                << "\n";

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        std::cout << "\nSimulation finished successfully.\n";
    }
    catch (const std::exception& e) {
        std::cerr << "\n[FATAL ERROR] " << e.what() << "\n";
    }
    catch (...) {
        std::cerr << "\n[FATAL ERROR] Unknown exception!\n";
    }

    return 0;
}
