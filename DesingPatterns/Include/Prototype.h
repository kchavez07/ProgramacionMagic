#pragma once
#include "Preriquisites.h"

// Clase base para los prototipos
class Prototype {
public:
    // Método virtual para clonar el prototipo
    virtual Prototype* clonar() = 0;

    // Método virtual para configurar el prototipo
    virtual void configurar(string _valor) = 0;

    // Método virtual para mostrar el prototipo
    virtual void mostrar() = 0;
};

// Clase concreta del prototipo
class PrototypeConcreto : public Prototype {
public:
    // Método para clonar el prototipo concreto
    Prototype* clonar() override {
        PrototypeConcreto* copia = new PrototypeConcreto();
        copia->configurar(valor);
        return copia;
    }

    // Método para configurar el valor del prototipo concreto
    void configurar(string _valor) override {
        valor = _valor;
    }

    // Método para mostrar el valor del prototipo concreto
    void mostrar() override {
        cout << "Valor: " << valor << endl;
    }

private:
    string valor; // Atributo que almacena el valor del prototipo
};

