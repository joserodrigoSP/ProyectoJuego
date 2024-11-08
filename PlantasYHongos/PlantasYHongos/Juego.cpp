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
        std::cerr << "Error: `almacenar` est� vac�o. No hay cartas para mezclar y asignar a `pool`." << std::endl;
        return;
    }

    // Desordenar el vector `almacenar`
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(almacenar.begin(), almacenar.end(), rng);

    // Insertar cada carta en la pila `pool` despu�s de desordenar
    for (Carta* carta : almacenar) {
        pool.push(carta);
    }
}


/*
  --------------------------------------------------------------- HONGOS ---------------------------------------------------------------
 */


void Juego::aplicarHongoGrado1(int infectar, int planta) {
    if (jugadores[infectar]->jardin[planta].proteccionFungi > 0) {
        jugadores[infectar]->jardin[planta].reducirProteccion();
        cout << "Un fungicida ha protegido la planta del hongo de grado 1." << endl;
    }
    else {
        jugadores[infectar]->jardin[planta].hongosGrado1++;

        if (jugadores[infectar]->jardin[planta].hongosGrado1 >= 2) {



            vector<Carta> borrar = jugadores[infectar]->jardin;

            borrar.erase(borrar.begin() + planta);

            jugadores[infectar]->setJardin(borrar);

            cout << "La planta ha sido eliminada por hongos de grado 1." << endl;


        }
        else {
            cout << "Un hongo de grado 1 ha sido aplicado a la planta." << endl;
        }
    }
}

void Juego::aplicarHongoGrado2(int infectar, int planta) {
    if (jugadores[infectar]->jardin[planta].proteccionFungi >= 2) {

        jugadores[infectar]->jardin[planta].reducirProteccion();
        jugadores[infectar]->jardin[planta].reducirProteccion();

        cout << "Dos fungicidas han protegido la planta del hongo de grado 2." << endl;
    }
    else {
        vector<Carta> borrar = jugadores[infectar]->jardin;

        borrar.erase(borrar.begin() + planta);

        jugadores[infectar]->setJardin(borrar);
        cout << "La planta ha sido eliminada por un hongo de grado 2." << endl;

    }
}

void Juego::aplicarHongoGradoFatal(int infectar, int planta) {
    vector<Carta> borrar = jugadores[infectar]->jardin;

    borrar.erase(borrar.begin() + planta);

    jugadores[infectar]->setJardin(borrar);
    cout << "La planta ha sido eliminada por un hongo de grado fatal." << endl;
}

/*
  --------------------------------------------------------------- FIN HONGOS ---------------------------------------------------------------
 */

void Juego::trasplantar(int actual, int intercambio) {
    
    if (jugadores[actual]->contarElementosJardin() < 5) {
        cout << "Transplanta, ingresa la planta que desea: " << endl;
        jugadores[intercambio]->mostrarPlantas();
        int opcion; cin >> opcion;
        Carta carta = jugadores[intercambio]->jardin[opcion];

        vector<Carta> borrar = jugadores[intercambio]->jardin;
        borrar.erase(borrar.begin() + opcion);
        jugadores[intercambio]->setJardin(borrar);

        jugadores[actual]->jardin.push_back(carta);
        cout << "Carta agregada al jardin" << endl;


        cout << "transplante realizado" << endl;
        cout << "*****************************************************************" << endl;
        cout << "Jardin de " << jugadores[actual]->nombre << endl;
        jugadores[actual]->mostrarJardin();

        cout << "*****************************************************************" << endl;
        cout << "Jardin de " << jugadores[intercambio]->nombre << endl;
        jugadores[intercambio]->mostrarJardin();
        cout << "*****************************************************************" << endl;

    }
    else {
        cout << "Jardin lleno" << endl;
    }

}


