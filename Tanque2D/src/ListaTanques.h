#pragma once
#define MAX_TANQUES 10
#include "tanqueEnemigo.h"
class ListaTanques 
{
private:
	tanqueEnemigo* lista[MAX_TANQUES];
	int numero;
public:
	friend class Interaccion;

	ListaTanques();
	virtual ~ListaTanques();
	bool agregar(tanqueEnemigo* t);
	void Dibuja();
	void Mueve(float t, Vector2D posJ);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(tanqueEnemigo* o);
	tanqueEnemigo* operator[](int i);
	int getNumero();
};

