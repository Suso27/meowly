#pragma once
#define MAX_CAJAS 20
#include "Caja.h"

class ListaCajas1
{
	Caja* lista[MAX_CAJAS];
	int numero;

public:
	friend class Interaccion;
	ListaCajas1();
	~ListaCajas1();
	void Inicializa();
	void Inicializa(int n);
	void Dibuja();
	int getNumero();
	void destruirContenido();


	Caja* operator[](int pos);

};

