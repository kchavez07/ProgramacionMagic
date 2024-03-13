#pragma once
#include "Preriquisites.h"

// Interfaz base para las im�genes
class Imagen {
public:
    // M�todo virtual puro para mostrar la imagen.
    virtual void mostrar() = 0;
};

// Proxy para la imagen
class ProxyImagen : public Imagen {
private:
    Imagen* imagenReal; // Puntero a la imagen real

    // M�todo para crear la imagen real si a�n no existe
    void crearImagenReal() {
        if (!imagenReal) {
            imagenReal = new ImagenReal();
        }
    }

public:
    // Constructor del proxy
    ProxyImagen() : imagenReal(nullptr) {}

    // Implementaci�n del m�todo para mostrar la imagen
    void mostrar() override {
        crearImagenReal(); // Asegurarse de que la imagen real exista
        imagenReal->mostrar(); // Mostrar la imagen real
    }
};

// Implementaci�n concreta de la imagen real
class ImagenReal : public Imagen {
public:
    // Implementaci�n del m�todo para mostrar la imagen
    void mostrar() override {
        cout << "Mostrando la imagen." << endl;
    }
};
