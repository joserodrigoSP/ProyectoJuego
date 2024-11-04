#pragma once
#include <algorithm>  
#include <random>     
#include "iostream"
#include "Carta.h"
#include "vector"
#include "Fungicida.h"
#include "Hongo.h"
#include "Juego.h"
#include "Jugador.h"
#include "ListaEnlazada.h"
#include "Planta.h"
#include "Truco.h"
#include "PilaCartas.h"
class Juego
{
private:

	vector<Jugador*> jugadores;
	vector<Carta*> * almacenar;
	PilaCartas pool;
    int indiceTurno=0;
    bool juegosigue = true;
    string jActual = jugadores[indiceTurno]->getnombre();
public:

	void trasplantar(string nombrejugador);
	void intercambio(string nombrejugador);

	void pasarTurno();
	void almacenarPool();
	void asignarPool();



    void agregarJugador(Jugador* jugador) {
        jugadores.push_back(jugador);
    }

    void iniciarTurnos() {
        if (juegosigue) {
          
                Jugador* jugadorActual = jugadores[indiceTurno];
                cout << "Turno de: "<<jugadorActual->getnombre()<<endl;
                siguienteTurno();
            
        }
        else
        {
            cout << "El jugador ganador es: " << jActual << endl;
        }
    }

    void siguienteTurno() {
        indiceTurno = (indiceTurno + 1) % jugadores.size();
    }

};

