#pragma once
#define MAX_PROYECTILES 100
#include "Proyectil.h"


class ListaProyectiles
{
	friend class Interaccion;

	Proyectil* lista[MAX_PROYECTILES];
	int numero;
	int municion;
	int daño;

public:
	ListaProyectiles();
	virtual ~ListaProyectiles();
	bool agregar(Proyectil* d);
	void destruirContenido();
	void setPos(Vector2D);
	void setMunicion(int);
	void mueve(float t);
	void dibuja();
	void eliminar(int index);
	void eliminar(Proyectil* p);
	void setDaño(int dmg);
	int getNum();
	Proyectil* getElem(int n);
};

