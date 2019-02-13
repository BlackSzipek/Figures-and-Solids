#include "Podstawa.h"

Podstawa::~Podstawa() {};

std::ostream& operator<<(std::ostream& o, Podstawa& p)
{
    p.zapisz(o);
    return o;
}


std::istream& operator>>(std::istream& i, Podstawa& p)
{
    p.wczytaj(i);
    return i;
}
