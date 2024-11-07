#pragma once
#include "vector"
#include "iostream"
#include "Carta.h"
#include "ListaEnlazada.h"
using namespace std;
class Jugador
{
public:
	int contador = 0;
	int contadormano = 0;
	int id;
	string nombre; 
	vector<Carta> mano;
	vector<Carta> jardin;


	vector<Carta> getMano();
	void setMano(vector<Carta> mano);
	vector<Carta> getJardin() {
		return jardin;
	}

	void setJardin(vector<Carta> jardin);
	void mostrarPlantas();
	void mostrarJardin();
	Jugador();
	int contarElementosJardin();
	Jugador(int id, string nombre, vector<Carta> pool);

	Jugador(string nombre);
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

	void agregarAJardin(Carta carta);

	void agregarAMano(Carta carta);

	
};

