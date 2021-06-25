#include "ListaProyectiles.h"
#include "Interaccion.h"
ListaProyectiles::ListaProyectiles()
{
	daño = 1;
	numero = 0;
	municion = 10;
	for (int i = 0; i < MAX_PROYECTILES; i++)
		lista[i] = 0;
}

ListaProyectiles::~ListaProyectiles(){
	//for (int i = 0; i < numero; i++)
	//{
	//	delete lista[i];
	//}
	//numero = 0;
}

bool ListaProyectiles::agregar(Proyectil* d)
{
	if (municion>0)
	{
		lista[numero++] = d;
		lista[numero-1]->setDaño(daño);
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

/*void ListaProyectiles::colision()
{
}*/

void ListaProyectiles::setPos(Vector2D pos)
{
	for (int i = 0; i < numero; i++)
		lista[i]->setPos(pos);
}

void ListaProyectiles::setMunicion(int n) {
	municion = n;
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

void ListaProyectiles::setDaño(int dmg)
{
	daño = dmg;
}

//Proyectil* ListaProyectiles::colision(tanque &t)

int ListaProyectiles::getNum() {
	return numero;
}

Proyectil* ListaProyectiles::getElem(int n) {
	return lista[n];
}

/*Proyectil* ListaProyectiles::colision(tanque &t) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::colision(*(lista[i]), t)) {
			return lista[i];
		}
	}
	return 0;
}*/