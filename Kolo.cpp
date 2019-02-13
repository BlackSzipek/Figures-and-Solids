#include "Kolo.h"
#include "WrongInputException.h"

Kolo::Kolo(double r) : r_(r)
{
    if(r==0)
        throw WrongInputException();
}
/*virtual*/ const char* Kolo::identyfikatorTypu(void) const
{
    return identyfikator_typu_;
}
const char* Kolo::identyfikatorTypuEnd(void) const
{
    return identyfikator_typu_end_;
}
/*virtual*/ void Kolo::zapisz(std::ostream& o) const
{
    const char* s=identyfikatorTypuEnd();
    Podstawa::zapisz(o);
    o << r_ <<std::endl;
    o <<s<<std::endl;
}
/*virtual*/ void Kolo::wczytaj(std::istream& i)
{
    i >> r_;
}
double Kolo::Pole()
{
    return pi*r_*r_;
}
Kolo::~Kolo() {}
