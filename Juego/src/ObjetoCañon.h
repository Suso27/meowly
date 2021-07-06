#pragma once
#include "Objeto.h"
class ObjetoCañon :
    public Objeto
{
public:
    ObjetoCañon();
    void aplicarEfecto(tanqueJugador& j);

};

