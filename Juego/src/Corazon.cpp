#include "Corazon.h"

void Corazon::aplicarEfecto(tanqueJugador& j)
{
	if (j.getVidaMax()<10)
	j.aumentarVidaMax();
	j.aumentarVida();
	
}

/*Corazon::Corazon():Objeto("imagenes/cora.png") {
	float LO = -9.9f; //serian todos 10, un poco menos para evitar las paredes de la caja
	float HI = 9.9f;
	posicion.x = 0.1f * (get_random(LO, HI));
	posicion.y = 0.1f * (get_random(LO, HI));

	color.set(255, 0, 0);
	this->s = s;

	//sprite
	spriteObjeto.setCenter(0.2, 0.2);
	spriteObjeto.setSize(0.4, 0.4);

}*/

Corazon::Corazon() {
	int LO = -9.9; //serian todos 10, un poco menos para evitar las paredes de la caja
	int HI = 9.9;
	posicion.x = 0.1 * (get_random(LO, HI));
	posicion.y = 0.1 * (get_random(LO, HI));

	color.set(255, 0, 0);
	//sprite
	spriteObjeto = { "imagenes/cora.png" };
	spriteObjeto.setCenter(0, 0);
	spriteObjeto.setSize(0.1, 0.1);

}

