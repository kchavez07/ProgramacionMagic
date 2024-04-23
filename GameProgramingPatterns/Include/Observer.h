#pragma once
#include "Prereriquisites.h"

// Clase base Observer que define la interfaz para todos los observadores
class Observer {
public:
    // Método virtual para actualizar el estado del observador
    virtual void update(int temperature) = 0;
};

// Clase Subject que representa el objeto observado
class TemperatureSensor {
public:
    // Método para añadir un observador al sensor de temperatura
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    // Método para notificar a todos los observadores cuando cambia la temperatura
    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(temperature);
        }
    }

    // Método para establecer la temperatura y notificar a los observadores
    void setTemperature(int temp) {
        temperature = temp;
        notifyObservers();
    }

private:
    int temperature; // Estado del sujeto observado
    vector<Observer*> observers; // Lista de observadores
};

// Clase concreta que implementa el Observer para mostrar la temperatura en un dispositivo de visualización
class DisplayDevice : public Observer {
public:
    // Método para actualizar el estado del observador con la nueva temperatura
    void update(int temperature) override {
        cout << "Temperatura actual: " << temperature << " grados Celsius." << endl;
    }
};