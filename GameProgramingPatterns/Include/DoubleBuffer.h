#pragma once
#include "Prereriquisites.h"

// Clase DoubleBuffer para simular el uso de un buffer activo y un buffer de respaldo
class DoubleBuffer {
public:
    // Constructor: inicializa los dos buffers y establece activeBuffer en buffer1
    DoubleBuffer() : buffer1(10), buffer2(10), activeBuffer(&buffer1) {}

    // Simula la actualización de datos en el buffer activo
    void updateData() {
        for (int i = 0; i < activeBuffer->size(); i++) {
            // Actualiza los datos en el buffer activo
            (*activeBuffer)[i] = 12;
        }
    }

    // Intercambia los buffers activos y de respaldo
    void swapBuffers() {
        activeBuffer = (activeBuffer == &buffer1) ? &buffer2 : &buffer1;
    }

    // Imprime los datos en el buffer activo
    void printActive() {
        cout << "Datos en el buffer activo: ";
        for (int val : *activeBuffer) {
            cout << val << " ";
        }
        cout << endl;
    }

private:
    vector<int> buffer1;        // Primer buffer
    vector<int> buffer2;        // Segundo buffer
    vector<int>* activeBuffer;   // Puntero al buffer activo
};
