#pragma once
#include "Preriquisites.h"

// Interfaz com�n para objetos dibujables
class Dibujable {
public:
    virtual void dibujar() = 0;
};

// Clase concreta Circulo
class Circulo {
public:
    void dibujarCirculo() {
        cout << "Dibujando c�rculo." << endl;
    }
};

// Clase concreta Cuadrado
class Cuadrado {
public:
    void dibujarCuadrado() {
        cout << "Dibujando cuadrado." << endl;
    }
};

// Adaptador para Circulo
class CirculoAdapter : public Dibujable {
private:
    Circulo* circulo;

public:
    // Constructor que toma un objeto Circulo para adaptar
    CirculoAdapter(Circulo* circulo) : circulo(circulo) {}

    // Implementaci�n del m�todo dibujar de la interfaz Dibujable
    void dibujar() override {
        cout << "Adapter llamado para dibujar un c�rculo." << endl;
        circulo->dibujarCirculo();
    }
};

// Adaptador para Cuadrado
class CuadradoAdapter : public Dibujable {
private:
    Cuadrado* cuadrado;

public:
    // Constructor que toma un objeto Cuadrado para adaptar
    CuadradoAdapter(Cuadrado* cuadrado) : cuadrado(cuadrado) {}

    // Implementaci�n del m�todo dibujar de la interfaz Dibujable
    void dibujar() override {
        cout << "Adapter llamado para dibujar un cuadrado." << endl;
        cuadrado->dibujarCuadrado();
    }
};
