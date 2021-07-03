#pragma once
#include"Mundo.h"

class Coordinador
{
protected:
	Mundo mundo;
	enum Estado { INICIO, JUEGO, FIN, GAMEOVER, PAUSA };
	Estado estado;

public:
	Coordinador();
	virtual ~Coordinador();

	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	void setRaton(int x, int y);
	void crearObjeto();
};