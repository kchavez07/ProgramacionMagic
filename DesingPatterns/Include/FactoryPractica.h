#pragma once
#include "Preriquisites.h"

// Clase base Vehiculo
class Vehiculo {
public:
    virtual void descripcion() = 0;
};

// Clases concretas Coche y Bicicleta
class Coche : public Vehiculo {
public:
    void descripcion() override {
        cout << "Soy un coche." << endl;
    }
};

class Bicicleta : public Vehiculo {
public:
    void descripcion() override {
        cout << "Soy una bicicleta." << endl;
    }
};

// Clase base FactoriaVehiculos
class FactoriaVehiculos {
public:
    virtual Vehiculo* crearVehiculo() = 0;
};

// Clases concretas FactoriaCoches y FactoriaBicicletas
class FactoriaCoches : public FactoriaVehiculos {
public:
    Vehiculo* crearVehiculo() override {
        return new Coche();
    }
};

class FactoriaBicicletas : public FactoriaVehiculos {
public:
    Vehiculo* crearVehiculo() override {
        return new Bicicleta();
    }
};
