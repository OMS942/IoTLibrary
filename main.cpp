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
#include "Room.hpp"
#include "Schedule.hpp"


int main() {
    try {
        std::cout << "=== IoT Library Simulation Demo ===\n\n";

        // --- Initial conditions ---
        float targetTemperature = 22.0f;
        float ambientTemperature = 18.0f;
        float initialTemperature = 24.0f;

        // --- Create environment ---
        os::Environment room(initialTemperature, ambientTemperature);

        os::Schedule schedule;

        // --- Create devices ---
        os::HeaterActuator heater(1, "Main heater");
        os::Termometer tempSensor(2, "Room thermometer", "C", -50.0f, 100.0f);

        std::cout << "Initial state:\n";
        std::cout << "Temperature: " << room.getTemperature() << " C\n\n";
        
        os::Room livingRoom("Living room");
        livingRoom += &heater;
        livingRoom += &tempSensor;

        // Schedule turning on pump in first second
        schedule.addEvent({1.0f, &heater, true, 100, 5});
        // Schedule turning of pump in third second
        schedule.addEvent({3.0f, &heater, false, 0, 0});

        std::cout << "Turning ON all devices via Room...\n";
        livingRoom.turnOnAll();
        std::cout << "Heater status: " << (heater.getStatus() ? "ON" : "OFF") << "\n\n";

        std::cout << "Turning OFF all devices via Room...\n";
        livingRoom.shutdownAll();
        std::cout << "Heater status: " << (heater.getStatus() ? "ON" : "OFF") << "\n\n";

        std::cout << "--- Room device list (initial) ---\n";
        for (auto d : livingRoom.getDevices()) {
            std::cout << " * " << d->getName() << " [ID=" << d->getId() << "]\n";
        }
        std::cout << "\n";

        // Remove the thermometer
        std::cout << "\nRemoving thermometer using -= ...\n";
        livingRoom -= &tempSensor;

        std::cout << "--- Room device list (after removal) ---\n";
        for (auto d : livingRoom.getDevices()) {
            std::cout << " * " << d->getName() << " [ID=" << d->getId() << "]\n";
        }
        std::cout << "\n";

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
            schedule.update(elapsed);

            room.applyCooling(dt);

            // --- Read sensors ---
            tempSensor.read(room);

            if (elapsed > 5) {
                // --- Temperature control ---
                if ((tempSensor.getValue() > targetTemperature + 0.5f) && heater.getStatus()) {
                    heater.turnOff();
                }
                else if ((tempSensor.getValue() < targetTemperature - 0.5f) && !heater.getStatus()) {
                    heater.turnOn(70);
                }
            }
            
            // --- Print status ---
            std::cout << std::fixed << std::setprecision(2);
            std::cout
                << "Time: " << elapsed << " s | "
                << "Temp: " << tempSensor.getValue() << " " << tempSensor.getUnit() << " | "
                << "Heater: " << (heater.getStatus() ? "ON" : "OFF")
                << " (" << heater.getPower() << "%) | "
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