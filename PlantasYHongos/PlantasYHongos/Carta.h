#pragma once
#include "iostream"
using namespace std;
class Carta
{
protected:
	string tipo;
	string detalle;
	int id;
	string descripcion;
public:
	//~Carta();
	int hongosGrado1 = 0;

    int proteccionFungi = 0;

	Carta(string tipo, string detalle);

	Carta();  
	bool operator==(const Carta& other) const;


	void setDescripcion(string descripcion);
	string getDescripcion();
	void mostrarCarta();
	void mostrarDatos();

	string getTipo();
	void setTipo(string tipo);
	string getDetalle();
	void setDetalle(string detalle);

	void aplicarFungicida() {
		proteccionFungi = proteccionFungi+1;
        cout << "Fungicida aplicado a la planta seleccionada." << endl;

	}

	void reducirProteccion() {
		if (proteccionFungi > 0) {
			proteccionFungi--;
			cout << "Proteccion reducida " << endl;
		}
	}

	int getProteccionFungi() {
		return proteccionFungi;
	}




};

