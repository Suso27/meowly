#include "ListaObjetos.h"
#include "Interaccion.h"
ListaObjetos::ListaObjetos() {
	numero = 0;
	for (int i = 0; i < MAX_OBJETOS; i++)
		lista[i] = 0;
}

ListaObjetos::~ListaObjetos()
{
}

bool ListaObjetos::agregar(Objeto* o)
{
	if (numero < MAX_OBJETOS)
		lista[numero++] = o; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaObjetos::Dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaObjetos::destruirContenido()
{
	for (int i = 0; i < numero; i++)
	{
		delete lista[i];
	}
	numero = 0;
}

void ListaObjetos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaObjetos::eliminar(Objeto* o)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == o)
		{
			eliminar(i);
			return;
		}
}

Objeto* ListaObjetos::colision(tanqueJugador& j)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), j))
			return lista[i];
	}
	return 0; //no hay colisión
}
