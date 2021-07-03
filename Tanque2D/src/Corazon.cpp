#include "Corazon.h"

void Corazon::aplicarEfecto(tanqueJugador& j)
{
	if (j.getVidaMax()<10)
	j.aumentarVidaMax();
	
}
