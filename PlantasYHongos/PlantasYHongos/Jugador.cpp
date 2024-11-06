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
void Jugador::mostrarJardin() {
	jardin.mostrar();
}
void Jugador::agregarAJardin(Carta* carta) {
	if (contador < 5) {
		jardin.agregar(carta);

	}
	else {
		return;
	}

	contador++;
}

void Jugador::agregarAMano(Carta carta) {

	//vector<Carta> mano;
	
		mano.push_back(carta);


}

void Jugador::setJardin(ListaEnlazada jardin) {
	this->jardin = jardin;
}

Jugador::Jugador(string nombre) {
	this->nombre = nombre;
}