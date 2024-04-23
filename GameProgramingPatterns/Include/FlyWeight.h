#pragma once 
#include "Prereriquisites.h"

// Clase base que define la interfaz Flyweight
class Flyweight {
public:
    // Método virtual puro para dibujar el objeto en una posición (x, y)
    virtual void draw(int x, int y) = 0;
};

// Clase concreta que implementa Flyweight y representa un objeto compartido
class ConcreteFlyweight : public Flyweight {
public:
    // Constructor que recibe un símbolo único para el objeto compartido
    ConcreteFlyweight(char _symbol) : symbol(_symbol) {}

    // Implementación del método draw para mostrar el símbolo en la posición (x, y)
    void draw(int x, int y) override {
        cout << symbol << " drawn at " << x << ", " << y << endl;
    }

private:
    char symbol; // Símbolo único que representa este objeto
};

// Fábrica que gestiona la creación y reutilización de objetos Flyweight
class FlyweightFactory {
public:
    // Método para obtener un objeto Flyweight compartido basado en un símbolo
    Flyweight* getFlyWeight(char _symbol) {
        // Verificar si ya existe el objeto con el símbolo dado
        if (m_flyweights.find(_symbol) == m_flyweights.end()) {
            // Si no existe, crear un nuevo ConcreteFlyweight con el símbolo y guardarlo
            m_flyweights[_symbol] = new ConcreteFlyweight(_symbol);
        }
        // Devolver el objeto Flyweight correspondiente al símbolo
        return m_flyweights[_symbol];
    }

private:
    unordered_map<char, Flyweight*> m_flyweights; // Mapa para almacenar objetos Flyweight
};