#include "ListaEnlazada.h"

// Constructor de la lista enlazada
ListaEnlazada::ListaEnlazada() : cabeza(nullptr) {}

// Destructor de la lista enlazada para liberar memoria
ListaEnlazada::~ListaEnlazada() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        if (temp->carta != nullptr) { // Verificaci�n adicional
            delete temp->carta; // Liberamos la memoria de la carta
        }
        delete temp; // Liberamos el nodo
    }
}

// M�todo para agregar una carta al inicio de la lista
void ListaEnlazada::agregar(Carta* carta) {
    Nodo* nuevoNodo = new Nodo(carta);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

// M�todo para mostrar todas las cartas en la lista
void ListaEnlazada::mostrar() {
    Nodo* actual = cabeza;
    int cont = 0;
    while (actual != nullptr) {
        cout << cont << ") ";
        try {
            actual->carta->mostrarCarta(); // Llama al m�todo mostrarCarta de cada carta
        }
        catch (const std::exception& e) {
            cout << "Error mostrando carta: " << e.what() << endl;
        }
        actual = actual->siguiente;
        cont++; // Incrementa el contador en cada iteraci�n
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
            cout << contador << ". " << actual->carta->getTipo() + " " + actual->carta->getDetalle() << endl;
            contador++;
        }
        actual = actual->siguiente;
    }
    if (contador == 1) {
        cout << "No hay cartas de tipo planta" << endl;
    }
}

// M�todo para verificar si la lista est� vac�a
bool ListaEnlazada::vacia() {
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

void ListaEnlazada::recorrerHasta(int indiceObjetivo) {
    if (indiceObjetivo < 0) {
        cout << "�ndice inv�lido. No se puede aplicar fungicida." << endl;
        return;
    }

    Nodo* actual = cabeza;
    int contador = 0;

    while (actual != nullptr && contador < indiceObjetivo) {
        actual = actual->siguiente;
        contador++;
    }

    if (actual != nullptr) {
        actual->carta->aplicarFungicida();
    }
    else {
        cout << "�ndice fuera de rango. No se puede aplicar fungicida." << std::endl;
    }
}