void Juego::intercambio(int actual, int intercambio) {
    vector<Carta> auxiliar;

   
        auxiliar = jugadores[actual]->jardin;

        jugadores[actual]->setJardin(jugadores[intercambio]->jardin);

        jugadores[intercambio]->setJardin(auxiliar);
    
        cout << "Intercambio realizado" << endl;
        cout << "*****************************************************************" << endl;
        cout << "Jardin de " << jugadores[actual]->nombre << endl;
        jugadores[actual]->mostrarJardin();

        cout << "*****************************************************************" << endl;
        cout << "Jardin de " << jugadores[intercambio]->nombre << endl;
        jugadores[intercambio]->mostrarJardin();
        cout << "*****************************************************************" << endl;

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
        cout << "Error: �ndice fuera de rango" << std::endl;
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
    cout << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Jardin: " << endl;
    jugadores[indiceTurno]->mostrarJardin();
    cout << "------------------------------------------------" << endl;
    cout << endl;

}

void Juego::jugarPlanta(Carta carta, int cartaAJugar) {
    Jugador* jugadorActual = jugadores[indiceTurno];
    if (jugadorActual->contarElementosJardin() < 5) {
        jugadorActual->agregarAJardin(carta);
        cout << "Carta de planta agregada al jard�n." << endl;
        vector<Carta> borrar = jugadores[indiceTurno]->getMano();

        borrar.erase(borrar.begin() + cartaAJugar);

        jugadores[indiceTurno]->setMano(borrar);

        jugadorActual->agregarAMano(*pool.peek());
        pool.pop();
    }
    else {
        cout << "No se pueden agregar m�s de 5 cartas al jard�n." << endl;
    }
}


void Juego::jugarFungicida(Carta carta, int cartaAJugar) {
    Jugador* jugadorActual = jugadores[indiceTurno];
    if (jugadorActual->jardin.empty()) {
        cout << "Jard�n vac�o. No se puede aplicar fungicida." << endl;
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
        cerr << "Error: �ndice de jugador fuera de rango." << endl;
        return;
    }

    if (jugadores[indiceJugador]->contarElementosJardin() == 0) {
        cout << "El jard�n del jugador seleccionado est� vac�o. No se puede aplicar hongo." << endl;
        return;
    }

    cout << "Seleccione la planta a la que desea aplicar el hongo:" << endl;
    jugadores[indiceJugador]->mostrarPlantas();

    int indicePlanta;
    cin >> indicePlanta;


    // Aplicar el hongo a la planta seleccionada
    if (carta.getDetalle() == "grado 1") {
        aplicarHongoGrado1(indiceJugador, indicePlanta);
    }
    else if (carta.getDetalle() == "grado 2") {
        aplicarHongoGrado2(indiceJugador, indicePlanta);
    }
    else if (carta.getDetalle() == "grado fatal") {
        aplicarHongoGradoFatal(indiceJugador, indicePlanta);
    }

    vector<Carta> borrar = jugadores[indiceTurno]->getMano();

    borrar.erase(borrar.begin() + cartaAJugar);

    jugadores[indiceTurno]->setMano(borrar);
    jugadores[indiceTurno]->agregarAMano(*pool.peek());
    pool.pop();
    
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
        trasplantar(indiceTurno, indiceJugador);
    }
    else if (carta.getDetalle() == "intercambio") {
        cout << "Seleccione el jugador con el que desea intercambiar el jard�n:" << endl;
        for (int i = 0; i < jugadores.size(); i++) {
            if (i != indiceTurno) {
                cout << i + 1 << ") " << jugadores[i]->getnombre() << endl;
            }
        }
        int indiceJugador;
        cin >> indiceJugador;
        indiceJugador--;

        intercambio(indiceTurno, indiceJugador);
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
                cout << endl;
                cout << "------------------------------------------------" << endl;
                cout << "Jardin: " << endl;
                jugadores[indiceTurno]->mostrarJardin();
                cout << "------------------------------------------------" << endl;
                cout << endl;

                cout << "Ingrese la carta que desea jugar " << endl;
                int cartaAJugar;
                cin >> cartaAJugar;

                cartaAJugar = cartaAJugar - 1;

                if (cartaAJugar < 0 || cartaAJugar >= jugadores[indiceTurno]->getMano().size()) {
                    cerr << "Error: �ndice de carta fuera de rango" << endl;
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

