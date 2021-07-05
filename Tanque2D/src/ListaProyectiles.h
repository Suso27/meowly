#pragma once
#define MAX_PROYECTILES 100
#include "Proyectil.h"
#include "ProyectilCañon.h"
#include "ProyectilRicochet.h"

class ListaProyectiles
{
	friend class Interaccion;

	Proyectil* lista[MAX_PROYECTILES];
	int numero;

public:
	ListaProyectiles();
	ListaProyectiles(ListaProyectiles&);
	virtual ~ListaProyectiles();
	bool agregar(Proyectil* d);
	void destruirContenido();
	void setPos(Vector2D);
	void mueve(float t);
	void dibuja();
	void eliminar(int index);
	void eliminar(Proyectil* p);	
	int getNum();
	Proyectil operator[](int i);
};

