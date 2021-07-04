#include "DmgUp.h"

void DmgUp::aplicarEfecto(tanqueJugador& j)
{
	j.aumentarDaño();
}


DmgUp::DmgUp() {
	int LO = -9.9; //serian todos 10, un poco menos para evitar las paredes de la caja
	int HI = 9.9;
	posicion.x = 0.1 * (get_random(LO, HI));
	posicion.y = 0.1 * (get_random(LO, HI));

	color.set(0, 0, 255);

}
