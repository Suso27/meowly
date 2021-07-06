#pragma once
#include "Proyectil.h"
class ProyectilCañon :
    public Proyectil
{
public:
    ProyectilCañon(Vector2D, Vector2D, int d, int n, float velModulo);
};

