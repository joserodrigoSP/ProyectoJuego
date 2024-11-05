#include "PilaCartas.h"

// Constructor que inicializa la pila vac�a
PilaCartas::PilaCartas() : cima(nullptr) {}

// Destructor que limpia la pila y libera la memoria
PilaCartas::~PilaCartas() {
    while (!vacia()) {
        delete pop();  // Liberar memoria de cada carta al eliminarla de la pila
    }
}

// M�todo para agregar una carta a la pila
void PilaCartas::push(Carta* carta) {
    NodoCarta* nuevoNodo = new NodoCarta(carta);
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
}

// M�todo para quitar la carta en la cima de la pila
Carta* PilaCartas::pop() {
    if (vacia()) {
        std::cout << "La pila est� vac�a. No se puede quitar ninguna carta." << std::endl;
        return nullptr;
    }

    NodoCarta* nodoAEliminar = cima;
    Carta* carta = nodoAEliminar->carta;
    cima = cima->siguiente;
    delete nodoAEliminar;
    return carta;
}

// M�todo para ver la carta en la cima sin quitarla
Carta* PilaCartas::peek() const {
    if (vacia()) {
        std::cout << "La pila est� vac�a. No hay ninguna carta en la cima." << std::endl;
        return nullptr;
    }
    return cima->carta;
}

// M�todo para verificar si la pila est� vac�a
bool PilaCartas::vacia() const {
    return cima == nullptr;
}

void PilaCartas::mostrarPila() {
    NodoCarta* actual = cima;
    while (actual != nullptr) {
        actual->carta->mostrarCarta(); // Llama al m�todo mostrarCarta de cada carta
        actual = actual->siguiente;
    }
}
