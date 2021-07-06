#pragma once
#include "tanque.h"
//#include "ETSIDI.h"

class tanqueJugador : public tanque
{
	int municion;
	int tipo;
public:
	
	tanqueJugador();
	~tanqueJugador();
	void Dispara();
	void Inicializa(float x,float y);
	void mueveTecla(unsigned char key);
	void setTipoDisparo(int type);

	int getMunicion();
	void aumentarMunicion();
};

