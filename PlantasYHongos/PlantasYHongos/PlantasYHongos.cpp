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
	Juego juego;
	juego.almacenarPool();
	juego.asignarPool();
	juego.mostrarPool();

   cout << "Hello World!\n";
}

