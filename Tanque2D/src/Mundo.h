#pragma once
#include <vector>
#include "tanque.h"
#include "Vector2D.h"
#include "tanqueJugador.h"
#include "tanqueEnemigo.h"
#include "tanqueEnemigoA.h"
#include "tanqueEnemigoB.h"
#include "Pared.h"
#include "Caja.h"
#include "ListaCajas.h"
#include "ListaObjetos.h"
#include "ListaTanques.h"
#define ALTO 750.0F
#define ANCHO 1300.0F
#define ESCALA 300.0F

class Mundo
{
private:
	bool impacto;
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
	void crearObjeto();

	bool cargarNivel();
	bool getImpacto();
	int getNumTanques();
};
