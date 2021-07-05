#include "ObjetoCa�on.h"

void ObjetoCa�on::aplicarEfecto(tanqueJugador& j)
{
	j.setTipoDisparo(1);
}

ObjetoCa�on::ObjetoCa�on() {
	int LO = -9.9; //serian todos 10, un poco menos para evitar las paredes de la caja
	int HI = 9.9;
	posicion.x = 0.1 * (get_random(LO, HI));
	posicion.y = 0.1 * (get_random(LO, HI));

	color.set(163, 73, 164);

}