#pragma once
#include "Preriquisites.h"

// Clase base Refrigerador que define la estructura general de un refrigerador.
class Refrigerador {
public:
    // Método para inicializar el refrigerador.
    void inicializar() {
        cout << "Inicializando el refrigerador" << '\n';
    }

    // Método abstracto encender que debe ser implementado por las subclases.
    virtual void encender() = 0;

    // Método para apagar el refrigerador.
    void apagar() {
        cout << "Apagando el refrigerador" << '\n';
    }
};

// Subclase RefrigeradorSamsung que implementa el método encender específico para Samsung.
class RefrigeradorSamsung : public Refrigerador {
public:
    // Implementación del método encender para Samsung.
    void encender() override {
        cout << "Encendiendo el refrigerador Samsung" << '\n';
    }
};

// Subclase RefrigeradorLG que implementa el método encender específico para LG.
class RefrigeradorLG : public Refrigerador {
public:
    // Implementación del método encender para LG.
    void encender() override {
        cout << "Encendiendo el refrigerador LG" << '\n';
    }
};