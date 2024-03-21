#pragma once
#include "Preriquisites.h"
#include <thread>
#include <mutex>

class Configuracion {
private:
    // Atributo privado para almacenar la configuración
    int valor;

    // Constructor privado para evitar instancias externas
    Configuracion() : valor(0) {}

public:
    // Método estático para obtener la instancia única
    static Configuracion& getInstance() {
        static Configuracion instance;
        return instance;
    }

    // Métodos para establecer y obtener el valor de configuración
    void setValue(int _valor) {
        valor = _valor;
    }

    int getValue() {
        return valor;
    }
};

// Función que simula la ejecución de un hilo
void funcionHilo(int id) {
    Configuracion& conf = Configuracion::getInstance();
    conf.setValue(id); // Modifica la configuración con el ID del hilo
    cout << "Hilo " << id << " - Valor de configuración: " << conf.getValue() << endl;
}
