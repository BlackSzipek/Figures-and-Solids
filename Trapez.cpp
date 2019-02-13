#include "Trapez.h"
#include "WrongInputException.h"

Trapez::Trapez(double a, double b,double h):a_(a),b_(b),h_(h)
{
    if(a==0 || b==0 || h==0)
        throw WrongInputException();
}
/*virtual*/ const char* Trapez::identyfikatorTypu(void) const
{
    return identyfikator_typu_;
}
const char* Trapez::identyfikatorTypuEnd(void) const
{
    return identyfikator_typu_end_;
}
double Trapez::Pole()
{
    return ((a_+b_)*h_)*0.5;
}
/*virtual*/ void Trapez::zapisz(std::ostream& o) const
{
    const char* s=identyfikatorTypuEnd();
    Podstawa::zapisz(o);
    o << a_ << " " << b_<<" "<<h_<<std::endl;
    o <<s<<std::endl;
}
/*virtual*/ void Trapez::wczytaj(std::istream& i)
{
    i >> a_ >> b_>> h_;
}
Trapez::~Trapez() {}
