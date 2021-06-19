#pragma once
#include "ColorRGB.h"
#include "tanque.h"

class tanqueJugador : public tanque
{
protected:


public:
	tanqueJugador();
	void Inicializa();
	void mueveTecla(unsigned char key);
};

