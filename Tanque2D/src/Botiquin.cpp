#include "Botiquin.h"

void Botiquin::aplicarEfecto(tanqueJugador& j)
{
	if(j.getVidaActual()<j.getVidaMax())
	j.aumentarVida();
	
}
