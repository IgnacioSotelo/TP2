/*
 * Columna.h
 *
 *  Created on: 22 jun. 2021
 *      Author: ignacio
 */

#ifndef COLUMNA_H_
#define COLUMNA_H_
#include "Lista.h"

class Columna {
private:
	Lista<int> *celdas;
public:
	Columna();

	~Columna();

	void agregarCelda(int dato);

	void agregarCelda(int dato, int posicion);

	void setCelda(int dato, int posicion);

	int getCelda( int posicion);

	int getTamanio();
};


#endif /* COLUMNA_H_ */
