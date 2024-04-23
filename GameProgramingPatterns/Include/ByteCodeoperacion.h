#pragma once
#include "Prereriquisites.h"

// Clase base para operaciones de Bytecode
class BytecodeOperation {
public:
    virtual void execute() = 0;
};

// Implementaci�n de GreetingOperation
class GreetingOperation : public BytecodeOperation {
public:
    void execute() override {
        cout << "Ejecutando operaci�n de saludo." << endl;
    }
};

// Implementaci�n de FarewellOperation
class FarewellOperation : public BytecodeOperation {
public:
    void execute() override {
        cout << "Ejecutando operaci�n de despedida." << endl;
    }
};