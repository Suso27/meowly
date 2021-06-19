#pragma once
#define MAX_CAJAS 20
#include "Caja.h"
#include "Interaccion.h"


class ListaCajas
{
	Caja* lista[MAX_CAJAS];
	int numero;

public:
	friend class Interaccion;
	ListaCajas();
	~ListaCajas() {}
	void Inicializa();
	void Dibuja();

	Caja* operator[](int pos);

};
