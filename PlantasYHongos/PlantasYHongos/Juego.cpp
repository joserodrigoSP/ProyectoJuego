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




Juego::~Juego() {
    for (Jugador* jugador : jugadores) {
        delete jugador;
    }
    jugadores.clear();
}


void Juego::repartirCartas() {

    for (int i = 0; i < jugadores.size(); i++) {
        for (int j = 0; j < 5; j++) {
            jugadores[i]->agregarAMano(* pool.peek());
            pool.pop();
        }

    }
}


void Juego::agregarJugador(Jugador* jugador) {
    jugadores.push_back(jugador);
}
void Juego::jugarCarta(Carta carta, int cartaAJugar) {

    if (cartaAJugar < 0 || cartaAJugar >= jugadores[indiceTurno]->getMano().size()) {
        std::cerr << "Error: índice fuera de rango" << std::endl;
        return;
    }


    if (carta.getTipo() != "fungicida" && carta.getTipo() != "hongo" && carta.getTipo() != "truco") {
        jugadores[indiceTurno]->agregarAJardin(&jugadores[indiceTurno]->getMano()[cartaAJugar]);
        cout << "Carta de: ";
        jugadores[indiceTurno]->getMano()[cartaAJugar].mostrarCarta();
       cout<< " Agregada al jardin" << endl;
    }
    else {
        cout << "La carta es fungicida, hongo o truco" << endl;
    }


}



void Juego::iniciarTurnos() {
    {
        Jugador* jugadorActual= jugadores[indiceTurno];

        while (juegosigue)
        {

       
        if (juegosigue) {

            jugadorActual = jugadores[indiceTurno];
            cout << "Turno de: " << jugadorActual->getnombre() << endl;

            jugadores[indiceTurno]->mostrarCartas();
            cout << endl << "Desea pasar turno  1) Si  2) No 3) Salir del programa" << endl;
            int opcionn; cin >> opcionn;

            if (opcionn == 1) {
                cout << "Turno pasado..." << endl;
                siguienteTurno();
            }
            else if (opcionn == 2) {
                cout << "Ingrese la carta que desea jugar " << endl;
                int cartaAJugar;
                cin >> cartaAJugar;

                cartaAJugar = cartaAJugar - 1;

                if (cartaAJugar < 0 || cartaAJugar >= jugadores[indiceTurno]->getMano().size()) {
                    cerr << "Error: índice de carta fuera de rango" << endl;
                }
                else {
                    jugarCarta(jugadores[indiceTurno]->getMano()[cartaAJugar], cartaAJugar);
                    siguienteTurno();
                }
            }
            else if (opcionn == 3) {
                break;
            }

         
        }
        else
        {
            cout << "El jugador ganador es: " << jugadorActual->getnombre() << endl;
            return;
        }
        }
    }
}

void Juego::siguienteTurno() {
    indiceTurno = (indiceTurno + 1) % jugadores.size();
}

Juego::Juego() : indiceTurno(0), juegosigue(true) {
    almacenar = vector<Carta*>();
}


// Getters
vector<Jugador*> Juego::getJugadores() const {
    return jugadores;
}

vector<Carta*> Juego::getAlmacenar() const {
    return almacenar;
}

PilaCartas Juego::getPool() const {
    return pool;
}

int Juego::getIndiceTurno() const {
    return indiceTurno;
}

bool Juego::getJuegoSigue() const {
    return juegosigue;
}

string Juego::getJActual() const {
    return jActual;
}

// Setters
void Juego::setJugadores(const vector<Jugador*>& nuevosJugadores) {
    jugadores = nuevosJugadores;
}

void Juego::setAlmacenar(const vector<Carta*>& nuevasCartas) {
    almacenar = nuevasCartas;
}

void Juego::setPool(const PilaCartas& nuevoPool) {
    pool = nuevoPool;
}

void Juego::setIndiceTurno(int nuevoIndiceTurno) {
    indiceTurno = nuevoIndiceTurno;
}

void Juego::setJuegoSigue(bool nuevoJuegoSigue) {
    juegosigue = nuevoJuegoSigue;
}

void Juego::setJActual(const string& nuevoJActual) {
    jActual = nuevoJActual;
}

