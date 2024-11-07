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

	int cont=0;
	for (int i = 0; i < jardin.size(); i++) {
		// Muestra las cartas con nombre "planta" y detalle "azul"
		if (jardin[i].getTipo() == "planta") {
			cout << "Indice " << i << ") " << jardin[i].getTipo() << " " << jardin[i].getDetalle();
			cont = cont + 1;
			if (jardin[i].getProteccionFungi() > 0)
			{
				cout << " Nivel de fungicida : " << jardin[i].getProteccionFungi() << endl;
			}
			else {
				cout << endl;
			}
		}
	}

	if (cont == 0) {
		cout << "No hay plantas en el jardin" << endl;
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
	
	if (jardin.size() < 5) {
		jardin.push_back(carta);
	}
	else {
		cout << "Jardin lleno" << endl;
	}
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
