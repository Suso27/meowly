#pragma once
#include "Objeto.h"
class CajaMunicion :
    public Objeto
{
public:
    void aplicarEfecto(tanqueJugador& j);
    CajaMunicion();
};

