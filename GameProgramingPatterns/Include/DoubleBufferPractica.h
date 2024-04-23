#pragma once
#include "Prereriquisites.h"

// Clase para representar objetos del juego
class GameObject {
public:
    GameObject(const string& name, int x, int y) : name(name), x(x), y(y) {}

    void setPosition(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void printInfo() const {
        cout << "Nombre: " << name << ", Posición: (" << x << ", " << y << ")" << endl;
    }

private:
    string name;
    int x;
    int y;
};

// Clase que gestiona el Double Buffer y la actualización de objetos del juego
class Game {
public:
    Game() : buffer1(), buffer2(), activeBuffer(&buffer1) {}

    void UpdateGameObjects() {
        // Simulación de la actualización de objetos del juego
        activeBuffer->clear();
        activeBuffer->emplace_back("Objeto1", 10, 20);
        activeBuffer->emplace_back("Objeto2", 30, 40);
    }

    void SwapBuffers() {
        activeBuffer = (activeBuffer == &buffer1) ? &buffer2 : &buffer1;
    }

    void PrintActiveObjects() const {
        cout << "Objetos activos en el buffer:" << endl;
        for (const auto& obj : *activeBuffer) {
            obj.printInfo();
        }
        cout << endl;
    }

private:
    vector<GameObject> buffer1;
    vector<GameObject> buffer2;
    vector<GameObject>* activeBuffer;
};
