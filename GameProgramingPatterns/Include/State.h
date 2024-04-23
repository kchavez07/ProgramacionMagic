#pragma once
#include "Prereriquisites.h"

// Clase base EstadoPersonaje
class EstadoPersonaje {
public:
    virtual void atacar() = 0;
    virtual void moverse() = 0; // M�todo moverse,debe ser virtual puro
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
        cout << "Ataque con m�s fuerza" << endl; 
    }
    void moverse() override {
        cout << "Movimiento m�s lento" << endl;
    }
};

// Clase EstadoEnfurecido
class EstadoEnfurecido : public EstadoPersonaje {
public:
    void atacar() override {
        cout << "Ataque con furia" << endl;
    }
    void moverse() override {
        cout << "Movimiento m�s r�pido" << endl;
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

    // Acci�n de ataque delegada al estado actual
    void atacar() {
        estado->atacar();
    }

    // Acci�n de moverse delegada al estado actual
    void moverse() {
        estado->moverse();
    }

private:
    EstadoPersonaje* estado; // Estado actual del personaje
};