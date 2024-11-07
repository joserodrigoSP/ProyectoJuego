#include "Carta.h"

Carta::Carta(string tipo, string color) {
	this->tipo = tipo;
	this->detalle = color;
}

void Carta::mostrarCarta() {
		cout <<"o  "+ tipo + " "+ detalle << endl;
}
void Carta::mostrarDatos() {
	cout << tipo + " " + detalle << endl;
}
     
void Carta::setTipo(string tipo) {
	this->tipo = tipo;
}
string Carta::getTipo() {
	return tipo;
}
string Carta::getDetalle() {
	return detalle;
}
string Carta::getDescripcion() {
	return descripcion;
}
void Carta::setDetalle(string detalle){
	this->detalle = detalle;
}

void Carta::setDescripcion(string descripcion){}
