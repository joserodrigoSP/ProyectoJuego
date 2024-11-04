#pragma once
#include <iostream>
#include "Carta.h"
using namespace std;


// Nodo de la lista
struct Nodo {
    Carta* carta;
    Nodo* siguiente;

    Nodo(Carta* carta) : carta(carta), siguiente(nullptr) {}
};

// Clase ListaEnlazada para manejar nodos de cartas
class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada();
    ~ListaEnlazada();

    void agregar(Carta* carta);
    void mostrar() ;
    bool vacia() ;
    int contarElementos();
    void mostrarPlantas();
};