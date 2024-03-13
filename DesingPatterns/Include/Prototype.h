#pragma once
#include "Preriquisites.h"

// Clase base para los prototipos
class Prototype {
public:
    // M�todo virtual para clonar el prototipo
    virtual Prototype* clonar() = 0;

    // M�todo virtual para configurar el prototipo
    virtual void configurar(string _valor) = 0;

    // M�todo virtual para mostrar el prototipo
    virtual void mostrar() = 0;
};

// Clase concreta del prototipo
class PrototypeConcreto : public Prototype {
public:
    // M�todo para clonar el prototipo concreto
    Prototype* clonar() override {
        PrototypeConcreto* copia = new PrototypeConcreto();
        copia->configurar(valor);
        return copia;
    }

    // M�todo para configurar el valor del prototipo concreto
    void configurar(string _valor) override {
        valor = _valor;
    }

    // M�todo para mostrar el valor del prototipo concreto
    void mostrar() override {
        cout << "Valor: " << valor << endl;
    }

private:
    string valor; // Atributo que almacena el valor del prototipo
};

