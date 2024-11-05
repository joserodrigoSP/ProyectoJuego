#pragma once
#include "Carta.h"
#include "iostream"
using namespace std;
class Hongo :public Carta
{
private:
public:
	Hongo(string grado) : Carta("hongo", grado) {
		this->detalle = grado;
	}
	
	void setGrado(string grado) {
		this->detalle = grado;
	}

	string getGrado() {
		return this->detalle;
	}


};

