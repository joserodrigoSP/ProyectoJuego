#pragma once
#include <iostream>
#include "Carta.h"

// Nodo que contendrá cada carta en la pila
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

    void push(Carta* carta);  // Método para agregar una carta
    Carta* pop();             // Método para quitar una carta
    Carta* peek() const;      // Método para ver la carta en la cima sin quitarla
    bool vacia() const;       // Método para verificar si la pila está vacía
};
