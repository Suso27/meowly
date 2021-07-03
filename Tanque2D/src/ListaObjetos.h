#pragma once
#define MAX_OBJETOS 10
#include "Objeto.h"
#include "tanqueJugador.h"
class ListaObjetos
{
public:
	friend class Interaccion;
	ListaObjetos();
	virtual ~ListaObjetos();
	bool agregar(Objeto* o);
	void Dibuja();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Objeto* o);
	//Objeto* colision(tanqueJugador& t); ya no se usa, ahora hay una funcion en interaccion
	int getNumero();
	Objeto* operator[](int pos);
private:
	Objeto* lista[MAX_OBJETOS];
	int numero;
};

