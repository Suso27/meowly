#pragma once
#include "Vector2D.h"
#include "Proyectil.h"
#include "ListaProyectiles.h"
#include "ColorRGB.h"

class tanque {
protected:

	float municion;
	float vel;
	ColorRGB color;

	ListaProyectiles proyectiles;
	Vector2D apuntado;
	Vector2D posicion;
	Vector2D velocidad;

public:
	friend class Interaccion;
	tanque();
	void Inicializa();
	void Dibuja();
	void Mueve(float t);
	//void Interacciona(Caja& c);
	//void Interacciona(ListaCajas c);
	void Dispara();
	void setVel(float vx, float vy);
	void setApuntado(float x, float y);
	void setApuntado(Vector2D);
	Vector2D getPos();
};

