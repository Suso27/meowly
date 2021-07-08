#pragma once
#include "ListaProyectiles.h"
#include "ListaCajas.h"
#include "ListaObjetos.h"
#include "ListaTanques.h"

class Interaccion {
public:
	Interaccion();

	static bool colision(tanque&, Pared&);
	static bool colision(Objeto& o, tanqueJugador& j);
	static void colision(ListaObjetos& lo, tanqueJugador& j);
	static bool colision(Proyectil& p, tanque& t);
	static bool colision(ListaProyectiles& l, tanque& t);
	static bool colision(tanqueJugador& tJ, tanqueEnemigo& tE);
	static void colision(tanqueJugador& tJ, ListaTanques& lt);
	static void colision(ListaProyectiles& l1, ListaProyectiles& l2);

	static bool rebote(Proyectil&, Caja&);
	static bool rebote(Proyectil& d, Pared& p);
	static void rebote(ListaProyectiles&, Caja&);
	static bool rebote(tanque& t, Caja& c);
	static void rebote(tanque& t, ListaCajas& l);
	static void rebote(ListaTanques& lt, ListaCajas& lc);

};