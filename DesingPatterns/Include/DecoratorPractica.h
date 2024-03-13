#pragma once
#include "Preriquisites.h"

// Clase que representa un condimento
class Condimento {
public:
    virtual void decorar() = 0;
};

// Clase principal que representa una cafetería
class Cafeteria {
public:
    // Método para preparar café
    void prepararCafe() {
        cout << "Café preparado" << '\n';
    }
};

// Clase que hereda de Condimento para representar la leche como condimento
class Leche : public Condimento {
private:
    Cafeteria* cafeteria;  // Cafetería a decorar con leche

public:
    Leche(Cafeteria* _cafeteria) : cafeteria(_cafeteria) {}

    // Método para decorar la cafetería con leche
    void decorar() override {
        cout << "Leche agregada" << '\n';
    }
};

// Clase que hereda de Condimento para representar el azúcar como condimento
class Azucar : public Condimento {
private:
    Cafeteria* cafeteria;  // Cafetería a decorar con azúcar

public:
    Azucar(Cafeteria* _cafeteria) : cafeteria(_cafeteria) {}

    // Método para decorar la cafetería con azúcar
    void decorar() override {
        cout << "Azúcar agregado" << '\n';
    }
};
