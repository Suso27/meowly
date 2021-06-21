#pragma once
#define MAX_OBJETOS 10
#include "Objeto.h"
class ListaObjetos
{
private:
	Objeto* lista[MAX_OBJETOS];
	int numero;
};

