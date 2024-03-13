#pragma once
#include "Preriquisites.h"

// Clase base Juego que define el esqueleto de un juego.
class Juego {
public:
    // Método principal que define el flujo general del juego.
    void jugar() {
        inicializar();
        comenzarJuego();
        terminarJuego();
    }

protected:
    // Método inicializar, proporciona una implementación predeterminada.
    virtual void inicializar() {
        cout << "Iniciando Juego." << endl;
    }

    // Método puro comenzarJuego, debe ser implementado por las subclases.
    virtual void comenzarJuego() = 0;

    // Método terminarJuego, proporciona una implementación predeterminada.
    virtual void terminarJuego() {
        cout << "Terminando el Juego." << endl;
    }
};

// Subclase Ajedrez que implementa el método comenzarJuego específicamente para el ajedrez.
class Ajedrez : public Juego {
protected:
    void comenzarJuego() override {
        cout << "Comenzar Partida de Ajedrez." << endl;
    }
};

// Subclase Monopoly que implementa el método comenzarJuego específicamente para el Monopoly.
class Monopoly : public Juego {
protected:
    void comenzarJuego() override {
        cout << "Comenzar partida Monopoly." << endl;
    }
};