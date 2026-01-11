/**
 * @file main.cpp
 * @brief File demonstrating functions of IoTLibrary.
 */

#include <iostream>
#include <vector>
#include "Device.hpp"
#include "Sensor.hpp"
#include "Light.hpp"
#include "Room.hpp"

int main() {
    // 1. Tworzenie kontenera (Pokoju)
    os::Room salon("Salon Glowny");

    // 2. Tworzenie urządzeń (Dynamiczna alokacja dla polimorfizmu)
    // Wykorzystujemy różne konstruktory (wymaganie projektu)
    os::Light* lampaLustro = new os::Light(101, "Lampa Lustro"); // Domyślna jasność
    os::Light* lampaGlowna = new os::Light(102, "Zyrandol", 75); // Jasność 75%

    // Użycie szablonu dla sensorów (wymaganie projektu)
    os::Sensor<float>* termometr = new os::Sensor<float>(201, "Termometr Zewn", -30.0f, 50.0f);
    os::Sensor<int>* czujnikDymu = new os::Sensor<int>(202, "Czujnik Dymu", 0, 1000);

    // 3. Prezentacja operatora + (wymaganie projektu)
    // Dodajemy urządzenia do pokoju za pomocą przeciążonego operatora
    salon += lampaLustro;
    salon += lampaGlowna;
    salon += termometr;
    salon += czujnikDymu;

    std::cout << "--- Inicjalizacja systemu IoT zakończona ---\n" << std::endl;

    // 4. Prezentacja obsługi wyjątków i walidacji
    std::cout << "[Test Wyjatkow/Walidacji]" << std::endl;
    try {
        std::cout << "Proba ustawienia jasnosci na 150%..." << std::endl;
        if (!lampaGlowna->setBrightness(150)) {
            // Jeśli zdecydowałeś się na zwracanie false zamiast rzucania wyjątków:
            std::cerr << "Blad: Niepoprawna wartosc jasnosci!" << std::endl;
        }
    } catch (const std::exception& e) {
        // Jeśli Twoja biblioteka rzuca wyjątki:
        std::cerr << "Zlapano wyjatek: " << e.what() << std::endl;
    }

    // 5. Symulacja działania (Zmiana stanów)
    termometr->updateValue(22.5f);
    lampaLustro->turnOn();
    
    // 6. Prezentacja polimorfizmu i raportowania (Brak std::cout wewnątrz klas!)
    // Metoda showStatus() wewnątrz zbiera dane z getDeviceInfo() każdego urządzenia
    std::cout << "\n[Pelny Raport Systemu]" << std::endl;
    std::cout << salon.showStatus() << std::endl;

    // 7. Porównywanie urządzeń (Przeciążony operator ==)
    std::cout << "[Test Operatora ==]" << std::endl;
    if (*lampaLustro == *lampaGlowna) {
        std::cout << "Urzadzenia maja to samo ID." << std::endl;
    } else {
        std::cout << "Urzadzenia maja rozne ID (Prawidlowo)." << std::endl;
    }

    // 8. Sprzątanie (Bardzo ważne w EiT!)
    // Jeśli Twoja klasa Room nie usuwa wskaźników w destruktorze, zrób to tutaj:
    delete lampaLustro;
    delete lampaGlowna;
    delete termometr;
    delete czujnikDymu;

    std::cout << "\nSystem zostal poprawnie zamkniety." << std::endl;

    return 0;
}


