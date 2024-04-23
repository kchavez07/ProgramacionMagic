#pragma once
#include "Prereriquisites.h"
#include "Comand.h"
#include "CommandPractica.h"
#include "FlyWeight.h"
#include "Observer.h"
#include "ObserverPractica.h"
#include "State.h"
#include "StatePractica.h"
#include "DoubleBuffer.h"
#include "DoubleBufferPractica.h"
#include "ByteCode.h"
#include "ByteCodeoperacion.h"
#include "SubClass_Sandbox.h"
#include "Componente.h"
#include "EventQueue.h"

// Función principal del patrón Command
int main() {
    // Crear una instancia de la luz
    Luz miLuz;

    // Crear comandos concretos asociados a la luz
    ComandoEncender encender(miLuz);
    ComandoApagarLuz apagar(miLuz);

    // Crear un control remoto
    ControlRemoto control;

    // Ejecutar el comando para encender la luz
    control.presionarBoton(&encender);

    // Ejecutar el comando para apagar la luz
    control.presionarBoton(&apagar);

    // Deshacer la última operación (apagar la luz)
    control.deshacer();

    return 0;
}


//Commnad Practica 
int main() {
    int resultado = 0;

    Suma suma(5);
    Resta resta(3);
    Multiplicacion multiplicacion(4);
    Division division(2);

    Calculadora calculadora;

    calculadora.realizarOperacion(&suma);
    std::cout << "Resultado después de la suma: " << calculadora.getResultado() << std::endl;

    calculadora.realizarOperacion(&resta);
    std::cout << "Resultado después de la resta: " << calculadora.getResultado() << std::endl;

    calculadora.deshacer();
    std::cout << "Resultado después de deshacer la resta: " << calculadora.getResultado() << std::endl;

    calculadora.rehacer();
    std::cout << "Resultado después de rehacer la resta: " << calculadora.getResultado() << std::endl;

    calculadora.realizarOperacion(&multiplicacion);
    std::cout << "Resultado después de la multiplicación: " << calculadora.getResultado() << std::endl;

    calculadora.realizarOperacion(&division);
    std::cout << "Resultado después de la división: " << calculadora.getResultado() << std::endl;

    return 0;
};

// Función principal del patron Flyweight
int main() {
    // Crear una instancia de la fábrica Flyweight
    FlyweightFactory factory{};

    // Obtener instancias compartidas de objetos Flyweight utilizando la fábrica
    Flyweight* a = factory.getFlyWeight('A');
    Flyweight* b = factory.getFlyWeight('B');
    Flyweight* c = factory.getFlyWeight('C');
    Flyweight* d = factory.getFlyWeight('D');

    // Utilizar las instancias Flyweight para realizar operaciones (en este caso, dibujar)
    a->draw(1, 1);
    b->draw(2, 2);
    c->draw(3, 3);
    d->draw(4, 4);

    // Liberar la memoria al finalizar
    delete a;
    delete b;
    delete c;
    delete d;

    return 0;
}

// Función main del patrón Observer
int main() {
    // Crear un sensor de temperatura y dos dispositivos de visualización
    TemperatureSensor sensor;
    DisplayDevice display1;
    DisplayDevice display2;

    // Añadir los dispositivos de visualización como observadores del sensor de temperatura
    sensor.addObserver(&display1);
    sensor.addObserver(&display2);

    // Simular cambios en la temperatura y notificar a los observadores
    sensor.setTemperature(25);
    sensor.setTemperature(18);
    sensor.setTemperature(2);
    sensor.setTemperature(24);

    return 0;
}

//Observer Practica 
int main() {
    MessageApp messageApp;
    SoundNotification soundNotification;
    VibrationNotification vibrationNotification;
    ScreenNotification screenNotification;

    messageApp.addObserver(&soundNotification);
    messageApp.addObserver(&vibrationNotification);
    messageApp.addObserver(&screenNotification);

    // Simular recepción de un nuevo mensaje
    messageApp.receiveMessage("¡Hola! ¿Cómo estás?");

    return 0;
}

