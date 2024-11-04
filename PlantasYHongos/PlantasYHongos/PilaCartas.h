#pragma once
#include <iostream>
#include "Carta.h"

// Nodo que contendr� cada carta en la pila
struct NodoCarta {
    Carta* carta;
    NodoCarta* siguiente;

    NodoCarta(Carta* carta) : carta(carta), siguiente(nullptr) {}
};

// Clase PilaCartas
class PilaCartas {
private:
    NodoCarta* cima;  // Puntero al nodo en la parte superior de la pila

public:
    PilaCartas();     // Constructor
    ~PilaCartas();    // Destructor

    void push(Carta* carta);  // M�todo para agregar una carta
    Carta* pop();             // M�todo para quitar una carta
    Carta* peek() const;      // M�todo para ver la carta en la cima sin quitarla
    bool vacia() const;       // M�todo para verificar si la pila est� vac�a
};
