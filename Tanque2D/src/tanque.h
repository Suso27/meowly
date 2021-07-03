#pragma once
#include "Vector2D.h"
#include "Proyectil.h"
#include "ListaProyectiles.h"
#include "ColorRGB.h"


class tanque {
protected:

	//float municion;
	float vel;
	int vida;
	float cadencia;//periodo con el que dispara
	float tRecarga=0;//tiempo que ha pasado desde el último disparo

	float daño;
	int nMaxRebotes = 2;
	float vProyectil = 3;


	ColorRGB color;

	Vector2D apuntado;
	Vector2D posicion;
	Vector2D velocidad;
	ListaProyectiles proyectiles;

public:

	friend class Interaccion;
	tanque();
	tanque(float x, float y);
	void Inicializa(float x,float y);
	void Dibuja();
	void Mueve(float t);
	void Dispara();
	void setVel(float vx, float vy);
	void setApuntado(float x, float y);
	void setApuntado(Vector2D);
	Vector2D getPos();
	void setDaño(int dmg);
	void setPos(float x, float y);
};

