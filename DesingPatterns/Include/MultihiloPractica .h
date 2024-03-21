#pragma once
#include "Preriquisites.h"
#include <thread>
#include <mutex>

class Configuracion {
private:
    // Atributo privado para almacenar la configuraci�n
    int valor;

    // Constructor privado para evitar instancias externas
    Configuracion() : valor(0) {}

public:
    // M�todo est�tico para obtener la instancia �nica
    static Configuracion& getInstance() {
        static Configuracion instance;
        return instance;
    }

    // M�todos para establecer y obtener el valor de configuraci�n
    void setValue(int _valor) {
        valor = _valor;
    }

    int getValue() {
        return valor;
    }
};

// Funci�n que simula la ejecuci�n de un hilo
void funcionHilo(int id) {
    Configuracion& conf = Configuracion::getInstance();
    conf.setValue(id); // Modifica la configuraci�n con el ID del hilo
    cout << "Hilo " << id << " - Valor de configuraci�n: " << conf.getValue() << endl;
}
