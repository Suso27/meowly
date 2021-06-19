#include "ListaProyectiles.h"

ListaProyectiles::ListaProyectiles()
{
	numero = 0;
	municion = 10;
	for (int i = 0; i < MAX_PROYECTILES; i++)
		lista[i] = 0;
}

ListaProyectiles::~ListaProyectiles(){}

bool ListaProyectiles::agregar(Proyectil* d)
{
	if (municion>0)
	{
		lista[numero++] = d;
		municion -= 1;
		return true;
	}
	else
		return false;

	for (int i = 0; i < numero; i++)
	{
		for (int j = 0; j < numero; j++)
		{
			if (i != j) {
				if ((lista[i]) == (lista[j]))
				{
					return false;
				}
			}
		}
	}
}

void ListaProyectiles::destruirContenido()
{
	for (int i = 0; i < numero; i++)
	{
		delete lista[i];
	}
	numero = 0;
}

void ListaProyectiles::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaProyectiles::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaProyectiles::colision()
{
}

void ListaProyectiles::setPos(Vector2D pos)
{
	for (int i = 0; i < numero; i++)
		lista[i]->setPos(pos);
}

void ListaProyectiles::setMunicion(int n) {
	municion = n;
}