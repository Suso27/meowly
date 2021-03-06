#include "ListaCajas.h"

ListaCajas::ListaCajas(){
	numero = 0;
	for (int i=0; i < MAX_CAJAS; i++) {
		lista[i] = NULL;
	}
}

ListaCajas::~ListaCajas() {
	for (int i = 0; i < numero; i++) delete lista[i];
}

void ListaCajas::destruirContenido()
{
	for (int i = 0; i < numero; i++)
	{
		delete lista[i];
	}
	numero = 0;
}


void ListaCajas::Inicializa() {
	//La disposición de las cajas.
	lista[0] = new Caja(-1.0f, 1.0f, -0.95f, -1.0);
	lista[1] = new Caja(-1.0f, 1.0f, 1.0f, 0.95f);
	lista[2] = new Caja(0.95f, 1.0f, 1.0f, -1.0f);
	lista[3] = new Caja(-1.0f, -0.95f, 1.0f, -1.0);

	numero = 4;
}

void ListaCajas::Inicializa(int n) {
	switch (n)
	{
	case 1:
		lista[0] = new Caja(-0.48f, 0.4f, -0.4f, -0.4f);
		numero = 1;
		break;
	case 2:
		lista[0] = new Caja(-0.28f, -0.2f, -0.2f, -0.6f);
		lista[1] = new Caja(0.2f, 0.6f, 0.28f, 0.2f);
		numero = 2;
		break;
	case 3:
		lista[0] = new Caja(-0.58f, 0.6f, -0.5f, -1.2f);
		lista[1] = new Caja(0.5f, 1.2f, 0.58f, -0.4f);

		numero = 2;
		break;
	case 4:
		lista[0] = new Caja(-1.8f, 1.2f, -1.75f, -1.2f);//Ponerlo en función de los límites del mapa
		lista[1] = new Caja(-1.8f, 1.2f, 1.8f, 1.15f);
		lista[2] = new Caja(1.75f, 1.2f, 1.8f, -1.2f);
		lista[3] = new Caja(-1.75f, -1.15f, 1.75f, -1.2f);
		numero = 4;
		break;
	}
	//case 4:
//	lista[0] = new Caja(-1.0f, 1.0f, -0.95f, -1.0);
//	lista[1] = new Caja(-1.0f, 1.0f, 1.0f, 0.95f);
//	lista[2] = new Caja(0.95f, 1.0f, 1.0f, -1.0f);
//	lista[3] = new Caja(-1.0f, -0.95f, 1.0f, -1.0);
//	numero = 4;
//	break;
}

Caja* ListaCajas::operator[](int pos) {
	return lista[pos];
}

void ListaCajas::Dibuja(){
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

int ListaCajas::getNumero() {
	return numero;
}