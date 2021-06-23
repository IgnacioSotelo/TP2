/*
 * Espacio.h
 *
 *  Created on: 22 jun. 2021
 *      Author: ignacio
 */

#ifndef ESPACIO_H_
#define ESPACIO_H_

#include "Plano.h"

class Espacio {
private:
	Lista<Plano*>* planos;
public:
	Espacio();

	~Espacio();

	void agregarPlano(Plano* plano);

	int getTamanio();

	int getDimensionColumna();

	Plano* getPlano(int posicion);

	int getCelda( int x,  int y, int z);

	void setCelda(int dato, int x, int y, int z);

	void imprimirEspacio();
};


#endif /* ESPACIO_H_ */
