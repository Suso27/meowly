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
	lista[0] = new Caja(-1.0f, 1.0f, -0.95f, -1.0, "imagenes/terrain_atlas2.png");
	lista[1] = new Caja(-1.0f, 1.0f, 1.0f, 0.95f, "imagenes/terrain_atlas2.png");
	lista[2] = new Caja(0.95f, 1.0f, 1.0f, -1.0f, "imagenes/rock.png");
	lista[3] = new Caja(-1.0f, -0.95f, 1.0f, -1.0, "imagenes/sand.png");
	numero = 4;
}

void ListaCajas::Inicializa(int n) {
	switch (n)
	{

	case 0: //el contenedor
		lista[0] = new Caja(-1.8f, 1.2f, -1.75f, -1.2f, "imagenes/terrain_atlas2.png");//Ponerlo en función de los límites del mapa
		lista[1] = new Caja(-1.8f, 1.2f, 1.8f, 1.15f, "imagenes/terrain_atlas2.png");
		lista[2] = new Caja(1.75f, 1.2f, 1.8f, -1.2f, "imagenes/terrain_atlas2.png");
		lista[3] = new Caja(-1.75f, -1.15f, 1.75f, -1.2f, "imagenes/terrain_atlas2.png");
		numero = 4;
		break;
	case 1: //nivel 1
		lista[0] = new Caja(-0.48f, 0.4f, -0.4f, -0.4f, "imagenes/floor.png");
		numero = 1;
		break;
	case 2: //nivel 2
		//lista[0] = new Caja(-1.45f, -0.6f, -1.2f, -0.65f);
		//lista[1] = new Caja(-1.25f, -0.6f, -1.2f, -0.9f);
		lista[0] = new Caja(-0.05f, 0.9f, 0.05f, 0.2f, "imagenes/yellow.png");
		lista[3] = new Caja(-0.05f, -0.2f, 0.05f, -0.9f, "imagenes/yellow.png");
		lista[1] = new Caja(-1.75f, 0.025f, -0.5f, -0.025f, "imagenes/yellow.png");
		lista[2] = new Caja(0.5f, 0.025f, 1.75f, -0.025f, "imagenes/yellow.png");

		numero = 4;
		break;
	case 3:
		lista[0] = new Caja(-0.58f, 0.6f, -0.5f, -1.2f, "imagenes/grass5.png");
		lista[1] = new Caja(0.5f, 1.2f, 0.58f, -0.4f, "imagenes/grass5.png");

		numero = 2;
		break;

	case 4:
		lista[0] = new Caja(-0.5f, 0.45f, 0.5f, 0.4, "imagenes/grass2.png");
		lista[1] = new Caja(-0.5f, -0.4f, 0.5f, -0.45f, "imagenes/grass2.png");

		lista[2] = new Caja(-1.4f, 0.0f, -0.5f, -0.05f, "imagenes/grass2.png");
		lista[3] = new Caja(-1.4f, -0.7f, -0.5f, -0.75f, "imagenes/grass2.png");
		lista[4] = new Caja(-1.4f, 0.75f, -0.5f, 0.7f, "imagenes/grass2.png");

		lista[5] = new Caja(0.5f, 0.0f, 1.4f, -0.05f, "imagenes/grass2.png");
		lista[6] = new Caja(0.5f, -0.7f, 1.4f, -0.75f, "imagenes/grass2.png");
		lista[7] = new Caja(0.5f, 0.75f, 1.4f, 0.7f, "imagenes/grass2.png");

		numero = 8;
		break;
	}
}

Caja* ListaCajas::operator[](int pos) {
	return lista[pos];
}

void ListaCajas::Dibuja() const{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

int ListaCajas::getNumero() const{
	return numero;
}