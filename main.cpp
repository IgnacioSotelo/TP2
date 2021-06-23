#include <iostream>
#include "Juego.h"
using namespace std;

int main() {
//	Con profundidad = 1 es una tabla 2d
	Juego juego(4,4,1);
	int input = -1;

	while(input != 0) {
		cout << "Ingresar columna: ";
		cin >> input;
		cout << endl;

		juego.colocarFicha(1, input, 1);
		juego.mostrarTablero();
	}

	return 0;
}
