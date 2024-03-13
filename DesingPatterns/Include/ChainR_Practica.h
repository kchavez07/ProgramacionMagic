#pragma once
#include "Preriquisites.h"

// Clase Solicitud que representa una solicitud con un monto.
class Solicitud {
private:
    int monto;

public:
    Solicitud(int m) : monto(m) {}

    // Método para obtener el monto de la solicitud.
    int getMonto() const {
        return monto;
    }
};

// Clase base Manejador que define la interfaz para manejar solicitudes.
class Manejador {
protected:
    Manejador* siguiente;

public:
    Manejador(Manejador* siguiente) : siguiente(siguiente) {}

    virtual void manejar(const Solicitud& solicitud) = 0;
};

// Manejador Director General que maneja solicitudes con montos mayores a 10000.
class ManejadorDirectorGeneral : public Manejador {
public:
    ManejadorDirectorGeneral(Manejador* siguiente) : Manejador(siguiente) {}

    void manejar(const Solicitud& solicitud) override {
        cout << "Manejo por el Director General." << endl;
        if (solicitud.getMonto() > 10000) {
            cout << "Solicitud aprobada por el Director General." << endl;
        }
        else {
            cout << "Solicitud rechazada por el Director General." << endl;
        }
    }
};

// Manejador Gerente que maneja solicitudes con montos menores o iguales a 10000.
class ManejadorGerente : public Manejador {
public:
    ManejadorGerente(Manejador* siguiente) : Manejador(siguiente) {}

    void manejar(const Solicitud& solicitud) override {
        cout << "Manejo por el Gerente." << endl;
        if (solicitud.getMonto() <= 10000) {
            cout << "Solicitud aprobada por el Gerente." << endl;
        }
        else if (siguiente != nullptr) {
            siguiente->manejar(solicitud);
        }
        else {
            cout << "No hay más manejadores, la solicitud fue rechazada." << endl;
        }
    }
};

// Manejador Directivo que maneja solicitudes con montos menores o iguales a 5000.
class ManejadorDirectivo : public Manejador {
public:
    ManejadorDirectivo(Manejador* siguiente) : Manejador(siguiente) {}

    void manejar(const Solicitud& solicitud) override {
        cout << "Manejo por el Directivo." << endl;
        if (solicitud.getMonto() <= 5000) {
            cout << "Solicitud aprobada por el Directivo." << endl;
        }
        else if (siguiente != nullptr) {
            siguiente->manejar(solicitud);
        }
        else {
            cout << "No hay más manejadores, la solicitud fue rechazada." << endl;
        }
    }
};