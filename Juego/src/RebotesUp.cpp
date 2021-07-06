#include "RebotesUp.h"
void RebotesUp::aplicarEfecto(tanqueJugador& j)
{
		j.aumentarnMaxRebotes();

}

RebotesUp::RebotesUp() {
	int LO = -9.9; //serian todos 10, un poco menos para evitar las paredes de la caja
	int HI = 9.9;
	posicion.x = 0.1 * (get_random(LO, HI));
	posicion.y = 0.1 * (get_random(LO, HI));

	color.set(30, 70, 50);

	//sprite
	spriteObjeto = { "imagenes/espejo.png" };
	spriteObjeto.setCenter(0, 0);
	spriteObjeto.setSize(0.1, 0.1);
}