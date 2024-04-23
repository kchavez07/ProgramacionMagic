#pragma once
#include "StatePractica.h"

// Clase base EstadoVehiculo
class EstadoVehiculo {
public:
    virtual void acelerar() = 0;
    virtual void frenar() = 0;
};

// Clase EstadoNormal
class EstadoNormal : public EstadoVehiculo {
public:
    void acelerar() override {
        cout << "El veh�culo acelera normalmente." << endl;
    }
    void frenar() override {
        cout << "El veh�culo frena normalmente." << endl;
    }
};

// Clase EstadoReducido
class EstadoReducido : public EstadoVehiculo {
public:
    void acelerar() override {
        cout << "El veh�culo acelera lentamente debido al tr�fico." << endl;
    }
    void frenar() override {
        cout << "El veh�culo frena m�s suavemente en tr�fico." << endl;
    }
};

// Clase Vehiculo
class Vehiculo {
public:
    Vehiculo() : estado(new EstadoNormal()) {} // Estado inicial: Normal

    void setEstado(EstadoVehiculo* nuevoEstado) {
        estado = nuevoEstado;
    }

    void acelerar() {
        estado->acelerar();
    }

    void frenar() {
        estado->frenar();
    }

private:
    EstadoVehiculo* estado; // Estado del veh�culo
};