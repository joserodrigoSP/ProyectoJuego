#pragma once
#include "Carta.h"
class Planta:public Carta
{
public:
	Planta(string color) :  Carta("planta", color) {
		this->detalle = color;
		this->tipo = "planta";
	}

	void setColor(string color) {
		this->detalle = color;
	}

	string getColor() {
		return this->detalle;
	}
};

