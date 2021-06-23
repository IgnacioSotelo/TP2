/*
 * main.cpp
 *
 *  Created on: 22 jun. 2021
 *      Author: ignacio
 */
#include <iostream>
#include "Tablero.h"
using namespace std;

int main() {
	Tablero t(4, 4, 2);

	t.iniciarTablero();
	t.mostrarTablero();

	return 0;
}



