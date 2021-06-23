#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <iostream>

class Jugador {
private:
	int id;
	std::string ficha;
	bool cartaBloquearTurno; // = t (t : disponible, f: usada)
	bool cartaJuegaDoble;    // "  "
	bool cartaDobleFicha;
	int fichasRestantes;
	int cartasRestantes;

public:
	static int numero;

	Jugador(std::string ficha);

	int getNumero();

	std::string getFicha();
};


#endif /* JUGADOR_H_ */
