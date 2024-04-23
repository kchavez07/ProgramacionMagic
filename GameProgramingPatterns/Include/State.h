#pragma once
#include "Prereriquisites.h"

// Clase base EstadoPersonaje
class EstadoPersonaje {
public:
    virtual void atacar() = 0;
    virtual void moverse() = 0; // Método moverse,debe ser virtual puro
};

// Clase EstadoNormal
class EstadoNormal : public EstadoPersonaje {
public:
    void atacar() override {
        cout << "Ataque normal" << endl;
    }
    void moverse() override {
        cout << "Movimiento normal" << endl;
    }
};

// Clase EstadoHerido
class EstadoHerido : public EstadoPersonaje {
public:
    void atacar() override {
        cout << "Ataque con más fuerza" << endl; 
    }
    void moverse() override {
        cout << "Movimiento más lento" << endl;
    }
};

// Clase EstadoEnfurecido
class EstadoEnfurecido : public EstadoPersonaje {
public:
    void atacar() override {
        cout << "Ataque con furia" << endl;
    }
    void moverse() override {
        cout << "Movimiento más rápido" << endl;
    }
};

// Clase Personaje
class Personaje {
public:
    // Constructor: Inicializa con estado normal
    Personaje() : estado(new EstadoNormal()) {}

    // Cambiar el estado del personaje
    void setEstado(EstadoPersonaje* nuevoEstado) {
        estado = nuevoEstado;
    }

    // Acción de ataque delegada al estado actual
    void atacar() {
        estado->atacar();
    }

    // Acción de moverse delegada al estado actual
    void moverse() {
        estado->moverse();
    }

private:
    EstadoPersonaje* estado; // Estado actual del personaje
};