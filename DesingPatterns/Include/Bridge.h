#pragma once
#include "Preriquisites.h"

// Interfaz base para las implementaciones
class Implementacion {
public:
    // M�todo virtual puro para realizar una operaci�n.
    virtual void operacion() = 0;
};

// Implementacion Concreta A 
class ImplementacionConcretaA : public Implementacion {
public:
    // Implementaci�n concreta del m�todo de operaci�n.
    void operacion() override {
        cout << "Operaci�n en implementaci�n A" << endl;
    }
};

// Implementacion Concreta B
class ImplementacionConcretaB : public Implementacion {
public:
    // Implementaci�n concreta del m�todo de operaci�n.
    void operacion() override {
        cout << "Operaci�n en implementaci�n B" << endl;
    }
};

// Clase Abstracci�n
class Abstraccion {
public:
    // Constructor que recibe una implementaci�n.
    Abstraccion(Implementacion* imp) : m_implementacion(imp) {}

    // M�todo virtual puro para realizar una operaci�n.
    virtual void operacion() = 0;

protected:
    Implementacion* m_implementacion;
};

// Abstracci�n Refinada 
class AbstraccionRefinada : public Abstraccion {
public:
    // Constructor que recibe una implementaci�n.
    AbstraccionRefinada(Implementacion* imp) : Abstraccion(imp) {}

    // Implementaci�n del m�todo de operaci�n.
    void operacion() override {
        // Llama al m�todo de operaci�n de la implementaci�n.
        m_implementacion->operacion();
    }
};
