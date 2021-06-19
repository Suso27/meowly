#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class Pared
{
private:
	ColorRGB color;
	Vector2D limite1;
	Vector2D limite2;

public:
	Pared();
	virtual ~Pared();
	void Dibuja() const;
	void setPos(float, float, float, float);
	void setColor(char, char, char);
	float distancia(Vector2D punto, Vector2D* direccion = 0);

	friend class Interaccion;
};

