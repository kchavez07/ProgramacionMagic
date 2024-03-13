#pragma once
#include "Preriquisites.h"

// Interfaz base para las implementaciones
class Implementacion {
public:
    // Método virtual puro para realizar una operación.
    virtual void operacion() = 0;
};

// Implementacion Concreta A 
class ImplementacionConcretaA : public Implementacion {
public:
    // Implementación concreta del método de operación.
    void operacion() override {
        cout << "Operación en implementación A" << endl;
    }
};

// Implementacion Concreta B
class ImplementacionConcretaB : public Implementacion {
public:
    // Implementación concreta del método de operación.
    void operacion() override {
        cout << "Operación en implementación B" << endl;
    }
};

// Clase Abstracción
class Abstraccion {
public:
    // Constructor que recibe una implementación.
    Abstraccion(Implementacion* imp) : m_implementacion(imp) {}

    // Método virtual puro para realizar una operación.
    virtual void operacion() = 0;

protected:
    Implementacion* m_implementacion;
};

// Abstracción Refinada 
class AbstraccionRefinada : public Abstraccion {
public:
    // Constructor que recibe una implementación.
    AbstraccionRefinada(Implementacion* imp) : Abstraccion(imp) {}

    // Implementación del método de operación.
    void operacion() override {
        // Llama al método de operación de la implementación.
        m_implementacion->operacion();
    }
};
