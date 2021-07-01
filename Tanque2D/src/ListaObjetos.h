#pragma once
#define MAX_OBJETOS 10
#include "Objeto.h"
#include "tanqueJugador.h"
class ListaObjetos
{
public:
	ListaObjetos();
	virtual ~ListaObjetos();
	bool agregar(Objeto* o);
	void Dibuja();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Objeto* o);
	Objeto* colision(tanqueJugador& t);
	int getNum();
private:
	Objeto* lista[MAX_OBJETOS];
	int numero;
};

