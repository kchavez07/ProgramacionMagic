#pragma once
#pragma once
#include <iostream>

class CuentaBancaria 
{
private:
    double saldo;
    int numeroCuenta;

protected:
    void realizarTransaccionInterna(CuentaBancaria& otraCuenta, double amount) {
        if 
            std::cout << "Transacción interna realizada. Nuevo saldo: " << saldo << std::endl;
        }
        else {
            std::cout << "Fondos insuficientes para la transacción interna." << std::endl;
        }
    }

private:
    void calcularInteres() {
        
        std::cout << "Calculando interés..." << std::endl;
    }

public:
    std::string propietario;

    CuentaBancaria(double initialBalance, int accountNumber, std::string owner)
        : saldo(initialBalance), numeroCuenta(accountNumber), propietario(owner) {}

    double consultarSaldo() const {
        return saldo;
    }

    void realizarTransaccionExterna(double amount) {
        saldo -= amount;
        std::cout << "Transacción externa realizada. Nuevo saldo: " << saldo << std::endl;
    }

    void realizarTransaccion(double amount, CuentaBancaria& otraCuenta) {
        realizarTransaccionInterna(otraCuenta, amount);
    }

    CuentaBancaria() = default;
};

int main() {
    
    CuentaBancaria miCuenta(1000.0, 12345, "Wisin");

    std::cout << "Propietario: " << miCuenta.propietario << std::endl;

    std::cout << "Saldo actual: " << miCuenta.consultarSaldo() << std::endl;

    miCuenta.realizarTransaccionExterna(200.0);

    // Crear otra cuenta
    CuentaBancaria otraCuenta(500.0, 67890, "Yandel");

    miCuenta.realizarTransaccion(300.0, otraCuenta);

    return 0;
}
