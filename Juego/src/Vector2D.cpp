#include "Vector2D.h"

Vector2D::Vector2D(float xv, float yv)
{
	x = xv;
	y = yv;
}

Vector2D::~Vector2D(){}

float Vector2D::modulo() const
{
	return (float)sqrt(pow(x,2) + pow(y,2));
}

float Vector2D::argumento() const
{
	return (float)atan2(y, x);
}

Vector2D Vector2D::unitario()
{
	Vector2D retorno(x, y);
	float mod = modulo();
	if (mod > 0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	else {
		retorno.x = 1.0f;
		retorno.y = 0.0f;
	}
	return retorno;
}

//Vector2D Vector2D::unitario()
//{
//	float mod = modulo();
//	x /= mod;
//	y /= mod;
//	return *this;
//}


Vector2D Vector2D::operator - (Vector2D v) const
{
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}
Vector2D Vector2D::operator + (Vector2D v) const
{
	Vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}

Vector2D Vector2D::operator*(float k) const
{
	Vector2D res;
	res.x = k*x;
	res.y = k*y;
	return res;
}

Vector2D Vector2D::operator/(float k) const
{
	Vector2D res;
	res.x = x / k;
	res.y = y / k;
	return res;
}

float Vector2D::operator*(Vector2D v) const
{
	float res;
	res = x*v.x + y*v.y;
	return res;
}

void Vector2D::operator*=(float k) {
	x *= k;
	y *= k;
}

//
//Vector2D Vector2D::sumarAngulo(float a) {
//	float aux = x;
//	x = (x + y) * cos(a);
//	y = (aux + y) * sin(a);
//	return *this;
//}