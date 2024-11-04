#pragma once
#include "vector"
#include "iostream"
#include "Carta.h"
#include "ListaEnlazada.h"
using namespace std;
class Jugador
{
private: 
	int contador = 0;
	int contadormano = 0;
	int id;
	string nombre; 
	vector<Carta> mano;
	ListaEnlazada jardin;
public:


	ListaEnlazada getJardin() {
		return jardin;
	}

	void setJardin(ListaEnlazada jardin);


	Jugador();

	Jugador(int id, string nombre, vector<Carta> pool);

	void setid(int id) {
		this->id = id;
	}

	int getid() {
		return this->id;
	}
	
	void setnombre(string nombre) {
		this->nombre = nombre;
	}

	string getnombre() {
		return this->nombre;
	}

	void mostrarCartas();

	void agregarAJardin(Carta* carta);

	void agregarAMano(Carta carta);

	
};

