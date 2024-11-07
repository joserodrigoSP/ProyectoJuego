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
private:

	vector<Jugador*> jugadores;
    vector<Carta*> almacenar;

	PilaCartas pool;
    int indiceTurno;
    bool juegosigue;
    string jActual;
        
public:

    Juego();
    ~Juego();

	void trasplantar(int actual, int intercambio);
	void intercambio(int actual, int intercambio);

    void cubrirFungicida(Carta carta);
	void almacenarPool();
	void asignarPool();
    void mostrarPool();
    void repartirCartas();

    void agregarJugador(Jugador* jugador);
    void jugarCarta(Carta carta, int cartaAJugar);
    void iniciarTurnos();
    void jugarPlanta(Carta carta, int cartaAJugar);
    void jugarFungicida(Carta carta, int cartaAJugar);
    void jugarHongo(Carta carta, int cartaAJugar);
    void siguienteTurno();
    void jugarTruco(Carta carta, int cartaAJugar);
    //getters
    vector<Jugador*> getJugadores() const;
    vector<Carta*> getAlmacenar() const;
    PilaCartas getPool() const;
    int getIndiceTurno() const;
    bool getJuegoSigue() const;
    string getJActual() const;

    // Setters
    void setJugadores(const vector<Jugador*>& nuevosJugadores);
    void setAlmacenar(const vector<Carta*>& nuevasCartas);
    void setPool(const PilaCartas& nuevoPool);
    void setIndiceTurno(int nuevoIndiceTurno);
    void setJuegoSigue(bool nuevoJuegoSigue);
    void setJActual(const string& nuevoJActual);
};

