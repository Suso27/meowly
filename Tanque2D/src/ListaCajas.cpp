#include "ListaCajas.h"

ListaCajas::ListaCajas(){
	numero = 0;
	for (int i=0; i < MAX_CAJAS; i++) {
		lista[i] = NULL;
	}
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
	case 2:
		lista[0] = new Caja(-0.28f, -0.2f, -0.2f, -0.6f);
		lista[1] = new Caja(0.2f, 0.6f, 0.28f, 0.2f);
		numero = 2;
		break;
	case 4:
		lista[0] = new Caja(-1.0f, 1.0f, -0.95f, -1.0);
		lista[1] = new Caja(-1.0f, 1.0f, 1.0f, 0.95f);
		lista[2] = new Caja(0.95f, 1.0f, 1.0f, -1.0f);
		lista[3] = new Caja(-1.0f, -0.95f, 1.0f, -1.0);
		numero = 4;
		break;
	}
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