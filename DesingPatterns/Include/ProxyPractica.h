#pragma once
#include "Preriquisites.h"

// Interfaz base para las imágenes
class Imagen {
public:
    // Método virtual puro para mostrar la imagen.
    virtual void mostrar() = 0;
};

// Proxy para la imagen
class ProxyImagen : public Imagen {
private:
    Imagen* imagenReal; // Puntero a la imagen real

    // Método para crear la imagen real si aún no existe
    void crearImagenReal() {
        if (!imagenReal) {
            imagenReal = new ImagenReal();
        }
    }

public:
    // Constructor del proxy
    ProxyImagen() : imagenReal(nullptr) {}

    // Implementación del método para mostrar la imagen
    void mostrar() override {
        crearImagenReal(); // Asegurarse de que la imagen real exista
        imagenReal->mostrar(); // Mostrar la imagen real
    }
};

// Implementación concreta de la imagen real
class ImagenReal : public Imagen {
public:
    // Implementación del método para mostrar la imagen
    void mostrar() override {
        cout << "Mostrando la imagen." << endl;
    }
};
