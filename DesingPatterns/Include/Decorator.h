#pragma once
#include "Preriquisites.h"

// Clase base para los componentes
class Componente {
public:
    // Método virtual puro para realizar una operación.
    virtual void operacion() = 0;
};

// Clase concreta que implementa Componente
class ComponenteConcreto : public Componente {
public:
    // Implementación concreta del método de operación.
    void operacion() override {
        cout << "Operación del componente concreto" << endl;
    }
};

// Clase base para los decoradores
class Decorator : public Componente {
public:
    // Constructor que recibe un componente para decorar.
    Decorator(Componente* componente) : m_componente(componente) {}

    // Implementación del método de operación que delega al componente original.
    void operacion() override {
        m_componente->operacion();
    }

private:
    Componente* m_componente; // Almacena una instancia del componente a decorar.
};

// Decorador concreto A
class DecoratorConcretoA : public Decorator {
public:
    // Constructor que recibe un componente para decorar.
    DecoratorConcretoA(Componente* componente) : Decorator(componente) {}

    // Implementación adicional del método de operación.
    void operacion() override {
        Decorator::operacion(); // Llama al método del componente original.
        cout << "Operación del Decorator A." << endl;
    }
};

// Otro decorador concreto B
class DecoratorConcretoB : public Decorator {
public:
    // Constructor que recibe un componente para decorar.
    DecoratorConcretoB(Componente* componente) : Decorator(componente) {}

    // Implementación adicional del método de operación.
    void operacion() override {
        Decorator::operacion(); // Llama al método del componente original.
        cout << "Operación del Decorator B." << endl;
    }
};
