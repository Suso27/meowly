#pragma once
#include "tanque.h"

class tanqueJugador : public tanque
{
	int municion;

public:
	tanqueJugador();
	~tanqueJugador();
	void Dispara();
	void Inicializa(float x,float y);
	void mueveTecla(unsigned char key);
	void Reset();
};

