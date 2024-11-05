#pragma once
#include "iostream"
using namespace std;
class Carta
{
protected:
	string tipo;
	string detalle;
	int id;
public:
	//~Carta();

	Carta(string tipo, string detalle);

	Carta();

	void mostrarCarta();

	string getTipo();
	void setTipo(string tipo);
	string getDetalle();
	void setDetalle(string detalle);
};

