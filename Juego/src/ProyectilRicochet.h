#pragma once
#include "Proyectil.h"
class ProyectilRicochet :
    public Proyectil
{
public:
    ProyectilRicochet(Vector2D, Vector2D, int d, int n, float velModulo);
};

