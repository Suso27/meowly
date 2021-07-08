#pragma once
#include"Mundo.h"
#include <string>

class Coordinador
{
protected:
	Mundo mundo;
	enum  Estado { INICIO, JUEGO, FIN, GAMEOVER, PAUSA } estado;

public:
	Coordinador();
	virtual ~Coordinador();

	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	void setRaton(int x, int y);
	void crearObjeto();
	void dibujaCartel(const char*,float l1x,float l1y,float l2x,float l2y);

};