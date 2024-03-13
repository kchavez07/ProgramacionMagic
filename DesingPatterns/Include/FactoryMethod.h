#pragma once
#include "Preriquisites.h"

// Clase base de productos
class FMProducto {
public:
    virtual void operacion() = 0;
};

// Clase base para la fábrica
class FMFabrica {
public:
    virtual FMProducto* crearProducto() = 0;
    virtual FMProducto* crearPapas() = 0;
    virtual FMProducto* crearRefresco() = 0;
};

// Clase concreta del producto
class FMProductoConcreto : public FMProducto {
public:
    void operacion() override {
        cout << "Operación en Producto Concreto" << endl;
    }
};

// Clase concreta de la fábrica
class FMFabricaConcreta : public FMFabrica {
public:
    FMProducto* crearProducto() override {
        return new FMProductoConcreto();
    }

    FMProducto* crearPapas() override {
        return new FMProductoConcreto();
    }

    FMProducto* crearRefresco() override {
        return new FMPepsiBlack();
    }
};

// Clase concreta del producto "Chettos"
class FmChettos : public FMProducto {
public:
    string nombre;
    float peso;
    float precio;

    void registrar(string _nombre, float _peso, float _precio) {
        nombre = _nombre;
        peso = _peso;
        precio = _precio;
    }

    void operacion() override {
        cout << "Nombre: " << nombre << ", Peso: " << peso << "g, Precio: $" << precio << endl;
    }
};

// Clase concreta del producto "PepsiBlack"
class FMPepsiBlack : public FMProducto {
public:
    string nombre;
    float peso;
    float precio;

    void registrar(string _nombre, float _peso, float _precio) {
        nombre = _nombre;
        peso = _peso;
        precio = _precio;
    }

    void operacion() override {
        cout << "Nombre: " << nombre << ", Peso: " << peso << "ml, Precio: $" << precio << endl;
    }
};

// Clase concreta de la fábrica "Pepsico"
class FMPepsico : public FMFabrica {
public:
    FMProducto* crearPapas() override {
        return new FmChettos();
    }

    FMProducto* crearRefresco() override {
        return new FMPepsiBlack();
    }
};
