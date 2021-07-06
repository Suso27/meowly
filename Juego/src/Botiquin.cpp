#include "Botiquin.h"
void Botiquin::aplicarEfecto(tanqueJugador& j)
{
	if(j.getVidaActual()<j.getVidaMax())
	j.aumentarVida();
	
}

Botiquin::Botiquin() {
	float LO = -9.9f; //serian todos 10, un poco menos para evitar las paredes de la caja
	float HI = 9.9f;
	posicion.x = 0.1f * (get_random(LO, HI));
	posicion.y = 0.1f * (get_random(LO, HI));

	color.set(250, 100, 100);

	//sprite
	spriteObjeto = { "imagenes/botiquin.png" };
	spriteObjeto.setCenter(0, 0);
	spriteObjeto.setSize(0.1, 0.1);
}
