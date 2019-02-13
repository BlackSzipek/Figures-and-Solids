#include "Bryla.h"
#include "WrongInputException.h"


Bryla::Bryla(std::shared_ptr <Podstawa> p,double h) : p_(p), h_(h)
{
    if(p==0 || h==0)
        throw WrongInputException();
}
Bryla::~Bryla() {}
void Bryla::zapisz(std::ostream& o) const
{
    o << identyfikatorTypu() << std::endl;
    o <<*p_;
    o<<"<wysokosc>"<<std::endl;
    o <<h_<<std::endl;
    o<<"</wysokosc>"<<std::endl;
}
std::ostream& operator<<(std::ostream& o, Bryla& b)
{
    b.zapisz(o);
    return o;
}
void Bryla::wczytaj(std::istream& i)
{
    i>>*p_;
    i>>h_;
}

std::istream& operator>>(std::istream& i, Bryla& b)
{
    b.wczytaj(i);
    return i;
}
