#pragma once
#include "Vector2D.h"

class Proyectil
{
	friend class Interaccion;
private:
	float radio;
	int rebotes;

	Vector2D posicion;
	Vector2D posicionTmenos;
	Vector2D velocidad;
	//int daño;
public:
	Proyectil();
	Proyectil(Vector2D,Vector2D);
	virtual ~Proyectil();
	void dibuja();
	void mueve(float);
	void setPos(Vector2D);
	//void setVel(Vector2D apuntando);
	//bool getDisparado();//también innecesario
	void setDaño(int dmg);
	Vector2D getPos();
};

