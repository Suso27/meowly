#include "ListaCajas.h"

ListaCajas::ListaCajas(){}

void ListaCajas::Inicializa() {
	//La disposición de las cajas.
	lista[0] = new Caja(-1.0f, 1.0f, -0.95f, -1.0);
	lista[1] = new Caja(-1.0f, 1.0f, 1.0f, 0.95f);
	lista[2] = new Caja(0.95f, 1.0f, 1.0f, -1.0f);
	lista[3] = new Caja(-1.0f, -0.95f, 1.0f, -1.0);

	numero = 4;
}

Caja* ListaCajas::operator[](int pos) {
	return lista[pos];
}

void ListaCajas::Dibuja(){
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}