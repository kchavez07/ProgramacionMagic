#pragma once
#include "Prereriquisites.h"

// Clase base para operaciones de Bytecode
class BytecodeOperation {
public:
    virtual void execute() = 0;
};

// Implementación de GreetingOperation
class GreetingOperation : public BytecodeOperation {
public:
    void execute() override {
        cout << "Ejecutando operación de saludo." << endl;
    }
};

// Implementación de FarewellOperation
class FarewellOperation : public BytecodeOperation {
public:
    void execute() override {
        cout << "Ejecutando operación de despedida." << endl;
    }
};