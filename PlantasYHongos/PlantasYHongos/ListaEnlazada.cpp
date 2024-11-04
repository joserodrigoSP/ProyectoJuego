#include "ListaEnlazada.h"

// Constructor de la lista enlazada
ListaEnlazada::ListaEnlazada() : cabeza(nullptr) {}

// Destructor de la lista enlazada para liberar memoria
ListaEnlazada::~ListaEnlazada() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp->carta; // Liberamos la memoria de la carta
        delete temp;         // Liberamos el nodo
    }
}

// Método para agregar una carta al inicio de la lista
void ListaEnlazada::agregar(Carta* carta) {
    Nodo* nuevoNodo = new Nodo(carta);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

// Método para mostrar todas las cartas en la lista
void ListaEnlazada::mostrar()  {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        actual->carta->mostrarCarta();
        actual = actual->siguiente;
    }
}

void ListaEnlazada::mostrarPlantas() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->carta->getTipo() == "planta") {
            actual->carta->mostrarCarta();
        }
        actual = actual->siguiente;
    }
}

// Método para verificar si la lista está vacía
bool ListaEnlazada::vacia()  {
    return cabeza == nullptr;
}

int ListaEnlazada::contarElementos() {
    int contador = 0;
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}