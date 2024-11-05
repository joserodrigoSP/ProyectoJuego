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

void ListaEnlazada::mostrarPlantas(vector<Carta*>& aux) {
    int contador = 1;  // Inicializamos en 1 para numerar desde 1
    Nodo* actual = cabeza;
    aux.clear();  // Limpiamos el vector antes de agregar nuevas cartas

    while (actual != nullptr) {
        if (actual->carta->getTipo() == "planta") {
            aux.push_back(actual->carta);  // Agregamos la carta al vector
            // Imprimimos la carta enumerada
            cout << contador << ". " << actual->carta->getTipo() + " "+ actual->carta->getDetalle() << endl;
            contador++;
        }
        actual = actual->siguiente;
    }
    if (contador == 1) {
        cout << "No hay cartas de tipo planta" << endl;
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