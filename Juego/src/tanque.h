#pragma once
#include "ListaProyectiles.h"


class tanque {
protected:

	//float municion;
	float vel = 0.04f;
	int vida =1;
	int vidaMax = 10;
	float cadencia = 1.0f;//periodo con el que dispara
	float tRecarga= 0.0f;//tiempo que ha pasado desde el último disparo

	int daño = 1;
	int nMaxRebotes = 2;
	float vProyectil = 3;
	const char* s= "imagenes/Jugador.png";

	ColorRGB color;
	Vector2D apuntado;
	Vector2D posicion;
	Vector2D velocidad;
	ListaProyectiles proyectiles;

public:

	friend class Interaccion;
	tanque();
	tanque(float x, float y, const char*);
	//virtual void Inicializa(float x,float y)=0;
	void Dibuja() const;
	void Mueve(float t);
	void Dispara();
	void setVel(float vx, float vy);
	void aumentarVel();

	void aumentarVproyectil(int v);

	void setApuntado(float x, float y);
	void setApuntado(Vector2D);

	Vector2D getPos() const;
	void setPos(float x, float y);

	void setDaño(int dmg);
	void aumentarDaño();

	void setVidaMax(int vida);
	int getVidaMax() const;
	void aumentarVidaMax();

	void aumentarVida();
	int getVidaActual() const;

	float getvProyectil();
	void setvProyectil(float vel); //ahora mismo los set no se usan, solo los de aumentar

	int getnMaxRebotes();
	void aumentarnMaxRebotes();
	
	
	void dibujaImg(const char* c, float l1x, float l1y, float l2x, float l2y);
};

