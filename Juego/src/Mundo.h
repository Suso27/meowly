#pragma once
#include <random>
#include "tanqueJugador.h"
#include "tanqueEnemigoA.h"
#include "tanqueEnemigoB.h"
#include "ListaCajas.h"
#include "ListaObjetos.h"
#include "ListaTanques.h"
#include "Botiquin.h"
#include "Corazon.h"
#include "DmgUp.h"
#include "BulletSpeedUp.h"
#include "Interaccion.h"

#define ALTO 750.0F
#define ANCHO 1300.0F
#define ESCALA 300.0F
#define N_TIPOS_OBJETO 4 //para la generacion aleatoria

class Mundo
{
private:
	int nivel = 0;

	Vector2D raton;
	tanqueJugador tankJ;
	tanqueEnemigoA tankEA;
	tanqueEnemigoB tankEB;
	Caja caja;
	ListaCajas contenedor;
	ListaCajas cajas;
	ListaObjetos objetos;
	ListaTanques tanques;

public: 
	Mundo();
	~Mundo();
	void tecla(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char);
	void setRaton(int x, int y);
	Vector2D getRaton();
	void crearObjeto();
	void reset();

	bool cargarNivel();
	bool getVida();
	int getNumTanques();
};
