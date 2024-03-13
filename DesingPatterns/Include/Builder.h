#pragma once
#include "Preriquisites.h"

// Clase que representa un producto complejo
class BProducto {
public:
    void agregarParte(const string& _parte) {
        partes.push_back(_parte);
    }
    void mostrar() {
        cout << "Partes del producto: ";
        for (const string& parte : partes) {
            cout << parte << " ";
        }
        cout << endl;
    }

private:
    vector<string> partes;
};

// Clase abstracta del constructor (Builder)
class Builder {
public:
    virtual void construirParteA() = 0;
    virtual void construirParteB() = 0;
    virtual BProducto* obtenerProducto() = 0;
};

// Clase concreta del constructor (Builder Concreto)
class BuilderConcreto : public Builder {
public:
    BuilderConcreto() {
        producto = new BProducto();
    }

    void construirParteA() override {
        producto->agregarParte("Parte A");
    }

    void construirParteB() override {
        producto->agregarParte("Parte B");
    }

    BProducto* obtenerProducto() override {
        return producto;
    }

private:
    BProducto* producto;
};

// Clase Director
class Director {
public:
    Director(Builder* _builder) : builder(_builder) {}

    void construir() {
        builder->construirParteA();
        builder->construirParteB();
    }

private:
    Builder* builder;
};
