#pragma once
#include "Proyectil.h"
#include "ListaProyectiles.h"
#include "Pared.h"
#include "Caja.h"
#include "tanque.h"
#include "tanqueJugador.h"
#include "tanqueEnemigo.h"
#include "ListaCajas.h"
#include "Objeto.h"

class Interaccion {
public:
	Interaccion();
	//static bool colision(tanque&, Pared&);
	static bool colision(tanque&, Caja&);
	static bool rebote(Proyectil&, Caja&);
	static bool rebote(Proyectil& d,Pared& p);
	static void rebote(ListaProyectiles, Caja&);
	static void rebote(tanque& t, Caja& c);
	//static void rebote(tanque& t, ListaCajas l);
	//static void rebote(ListaCajas);
	//static bool colision(Proyectil p, tanque t);
	static bool colision(Objeto o, tanqueJugador j);
};

