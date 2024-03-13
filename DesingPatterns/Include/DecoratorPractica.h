#pragma once
#include "Preriquisites.h"

// Clase que representa un condimento
class Condimento {
public:
    virtual void decorar() = 0;
};

// Clase principal que representa una cafeter�a
class Cafeteria {
public:
    // M�todo para preparar caf�
    void prepararCafe() {
        cout << "Caf� preparado" << '\n';
    }
};

// Clase que hereda de Condimento para representar la leche como condimento
class Leche : public Condimento {
private:
    Cafeteria* cafeteria;  // Cafeter�a a decorar con leche

public:
    Leche(Cafeteria* _cafeteria) : cafeteria(_cafeteria) {}

    // M�todo para decorar la cafeter�a con leche
    void decorar() override {
        cout << "Leche agregada" << '\n';
    }
};

// Clase que hereda de Condimento para representar el az�car como condimento
class Azucar : public Condimento {
private:
    Cafeteria* cafeteria;  // Cafeter�a a decorar con az�car

public:
    Azucar(Cafeteria* _cafeteria) : cafeteria(_cafeteria) {}

    // M�todo para decorar la cafeter�a con az�car
    void decorar() override {
        cout << "Az�car agregado" << '\n';
    }
};
