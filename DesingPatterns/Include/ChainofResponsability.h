#pragma once
#include "Preriquisites.h"

// Clase base del manejador (Handler)
class Manejador {
public:
    // Constructor que recibe el siguiente manejador en la cadena
    Manejador(Manejador* siguiente) : m_siguienteManejador(siguiente) {}

    // Método virtual para manejar solicitudes
    virtual void manejarSolicitud(int solicitud) {
        // Si hay un siguiente manejador, pasa la solicitud a él
        if (m_siguienteManejador != nullptr) {
            m_siguienteManejador->manejarSolicitud(solicitud);
        }
    }

private:
    Manejador* m_siguienteManejador;
};

// Manejador Concreto A 
class ManejadorConcretoA : public Manejador {
public:
    // Constructor que recibe el siguiente manejador en la cadena
    ManejadorConcretoA(Manejador* siguiente) : Manejador(siguiente) {}

    // Implementación específica para el Manejador A
    void manejarSolicitud(int solicitud) override {
        // Maneja solicitudes si el valor es menor o igual a 10
        if (solicitud <= 10) {
            cout << "Manejador A ejecuta la solicitud." << endl;
        }
        else {
            // De lo contrario, pasa la solicitud al siguiente manejador
            Manejador::manejarSolicitud(solicitud);
        }
    }
};

// Manejador Concreto B 
class ManejadorConcretoB : public Manejador {
public:
    // Constructor que recibe el siguiente manejador en la cadena
    ManejadorConcretoB(Manejador* siguiente) : Manejador(siguiente) {}

    // Implementación específica para el Manejador B
    void manejarSolicitud(int solicitud) override {
        // Maneja solicitudes en el rango de 11 a 20
        if (solicitud <= 20) {
            cout << "Manejador B ejecuta la solicitud." << endl;
        }
        else {
            // Pasa la solicitud al siguiente manejador si no la maneja
            Manejador::manejarSolicitud(solicitud);
        }
    }
};

// Manejador Concreto C
class ManejadorConcretoC : public Manejador {
public:
    // Constructor que recibe el siguiente manejador en la cadena
    ManejadorConcretoC(Manejador* siguiente) : Manejador(siguiente) {}

    // Implementación específica para el Manejador C
    void manejarSolicitud(int solicitud) override {
        // Maneja la solicitud sin verificar el valor
        cout << "Manejador C ejecuta la solicitud." << endl;
    }
};
