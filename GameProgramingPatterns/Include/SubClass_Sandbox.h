#pragma once
#include "Prereriquisites.h"

// Clase base Sound
class Sound {
public:
    virtual void reproducir() = 0;
};

// Subclase para música de fondo
class MusicaFondo : public Sound {
public:
    // Implementación de la función virtual pura reproducir para música de fondo
    void reproducir() override {
        cout << "Reproduciendo música de fondo" << endl;
    }
};

// Subclase para efectos de sonido (SFX)
class SFX : public Sound {
public:
    // Implementación de la función virtual pura reproducir para efectos de sonido
    void reproducir() override {
        cout << "Reproduciendo efectos de sonido" << endl;
    }
};