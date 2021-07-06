#pragma once
#define MAX_CAJAS 20
#include "Caja.h"

class ListaCajas
{
	Caja* lista[MAX_CAJAS];
	int numero;

public:
	friend class Interaccion;
	ListaCajas();
	~ListaCajas();
	void Inicializa();
	void Inicializa(int n);
	void Dibuja() const;
	int getNumero() const;
	void destruirContenido();
	

	Caja* operator[](int pos);

};
