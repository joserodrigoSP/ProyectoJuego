#pragma once
#include <algorithm>  
#include <random>   
#include <vector>
#include <iostream>
#include "Carta.h"
#include "Fungicida.h"
#include "Hongo.h"
#include "Jugador.h"
#include "ListaEnlazada.h"
#include "Planta.h"
#include "Truco.h"
#include "PilaCartas.h"
class Juego
{
public:

	vector<Jugador*> jugadores;
    vector<Carta*> almacenar;

	PilaCartas pool;
    int indiceTurno;
    bool juegosigue;
    string jActual;
        
//public:

    Juego();
    ~Juego();

	void trasplantar(string nombrejugador);
	void intercambio(string nombrejugador);

	
	void almacenarPool();
	void asignarPool();
    void mostrarPool();


    void agregarJugador(Jugador* jugador) {
        jugadores.push_back(jugador);
    }


    void iniciarTurnos() {
        Jugador* jugadorActual = jugadores[indiceTurno];
        if (juegosigue) {
          
               
                cout << "Turno de: "<<jugadorActual->getnombre()<<endl;
                siguienteTurno();
            
        }
        else
        {
            cout << "El jugador ganador es: " << jugadorActual->getnombre() << endl;
        }
    }

    void siguienteTurno() {
        indiceTurno = (indiceTurno + 1) % jugadores.size();
    }

};

