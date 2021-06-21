#pragma once
#include "Vector2D.h"
#include <ctime>
#include "ColorRGB.h"
class Objeto
{
	friend class Interaccion;
protected:
	Vector2D posicion;
	ColorRGB color;
public:
	Vector2D getPos();
	//intentar meter el setPos(vector2D)
	void setPos(Vector2D pos);
	Objeto();
	void dibuja();
	float distancia(Vector2D punto);
};

