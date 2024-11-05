#include "Juego.h"
void Juego::almacenarPool() {
    // Llenar el vector con cartas de diferentes tipos



    for (int i = 0; i < 12; i++) {
        if (i < 4) {
            almacenar.push_back(new Planta("azul"));
            
        }
        else if (i < 8) {
            almacenar.push_back(new Planta("amarilla"));
        }
        else {
            almacenar.push_back(new Planta("roja"));
        }
    }
    for (int i = 0; i < 10; i++) {
        almacenar.push_back(new Hongo("grado 1"));
    }
    for (int i = 0; i < 5; i++) {
        almacenar.push_back(new Hongo("grado 2"));
    }
    for (int i = 0; i < 3; i++) {
        almacenar.push_back(new Hongo("grado fatal"));
    }
    for (int i = 0; i < 3; i++) {
        almacenar.push_back(new Fungicida("rojo"));
        almacenar.push_back(new Fungicida("amarillo"));
        almacenar.push_back(new Fungicida("azul"));
    }
    for (int i = 0; i < 6; i++) {
        almacenar.push_back(new Truco("trasplantar"));
    }
    for (int i = 0; i < 3; i++) {
        almacenar.push_back(new Truco("intercambio"));
    }
}

void Juego::asignarPool() {
    // Verifica que `almacenar` tenga elementos antes de mezclar y llenar la pila
    if (almacenar.empty()) {
        std::cerr << "Error: `almacenar` está vacío. No hay cartas para mezclar y asignar a `pool`." << std::endl;
        return;
    }

    // Desordenar el vector `almacenar`
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(almacenar.begin(), almacenar.end(), rng);

    // Insertar cada carta en la pila `pool` después de desordenar
    for (Carta* carta : almacenar) {
        pool.push(carta);
    }
}



void Juego::trasplantar(string nombrejugador) {
    int indice1, indice2, opcion = 0;
 
    for (int i = 0; i < jugadores.size(); i++) {
        if (jugadores[i]->getnombre() == nombrejugador) {
            indice1 = i;
        }
        if (jugadores[i]->getnombre() == jActual) {
            indice2 = i;
        }
    }
    if (jugadores[indice2]->getJardin().contarElementos() < 5) {

        vector<Carta*> aux;
        cout << "Elija la opción: " << endl;
        jugadores[indice1]->getJardin().mostrarPlantas(aux);
        cin >> opcion;
        

        jugadores[indice2]->agregarAJardin(aux[opcion - 1]);
    }
    else {
        cout << "Jardin lleno, no se puede transplantar" << endl;
        return ;
    }
    




}


void Juego::intercambio(string nombrejugador) {
    ListaEnlazada jardinAux;
    int indice1 = 0;
    int indice2 = 0;

    for (int i = 0; i < jugadores.size(); i++) {
        if (jugadores[i]->getnombre() == nombrejugador) {
            indice1 = i;
        }
        if (jugadores[i]->getnombre() == jActual) {
            indice2 = i;
        }
    }

    jardinAux = jugadores[indice2]->getJardin();

    jugadores[indice2]->setJardin(jugadores[indice1]->getJardin());

    jugadores[indice1]->setJardin(jardinAux);
}

void Juego::mostrarPool() {
    cout << "--------------------------------------------------------------" << endl;
    pool.mostrarPila();
    cout << "--------------------------------------------------------------" << endl;

}


Juego::Juego() : indiceTurno(0), juegosigue(true) {
    almacenar = vector<Carta*>();
}

Juego::~Juego() {
   
}