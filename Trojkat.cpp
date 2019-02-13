#include "Trojkat.h"
#include "WrongInputException.h"

Trojkat::Trojkat(double a, double h):a_(a),h_(h)
{
    if(a==0 || h==0)
        throw WrongInputException();
}
/*virtual*/ const char* Trojkat::identyfikatorTypu(void) const
{
    return identyfikator_typu_;
}

const char* Trojkat::identyfikatorTypuEnd(void) const
{
    return identyfikator_typu_end_;
}
/*virtual*/ void Trojkat::zapisz(std::ostream& o) const
{
    const char* s=identyfikatorTypuEnd();
    Podstawa::zapisz(o);
    o << a_ << " " << h_<< std::endl;
    o <<s<<std::endl;
}
/*virtual*/ void Trojkat::wczytaj(std::istream& i)
{
    i >> a_ >> h_;
}
double Trojkat::Pole()
{
    return (a_*h_)/2;
}
Trojkat::~Trojkat() {}

