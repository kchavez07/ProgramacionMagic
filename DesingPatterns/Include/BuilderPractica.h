#pragma once
#include "Preriquisites.h"

// Clase Pizza
class Pizza {
public:
    string masa;
    string salsa;
    string queso;
    string ingredientes;

    // Método para mostrar los detalles de la pizza
    void mostrarPizza() {
        cout << "Masa: " << masa << endl;
        cout << "Salsa: " << salsa << endl;
        cout << "Queso: " << queso << endl;
        cout << "Ingredientes: " << ingredientes << endl;
    }
};

// Clase abstracta ConstructorPizza
class ConstructorPizza {
protected:
    Pizza pizza;

public:
    virtual void construirMasa() = 0;
    virtual void construirSalsa() = 0;
    virtual void construirQueso() = 0;
    virtual void construirIngredientes() = 0;

    // Método para obtener la pizza construida
    Pizza obtenerPizza() {
        return pizza;
    }
};

// Clases concretas de ConstructorPizza
class ConstructorPizzaHawaiana : public ConstructorPizza {
public:
    void construirMasa() override {
        pizza.masa = "Fina";
    }

    void construirSalsa() override {
        pizza.salsa = "Tomate";
    }

    void construirQueso() override {
        pizza.queso = "Mozzarella";
    }

    void construirIngredientes() override {
        pizza.ingredientes = "Piña, Jamón";
    }
};

class ConstructorPizzaVegetariana : public ConstructorPizza {
public:
    void construirMasa() override {
        pizza.masa = "Integral";
    }

    void construirSalsa() override {
        pizza.salsa = "Pesto";
    }

    void construirQueso() override {
        pizza.queso = "Queso Vegetariano";
    }

    void construirIngredientes() override {
        pizza.ingredientes = "Tomate, Champiñones, Pimientos";
    }
};

