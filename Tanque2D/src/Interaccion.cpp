#include "Interaccion.h"
#include <math.h>
#include <cmath>
Interaccion::Interaccion() {};


bool Interaccion::rebote(Proyectil& d,Pared& p)
{
	Vector2D dir;
	float dif = p.distancia(d.posicion, &dir) - d.radio;
	if (dif <= 0.005f)//Lo suyo sería poner dif <= 0.0f pero se buguea
	{
		Vector2D v_inicial = d.velocidad;
		d.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
		d.posicion = d.posicion - dir * dif;
		return true;
	}
	return false;

}

//bool Interaccion::colision(tanque& t, Pared& p) {
//	Vector2D dir;
//	float dif = p.distancia(t.posicion, &dir) - 0.05;
//	if (dif <= 0.005f)//Lo suyo sería poner dif <= 0.0f pero se buguea
//
//	return false;
//
//}

bool Interaccion::rebote(Proyectil& p, Caja& c) {

	if (rebote(p, c.pared_abj)) return true;
	else if (rebote(p, c.pared_arib)) return true;
	else if (rebote(p, c.pared_dcha)) return true;
	else if (rebote(p, c.pared_izq)) return true;
	else return false;
}

//bool Interaccion::colision(tanque& t, Caja& c) {
//
//	if (colision(t, c.pared_abj)) return true;
//	else if (colision(t, c.pared_arib)) return true;
//	else if (colision(t, c.pared_dcha)) return true;
//	else if (colision(t, c.pared_izq)) return true;
//	else return false;
//}

void Interaccion::rebote(ListaProyectiles l, Caja& c) {
	for (int i = 0; i < l.numero; i++)
	{
		rebote(*(l.lista[i]), c);
	}
}

void Interaccion::rebote(tanque& t, Caja& c) {
	rebote(t.proyectiles, c);
}

bool Interaccion::colision(Objeto o, tanqueJugador j)
{
	float dist = o.distancia(j.getPos());
	if (dist < 0.07f) return true;
	return false;
}

//void Interaccion::rebote(tanque& t, ListaCajas l) {
//	for (int i = 0; i < l.numero; i++) {
//		rebote(t, *l[i]);
//	}
//}

/*bool Interaccion::colision(Proyectil p, tanque t){
	Vector2D pos = p.getPos();
	if ((pos.x > t.getPos().x - 0.05f) && (pos.x < t.getPos().x + 0.05f) && (pos.y > t.getPos().y - 0.05f) && (pos.x < t.getPos().y + 0.05f)) {
		return true;
	}
	else 
		return false;
}*/

