#pragma once
#include "Prereriquisites.h"

// Definición de una estructura simple para representar un evento
struct Event {
    enum Type { KEY_PRESS, MOUSE_CLICK } type;
    int data;

    Event(Type t, int d) : type(t), data(d) {}
};

// Clase EventQueue para gestionar una cola de eventos
class EventQueue {
public:
    // Agrega un evento a la cola de eventos
    void pushEvent(const Event& e) {
        events.push(e);
    }

    // Procesa todos los eventos en la cola
    void processEvents() {
        while (!events.empty()) {
            Event e = events.front();
            events.pop();

            // Procesa el evento actual
            switch (e.type) {
            case Event::KEY_PRESS:
                cout << "Tecla presionada: " << static_cast<char>(e.data) << endl;
                break;
            case Event::MOUSE_CLICK:
                cout << "Click del mouse: " << e.data << endl;
                break;
            }
        }
    }

private:
    queue<Event> events; // Cola para almacenar los eventos
};
