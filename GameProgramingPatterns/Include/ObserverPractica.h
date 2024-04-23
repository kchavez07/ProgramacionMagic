#pragma once
#include "Prereriquisites.h"

// Interfaz Observer
class Observer {
public:
    virtual void update(const string& message) = 0;
};

// Clase Subject
class Subject {
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void notifyObservers(const string& message) {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }

private:
    vector<Observer*> observers;
};

// Clase MessageApp que actúa como Subject
class MessageApp : public Subject {
public:
    void receiveMessage(const string& message) {
        cout << "Mensaje recibido: " << message << endl;
        notifyObservers(message);
    }
};

// Clases Observadoras concretas
class SoundNotification : public Observer {
public:
    void update(const string& message) override {
        cout << "Notificación de sonido: Ding! Ding!" << endl;
    }
};

class VibrationNotification : public Observer {
public:
    void update(const string& message) override {
        cout << "Notificación de vibración: ¡Vibrando!" << endl;
    }
};

class ScreenNotification : public Observer {
public:
    void update(const string& message) override {
        cout << "Notificación en pantalla: Nuevo mensaje recibido: " << message << endl;
    }
};
