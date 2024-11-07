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
        almacenar.push_back(new Fungicida("roja"));
        almacenar.push_back(new Fungicida("amarilla"));
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


}


void Juego::intercambio(string nombrejugador) {
   
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
        for (int j = 0; j < 4; j++) {
            jugadores[i]->agregarAMano(* pool.peek());
            pool.pop();
            cout << i << endl;
        }

    }
}


void Juego::agregarJugador(Jugador* jugador) {
    jugadores.push_back(jugador);
}







void Juego::jugarCarta(Carta carta, int cartaAJugar) {
    if (cartaAJugar < 0 || cartaAJugar >= jugadores[indiceTurno]->getMano().size()) {
        cout << "Error: índice fuera de rango" << std::endl;
        return;
    }


    if (carta.getTipo() == "planta") {
        jugarPlanta(carta, cartaAJugar);
    }
    else if (carta.getTipo() == "fungicida") {
        jugarFungicida(carta, cartaAJugar);
    }
    else if (carta.getTipo() == "hongo") {
        jugarHongo(carta, cartaAJugar);
    }
    else if (carta.getTipo() == "truco") {
        jugarTruco(carta, cartaAJugar);
    }

    cout << "------------------------------------------------" << endl;
    cout << "Jardin: " << endl;
    jugadores[indiceTurno]->mostrarJardin();
    cout << "------------------------------------------------" << endl;
}

void Juego::jugarPlanta(Carta carta, int cartaAJugar) {
    Jugador* jugadorActual = jugadores[indiceTurno];
    if (jugadorActual->contarElementosJardin() < 5) {
        jugadorActual->agregarAJardin(carta);
        cout << "Carta de planta agregada al jardín." << endl;
        vector<Carta> borrar = jugadores[indiceTurno]->getMano();

        borrar.erase(borrar.begin() + cartaAJugar);

        jugadores[indiceTurno]->setMano(borrar);

        jugadorActual->agregarAMano(*pool.peek());
        pool.pop();
    }
    else {
        cout << "No se pueden agregar más de 5 cartas al jardín." << endl;
    }
}


void Juego::jugarFungicida(Carta carta, int cartaAJugar) {
    Jugador* jugadorActual = jugadores[indiceTurno];
    if (jugadorActual->jardin.empty()) {
        cout << "Jardín vacío. No se puede aplicar fungicida." << endl;
        return;
    }

    cout << "Seleccione la planta a la que desea aplicar el fungicida:" << endl;
    jugadorActual->mostrarPlantas();

    int indicePlanta;
    cin >> indicePlanta;
    bool condicion = carta.getDetalle() == jugadorActual->jardin[indicePlanta].getDetalle();

    if (condicion == 1) {
        // Aplicar el fungicida a la planta seleccionada
        jugadorActual->jardin[indicePlanta].aplicarFungicida();

        // Eliminar la carta de fungicida de la mano del jugador
        vector<Carta> borrar = jugadores[indiceTurno]->getMano();

        borrar.erase(borrar.begin() + cartaAJugar);

        jugadores[indiceTurno]->setMano(borrar);
        jugadorActual->agregarAMano(*pool.peek());
        pool.pop();

    }
    else {

        cout << "No se puede aplicar fungicida a una planta que no es de su color..." << endl;

    }
  


    
}

void Juego::jugarHongo(Carta carta, int cartaAJugar) {
    /*
    cout << "Seleccione el jugador al que desea infectar:" << endl;
    for (int i = 0; i < jugadores.size(); i++) {
        if (i != indiceTurno) {
            cout << i + 1 << ") " << jugadores[i]->getnombre() << endl;
        }
    }
    int indiceJugador;
    cin >> indiceJugador;
    indiceJugador--;

    if (indiceJugador < 0 || indiceJugador >= jugadores.size() || indiceJugador == indiceTurno) {
        cerr << "Error: índice de jugador fuera de rango." << endl;
        return;
    }

    if (jugadores[indiceJugador]->getJardin().vacia()) {
        cout << "El jardín del jugador seleccionado está vacío. No se puede aplicar hongo." << endl;
        return;
    }

    cout << "Seleccione la planta a la que desea aplicar el hongo:" << endl;
    vector<Carta*> plantas;
    jugadores[indiceJugador]->getJardin().mostrarPlantas(plantas);

    int indicePlanta;
    cin >> indicePlanta;
    indicePlanta--;

    if (indicePlanta < 0 || indicePlanta >= plantas.size()) {
        cerr << "Error: índice de planta fuera de rango." << endl;
        return;
    }

    // Aplicar el hongo a la planta seleccionada
    if (carta->getDetalle() == "grado 1") {
        plantas[indicePlanta]->aplicarHongoGrado1();
    }
    else if (carta->getDetalle() == "grado 2") {
        plantas[indicePlanta]->aplicarHongoGrado2();
    }
    else if (carta->getDetalle() == "grado fatal") {
        plantas[indicePlanta]->aplicarHongoGradoFatal();
    }

    vector<Carta> borrar = jugadores[indiceTurno]->getMano();

    borrar.erase(borrar.begin() + cartaAJugar);

    jugadores[indiceTurno]->setMano(borrar);
    jugadores[indiceTurno]->agregarAMano(*pool.peek());
    pool.pop();
    */
}



void Juego::jugarTruco(Carta carta, int cartaAJugar) {
    if (carta.getDetalle() == "trasplantar") {
        cout << "Seleccione el jugador del que desea trasplantar una planta:" << endl;
        for (int i = 0; i < jugadores.size(); i++) {
            if (i != indiceTurno) {
                cout << i + 1 << ") " << jugadores[i]->getnombre() << endl;
            }
        }
        int indiceJugador;
        cin >> indiceJugador;
        indiceJugador--;

        trasplantar(jugadores[indiceJugador]->getnombre());
    }
    else if (carta.getDetalle() == "intercambio") {
        cout << "Seleccione el jugador con el que desea intercambiar el jardín:" << endl;
        for (int i = 0; i < jugadores.size(); i++) {
            if (i != indiceTurno) {
                cout << i + 1 << ") " << jugadores[i]->getnombre() << endl;
            }
        }
        int indiceJugador;
        cin >> indiceJugador;
        indiceJugador--;

        intercambio(jugadores[indiceJugador]->getnombre());
    }

    vector<Carta> borrar = jugadores[indiceTurno]->getMano();

    borrar.erase(borrar.begin() + cartaAJugar);          
    jugadores[indiceTurno]->setMano(borrar);
    jugadores[indiceTurno]->agregarAMano(*pool.peek());
    pool.pop();
}


void Juego::iniciarTurnos() {
    Jugador* jugadorActual = jugadores[indiceTurno];

    while (juegosigue) {
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
        else {
            cout << "El jugador ganador es: " << jugadorActual->getnombre() << endl;
            return;
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

