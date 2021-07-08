#include "ListaProyectiles.h"

ListaProyectiles::ListaProyectiles()
{

	numero = 0;
	for (int i = 0; i < MAX_PROYECTILES; i++)
		lista[i] = 0;
}

ListaProyectiles::ListaProyectiles(ListaProyectiles& l) {
	numero = l.numero;
	for (int i = 0; i < numero; i++) {
		lista[i] = new Proyectil(l[i]);
	}
}

ListaProyectiles::~ListaProyectiles(){
	/*for (int i = 0; i < numero; i++)
	{
		delete lista[i];
	}*/
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

void ListaProyectiles::dibuja() const
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



int ListaProyectiles::getNum() const{
	return numero;
}

Proyectil ListaProyectiles::operator[](int n) {
	return *lista[n];
}