// Funcion main del patrón State
int main() {
    // Crear un personaje
    Personaje personaje;

    // Acciones con estado normal
    personaje.atacar();
    personaje.moverse();

    // Cambiar a estado herido
    personaje.setEstado(new EstadoHerido());
    personaje.atacar();
    personaje.moverse();

    // Cambiar a estado enfurecido
    personaje.setEstado(new EstadoEnfurecido());
    personaje.atacar();
    personaje.moverse();

    return 0;
}
//State Practica 
int main() {
    Vehiculo auto1;

    auto1.acelerar();

    auto1.setEstado(new EstadoReducido());
    auto1.acelerar();
    auto1.frenar(); 

    return 0;
}

// Función principal del Patron DoubleBuffer
int main() {
    DoubleBuffer db;

    // Actualiza y muestra los datos en el buffer activo
    db.updateData();
    db.printActive();

    // Actualiza nuevamente y muestra los datos en el buffer activo
    db.updateData();
    db.printActive();

    // Intercambia los buffers activo y de respaldo
    db.swapBuffers();

    return 0;
}

//DoubleBuffer Practica 
int main() {
    Game game;

    // Crear objetos y añadirlos al buffer activo
    game.UpdateGameObjects();
    game.PrintActiveObjects();

    // Intercambiar buffers
    game.SwapBuffers();

    // Actualizar objetos en el nuevo buffer activo
    game.UpdateGameObjects();
    game.PrintActiveObjects();

    return 0;
}

// Función principal del ByteCodeInterpreter
int main() {
    // Crear una instancia de ByteCodeInterpreter
    ByteCodeInterpreter interpreter;

    // Vector de secuencia de ByteCode a interpretar
    vector<ByteCode> bytecodeSequence = { JUMP, ATTACK, JUMP, BLOCK, SPECIAL };

    // Iterar sobre la secuencia y llamar al método interpret de ByteCodeInterpreter
    for (ByteCode code : bytecodeSequence) {
        interpreter.interpret(code);
    }

    return 0;
}


//ByteCode Operacion
int main() {
    // Crear operaciones usando make_unique
    unique_ptr<BytecodeOperation> operation1 = make_unique<GreetingOperation>();
    unique_ptr<BytecodeOperation> operation2 = make_unique<FarewellOperation>();

    cout << "Ejecutando operaciones de Bytecode: " << endl;

    // Ejecutar las operaciones
    operation1->execute();
    operation2->execute();

    return 0;
}

//Funcion Principal del SubClass Sandbox
int main() {
    // Crear instancias de las subclases Sound
    MusicaFondo musica;
    SFX efecto;

    // Reproducir música de fondo y efectos de sonido
    musica.reproducir();
    efecto.reproducir();

    return 0;
}


//Funcion Principal del Patrón Componente
int main() {
    Entity player;

    // Agregar componentes a la entidad
    player.addComponent(new RenderComponent());
    player.addComponent(new PhysicsComponent());
    player.addComponent(new IAComponent());

    // Inicializar, actualizar, renderizar y destruir componentes de la entidad
    player.initComponent();
    player.updateComponent();
    player.renderComponent();
    player.destroyComponent();

    return 0;
}


// Función principal del Patrón EventQueue
int main() {
    EventQueue eventQueue;

    // Agregar varios eventos a la cola de eventos
    eventQueue.pushEvent(Event(Event::KEY_PRESS, 'H'));
    eventQueue.pushEvent(Event(Event::KEY_PRESS, 'F'));
    eventQueue.pushEvent(Event(Event::KEY_PRESS, '6'));
    eventQueue.pushEvent(Event(Event::KEY_PRESS, 'I'));
    eventQueue.pushEvent(Event(Event::MOUSE_CLICK, 1));
    eventQueue.pushEvent(Event(Event::MOUSE_CLICK, 2));

    // Procesar todos los eventos en la cola
    eventQueue.processEvents();

    return 0;
}