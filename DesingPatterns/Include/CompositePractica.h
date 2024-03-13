#pragma once
#include "Preriquisites.h"

// Clase base para los sistemas
class Sistema {
public:
    virtual void mostrarInfo() = 0;
};

// Clase para representar un archivo
class Archivo : public Sistema {
public:
    void mostrarInfo() override {
        cout << "Este es un archivo." << '\n';
    }
};

// Clase para representar una carpeta
class Carpeta : public Sistema {
public:
    void mostrarInfo() override {
        cout << "Este es una carpeta." << '\n';
    }
};

// Clase que representa una carpeta y puede contener otros sistemas
class SistemaCarpeta : public Carpeta {
private:
    vector<Sistema*> sistemas; // Almacena los sistemas contenidos en la carpeta

public:
    // Método para agregar un sistema a la carpeta
    void agregarSistema(Sistema* sistema) {
        sistemas.push_back(sistema);
    }

    // Método para mostrar información sobre la carpeta y sus sistemas contenidos
    void mostrarInfo() override {
        cout << "Esta es una carpeta con " << sistemas.size() << " sistemas." << '\n';
        for (Sistema* sistema : sistemas) {
            sistema->mostrarInfo();
        }
    }
};