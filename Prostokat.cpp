#include "Prostokat.h"
#include "Podstawa.h"
#include "WrongInputException.h"

Prostokat::Prostokat(double a, double b) : a_(a),b_(b)
{
    if(a==0 || b==0)
        throw WrongInputException();
}
/*virtual*/ const char* Prostokat::identyfikatorTypu(void) const
{
    return identyfikator_typu_;
}

const char* Prostokat::identyfikatorTypuEnd(void) const
{
    return identyfikator_typu_end_;
}
void Prostokat::zapisz(std::ostream& o) const
{
    const char* s=identyfikatorTypuEnd();
    Podstawa::zapisz(o);
    o << a_ << " " << b_<< std::endl;
    o <<s<<std::endl;
}

/*virtual*/ void Prostokat::wczytaj(std::istream& i)
{
    i >> a_ >> b_;
}
double Prostokat::Pole()
{
    return a_*b_;
}
Prostokat::~Prostokat() {}
