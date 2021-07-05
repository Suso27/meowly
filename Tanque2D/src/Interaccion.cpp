#include "Interaccion.h"
Interaccion::Interaccion() {};

bool Interaccion::colision(tanque& t, Pared& p) {
	Vector2D dir;
	float dif = p.distancia(t.posicion, &dir) - 0.05;
	if (dif <= 0.0f) {
		Vector2D v_inicial = t.velocidad;
		t.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
		t.posicion = t.posicion - dir * dif;
		return true;
	}
	return false;
}

bool Interaccion::colision(Objeto o, tanqueJugador j)
{
	float dist = o.distancia(j.getPos());
	if (dist < 0.07f)
		return true;
	return false;
}

void Interaccion::colision(ListaObjetos& lo, tanqueJugador& j)
{
	for (int i = 0; i < lo.numero; i++)
	{
		if (colision(*(lo.lista[i]), j)) {
			lo[i]->aplicarEfecto(j);
			lo.eliminar(i);

		}
	}
}

bool Interaccion::colision(Proyectil& p, tanque& t){
	if ((t.posicion - p.posicion).modulo() < (p.radio+0.04f)) {
		t.vida--;
		return true;
	}
	else return false;
}

bool Interaccion::colision(ListaProyectiles& l, tanque& t) {
	for (int i = 0; i < l.numero; i++)
	{
		if (colision(*(l.lista[i]), t)) {
			l.eliminar(i);
			return true;
		}
	}
	return false;
}

bool Interaccion::colision(tanqueJugador& tJ, tanqueEnemigo& tE) {

	if ((tJ.posicion - tE.posicion).modulo() < 0.1) {
		tJ.vida = 0;
	}

	colision(tJ.proyectiles, tE.proyectiles);

	colision(tE.proyectiles, tJ);

	return colision(tJ.proyectiles, tE);

}

void Interaccion::colision(tanqueJugador& tJ, ListaTanques& lt) {

	for (int i = 0; i < lt.numero; i++) {
		if (colision(tJ, *lt[i])) {
			if (lt[i]->vida == 0) lt.eliminar(i);
		}
	}

}

void Interaccion::colision(ListaProyectiles& l1, ListaProyectiles& l2) {
	int i = 0;
	int j = 0;
	while(i<l1.numero) {
		while (j<l2.numero){
			if ((l1[i].posicion - l2[j].posicion).modulo() < 0.02) {
				l1.eliminar(i);
				l2.eliminar(j);
				i--;
			}
			else j++;
		}
		i++;
	}
}

bool Interaccion::rebote(Proyectil& d, Pared& p)
{
	Vector2D dir;
	float dif = p.distancia(d.posicion, &dir) - d.radio;
	if (dif <= 0.0f)
	{
		d.rebotes++;

		Vector2D v_inicial = d.velocidad;
		d.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
		d.posicionTmenos = d.posicionTmenos - dir * dif;
		return true;
	}
	else {
		d.posicionTmenos = d.posicion;
		return false;
	}

}

bool Interaccion::rebote(Proyectil& p, Caja& c) {

	if (rebote(p, c.pared_abj)) return true;
	else if (rebote(p, c.pared_arib)) return true;
	else if (rebote(p, c.pared_dcha)) return true;
	else if (rebote(p, c.pared_izq)) return true;
	else return false;
}

void Interaccion::rebote(ListaProyectiles& l, Caja& c) {
	for (int i = 0; i < l.numero; i++)
	{
		if (rebote(*(l.lista[i]), c)) {
			if(l.lista[i]->rebotes> l.lista[i]->nMaxRebotes) {
				l.eliminar(i);
			}
		}
	}
}

bool Interaccion::rebote(tanque& t, Caja& c) {
	rebote(t.proyectiles, c);

	if (colision(t, c.pared_abj)) return true;
	else if (colision(t, c.pared_arib)) return true;
	else if (colision(t, c.pared_dcha)) return true;
	else if (colision(t, c.pared_izq)) return true;
	else return false;
}

void Interaccion::rebote(ListaTanques& lt, ListaCajas& lc) {
	for (int i = 0; i < lt.numero; i++) {
		rebote(*lt[i], lc);
	}
}

void Interaccion::rebote(tanque& t, ListaCajas& l) {
	for (int i = 0; i < l.numero; i++) {
		rebote(t, *l[i]);
	}
}


