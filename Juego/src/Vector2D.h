#pragma once
#include <math.h>

class Vector2D
{
public:
	float x;
	float y;

public:
	Vector2D(float xv = 0.0f, float yv = 0.0f); // (1)constructor
	~Vector2D();
	float modulo() const; // (2) modulo del vector
	float argumento() const; // (3) argumento del vector
	Vector2D unitario(); // (4) devuelve un vector unitario
	Vector2D operator - (Vector2D) const; // (5) resta de vectores
	Vector2D operator + (Vector2D) const; // (6) suma de vectores
	float operator *(Vector2D) const; // (7) producto escalar
	Vector2D operator *(float) const; // (8) producto por un escalar
	Vector2D operator /(float) const;
	void operator *=(float) ;
	//Vector2D sumarAngulo(float a);
};

