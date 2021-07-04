#pragma once
#include "ColorRGB.h"
#include "tanque.h"

class tanqueJugador : public tanque
{
protected:


public:
	tanqueJugador();
	~tanqueJugador();
	void Inicializa(float x,float y);
	void mueveTecla(unsigned char key);
};

