#include "ListaProyectiles.h"
#include "Interaccion.h"
ListaProyectiles::ListaProyectiles()
{

	numero = 0;
	for (int i = 0; i < MAX_PROYECTILES; i++)
		lista[i] = 0;
}

ListaProyectiles::~ListaProyectiles(){
	for (int i = 0; i < numero; i++)
	{
		delete lista[i];
	}
}

bool ListaProyectiles::agregar(Proyectil* d)
{
	lista[numero++] = d;
	return true;
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



void ListaProyectiles::setPos(Vector2D pos)
{
	for (int i = 0; i < numero; i++)
		lista[i]->setPos(pos);
}


void ListaProyectiles::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaProyectiles::eliminar(Proyectil* p)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == p)
		{
			eliminar(i);
			return;
		}
}



int ListaProyectiles::getNum() {
	return numero;
}

Proyectil* ListaProyectiles::getElem(int n) {
	return lista[n];
}
