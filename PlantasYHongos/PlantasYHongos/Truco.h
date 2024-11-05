#pragma once
#include "Carta.h"
#include "iostream"
using namespace std;
class Truco :public Carta
{
private:
public:
	Truco(string tipo) : Carta("truco", tipo) {
		this->detalle = tipo;
	}
	void setTruco(string color) {
		this->detalle = color;
	}

	string getTruco() {
		return this->detalle;
	}
};

