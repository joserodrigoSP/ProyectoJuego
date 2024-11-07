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
using namespace std;

int main()
{
	int p1;
	string nombre;
	Juego juego;
	juego.almacenarPool();
	juego.asignarPool();
	juego.mostrarPool();
	do {
	
	cout << "Cuantos jugadores desea agregar? " << endl;
	 cin >> p1;

	 if (!(p1 < 5)) {
		 cout << "NO ES POSIBLE ESCOGER MAS DE 4 JUGADORES, VUELVA A INGRESAR" << endl;
	 }
	} while (!(p1<5));
	vector<Jugador*> jugadores;
	for (int i = 0; i < p1; i++) {
		cout << "Ingrese el nombre del jugador [" << i + 1 << "]" << endl;
		cin >> nombre;
		jugadores.push_back(new Jugador(nombre));
	}
	juego.setJugadores(jugadores);
	juego.repartirCartas();

	for (int i = 0; i < p1; i++) {
		juego.getJugadores()[i]->mostrarCartas();
	}

	juego.iniciarTurnos();
}



