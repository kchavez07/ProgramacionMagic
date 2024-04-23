#pragma once
#include "Prereriquisites.h"

// Clase base Sound
class Sound {
public:
    virtual void reproducir() = 0;
};

// Subclase para m�sica de fondo
class MusicaFondo : public Sound {
public:
    // Implementaci�n de la funci�n virtual pura reproducir para m�sica de fondo
    void reproducir() override {
        cout << "Reproduciendo m�sica de fondo" << endl;
    }
};

// Subclase para efectos de sonido (SFX)
class SFX : public Sound {
public:
    // Implementaci�n de la funci�n virtual pura reproducir para efectos de sonido
    void reproducir() override {
        cout << "Reproduciendo efectos de sonido" << endl;
    }
};