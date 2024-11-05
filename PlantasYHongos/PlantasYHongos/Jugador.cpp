#include "Jugador.h"
#include "Carta.h"
void Jugador::mostrarCartas() {

	int n = mano.size();

	for (int i = 0; i < n; i++) {
		cout << i + 1 << ") "; mano[i].mostrarCarta();
	}	
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
	if (contadormano < 4) {
		mano.push_back(carta);

	}
	else {
		return;
	}

	contadormano++;
}

void Jugador::setJardin(ListaEnlazada jardin) {
	this->jardin = jardin;
}