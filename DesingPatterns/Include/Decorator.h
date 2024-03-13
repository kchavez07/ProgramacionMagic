#pragma once
#include "Preriquisites.h"

// Clase base para los componentes
class Componente {
public:
    // M�todo virtual puro para realizar una operaci�n.
    virtual void operacion() = 0;
};

// Clase concreta que implementa Componente
class ComponenteConcreto : public Componente {
public:
    // Implementaci�n concreta del m�todo de operaci�n.
    void operacion() override {
        cout << "Operaci�n del componente concreto" << endl;
    }
};

// Clase base para los decoradores
class Decorator : public Componente {
public:
    // Constructor que recibe un componente para decorar.
    Decorator(Componente* componente) : m_componente(componente) {}

    // Implementaci�n del m�todo de operaci�n que delega al componente original.
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

    // Implementaci�n adicional del m�todo de operaci�n.
    void operacion() override {
        Decorator::operacion(); // Llama al m�todo del componente original.
        cout << "Operaci�n del Decorator A." << endl;
    }
};

// Otro decorador concreto B
class DecoratorConcretoB : public Decorator {
public:
    // Constructor que recibe un componente para decorar.
    DecoratorConcretoB(Componente* componente) : Decorator(componente) {}

    // Implementaci�n adicional del m�todo de operaci�n.
    void operacion() override {
        Decorator::operacion(); // Llama al m�todo del componente original.
        cout << "Operaci�n del Decorator B." << endl;
    }
};
