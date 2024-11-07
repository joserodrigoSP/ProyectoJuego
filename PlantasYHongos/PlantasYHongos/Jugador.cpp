#include "Jugador.h"
#include "Carta.h"
void Jugador::mostrarCartas() {
	
	int n = mano.size();
	cout <<endl<< "---------------------------------------------" << endl;
	cout << "Cartas de " << nombre << endl;
	cout << "---------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		
		cout << i + 1 << ") "; mano[i].mostrarDatos();
	}	
}

vector<Carta> Jugador::getMano() {
	return mano;
}

void Jugador::setMano(vector<Carta> mano) {

	this->mano = mano;
	
}

void Jugador::mostrarPlantas() {
	for (int i = 0; i < jardin.size(); i++) {
		// Muestra las cartas con nombre "planta" y detalle "azul"
		if (jardin[i].getTipo() == "planta") {
			cout << "Indice " << i << ") " << jardin[i].getTipo() << " " << jardin[i].getDetalle();

			if (jardin[i].getProteccionFungi() > 0)
			{
				cout << " Nivel de fungicida : " << jardin[i].getProteccionFungi() << endl;
			}
			else {
				cout << endl;
			}
		}
	}

}



void Jugador::mostrarJardin() {
	for (int i = 0; i < jardin.size(); i++) {
		// Muestra las cartas con nombre "planta" y detalle "azul"
			cout << "Indice " << i << ") " << jardin[i].getTipo() << " " << jardin[i].getDetalle();
			if (jardin[i].getProteccionFungi() >0)
			{
				cout << " Nivel de fungicida : " << jardin[i].getProteccionFungi() << endl;
			}
			else {
				cout << " Nivel de fungicida : " << jardin[i].getProteccionFungi() << endl;

				cout << endl;
			}
		
	}
}

void Jugador::agregarAJardin(Carta carta) {
	
		jardin.push_back(carta);

}

void Jugador::agregarAMano(Carta carta) {

	//vector<Carta> mano;
	
		mano.push_back(carta);


}

void Jugador::setJardin(vector<Carta> jardin) {
	this->jardin = jardin;
}

Jugador::Jugador(string nombre) {
	this->nombre = nombre;
}
int Jugador::contarElementosJardin() {
	return jardin.size();
}
