#include "ListaTanques.h"

ListaTanques::ListaTanques() {
	numero = 0;
	for (int i = 0; i < MAX_TANQUES; i++)
		lista[i] = NULL;
}

ListaTanques::~ListaTanques()
{
}

tanqueEnemigo* ListaTanques::operator[](int i) {
	return lista[i];
}

bool ListaTanques::agregar(tanqueEnemigo* t)
{
	if (numero < MAX_TANQUES)
		lista[numero++] = t; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaTanques::Dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

void ListaTanques::Mueve(float t, Vector2D posJ) {
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t,posJ);
}

void ListaTanques::destruirContenido()
{
	for (int i = 0; i < numero; i++)
	{
		delete lista[i];
	}
	numero = 0;
}

void ListaTanques::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaTanques::eliminar(tanqueEnemigo* o)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == o)
		{
			eliminar(i);
			return;
		}
}

int ListaTanques::getNumero() {
	return numero;
}