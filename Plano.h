/*
 * Plano.h
 *
 *  Created on: 22 jun. 2021
 *      Author: ignacio
 */

#ifndef PLANO_H_
#define PLANO_H_

#include <iostream>
#include "Lista.h"
#include "Columna.h"

class Plano {
private:
	Lista<Columna*>* columnas;
public:
	Plano();

	~Plano();

	void agregarColumna(Columna *columna);

	int getTamanio();

	int getDimensionColumna();

	Columna *getColumna(int posicion);

	int getCelda( int x,  int y);

	void setCelda( int dato, int x,  int y);

	void imprimirPlano();
};


#endif /* PLANO_H_ */
