#pragma once
#include "Preriquisites.h"

// Clase base Juego que define el esqueleto de un juego.
class Juego {
public:
    // M�todo principal que define el flujo general del juego.
    void jugar() {
        inicializar();
        comenzarJuego();
        terminarJuego();
    }

protected:
    // M�todo inicializar, proporciona una implementaci�n predeterminada.
    virtual void inicializar() {
        cout << "Iniciando Juego." << endl;
    }

    // M�todo puro comenzarJuego, debe ser implementado por las subclases.
    virtual void comenzarJuego() = 0;

    // M�todo terminarJuego, proporciona una implementaci�n predeterminada.
    virtual void terminarJuego() {
        cout << "Terminando el Juego." << endl;
    }
};

// Subclase Ajedrez que implementa el m�todo comenzarJuego espec�ficamente para el ajedrez.
class Ajedrez : public Juego {
protected:
    void comenzarJuego() override {
        cout << "Comenzar Partida de Ajedrez." << endl;
    }
};

// Subclase Monopoly que implementa el m�todo comenzarJuego espec�ficamente para el Monopoly.
class Monopoly : public Juego {
protected:
    void comenzarJuego() override {
        cout << "Comenzar partida Monopoly." << endl;
    }
};