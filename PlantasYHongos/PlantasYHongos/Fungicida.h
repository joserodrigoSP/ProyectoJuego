#pragma once
#include "Carta.h"
class Fungicida : public Carta
{
public:
	Fungicida(string color) : Carta("fungicida", color) {
		this->detalle = color;
		this->tipo = "fungicida";
	}

	void setColor(string color) {
		this->detalle = color;
	}

	string getColor() {
		return this->detalle;
	}

	
};

