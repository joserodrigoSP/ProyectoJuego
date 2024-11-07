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
    int hongosGrado1;
public:
	//~Carta();
    int proteccionFungi = 0;

	Carta(string tipo, string detalle);

	Carta();

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
		}
	}

	int getProteccionFungi() {
		return proteccionFungi;
	}






    void aplicarHongoGrado1() {
        if (proteccionFungi > 0) {
            reducirProteccion();
            cout << "Un fungicida ha protegido la planta del hongo de grado 1." << endl;
        }
        else {
            hongosGrado1++;
            if (hongosGrado1 >= 2) {
                cout << "La planta ha sido eliminada por hongos de grado 1." << endl;
            }
            else {
                cout << "Un hongo de grado 1 ha sido aplicado a la planta." << endl;
            }
        }
    }

    void aplicarHongoGrado2() {
        if (proteccionFungi >= 2) {
            reducirProteccion();
            reducirProteccion();
            cout << "Dos fungicidas han protegido la planta del hongo de grado 2." << endl;
        }
        else {
            cout << "La planta ha sido eliminada por un hongo de grado 2." << endl;

        }
    }

    void aplicarHongoGradoFatal() {
        cout << "La planta ha sido eliminada por un hongo de grado fatal." << endl;
    }
};

