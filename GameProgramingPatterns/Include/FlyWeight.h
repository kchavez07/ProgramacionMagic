#pragma once 
#include "Prereriquisites.h"

// Clase base que define la interfaz Flyweight
class Flyweight {
public:
    // M�todo virtual puro para dibujar el objeto en una posici�n (x, y)
    virtual void draw(int x, int y) = 0;
};

// Clase concreta que implementa Flyweight y representa un objeto compartido
class ConcreteFlyweight : public Flyweight {
public:
    // Constructor que recibe un s�mbolo �nico para el objeto compartido
    ConcreteFlyweight(char _symbol) : symbol(_symbol) {}

    // Implementaci�n del m�todo draw para mostrar el s�mbolo en la posici�n (x, y)
    void draw(int x, int y) override {
        cout << symbol << " drawn at " << x << ", " << y << endl;
    }

private:
    char symbol; // S�mbolo �nico que representa este objeto
};

// F�brica que gestiona la creaci�n y reutilizaci�n de objetos Flyweight
class FlyweightFactory {
public:
    // M�todo para obtener un objeto Flyweight compartido basado en un s�mbolo
    Flyweight* getFlyWeight(char _symbol) {
        // Verificar si ya existe el objeto con el s�mbolo dado
        if (m_flyweights.find(_symbol) == m_flyweights.end()) {
            // Si no existe, crear un nuevo ConcreteFlyweight con el s�mbolo y guardarlo
            m_flyweights[_symbol] = new ConcreteFlyweight(_symbol);
        }
        // Devolver el objeto Flyweight correspondiente al s�mbolo
        return m_flyweights[_symbol];
    }

private:
    unordered_map<char, Flyweight*> m_flyweights; // Mapa para almacenar objetos Flyweight
};