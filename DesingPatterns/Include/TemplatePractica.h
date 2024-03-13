#pragma once
#include "Preriquisites.h"

// Clase base Refrigerador que define la estructura general de un refrigerador.
class Refrigerador {
public:
    // M�todo para inicializar el refrigerador.
    void inicializar() {
        cout << "Inicializando el refrigerador" << '\n';
    }

    // M�todo abstracto encender que debe ser implementado por las subclases.
    virtual void encender() = 0;

    // M�todo para apagar el refrigerador.
    void apagar() {
        cout << "Apagando el refrigerador" << '\n';
    }
};

// Subclase RefrigeradorSamsung que implementa el m�todo encender espec�fico para Samsung.
class RefrigeradorSamsung : public Refrigerador {
public:
    // Implementaci�n del m�todo encender para Samsung.
    void encender() override {
        cout << "Encendiendo el refrigerador Samsung" << '\n';
    }
};

// Subclase RefrigeradorLG que implementa el m�todo encender espec�fico para LG.
class RefrigeradorLG : public Refrigerador {
public:
    // Implementaci�n del m�todo encender para LG.
    void encender() override {
        cout << "Encendiendo el refrigerador LG" << '\n';
    }
};