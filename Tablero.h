/*
 * Tablero.h
 *
 *  Created on: 22 jun. 2021
 *      Author: ignacio
 */

#ifndef TABLERO_H_
#define TABLERO_H_

#include "Espacio.h"

class Tablero {
private:
	int numeroDeFilas;
	int numeroDeColumnas;
	int numeroDeProfundidad;

	Espacio *espacio;
public:

	Tablero(int numeroDeFilas, int numeroDeColumnas, int numeroDeProfundidad);

	~Tablero();

	int getNumeroDeFilas();

	int getNumeroDeColumnas();

	int getNumeroDeProfundidad();

	void setCelda(int dato, int x, int y, int z);

	int getCelda(int x, int y, int z);

	void iniciarTablero();

	void mostrarTablero();
};


#endif /* TABLERO_H_ */
