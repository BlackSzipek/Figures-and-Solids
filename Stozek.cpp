#include "Stozek.h"
#include "WrongInputException.h"


Stozek::Stozek(std::shared_ptr<Kolo> k,double h):Bryla_Obrotowa(k,h)
{
    if(k==0 || h==0)
        throw WrongInputException();
}
/*virtual*/ const char* Stozek::identyfikatorTypu(void) const
{
    return identyfikator_typu_;
}
double Stozek::Objetosc()
{
    return (p_->Pole()*h_)/3;
}
const char* Stozek ::identyfikatorTypuEnd(void) const
{
    return identyfikator_typu_end_;
}
Stozek::~Stozek() {}

void Stozek::zapisz(std::ostream& o) const
{
    const char* s=identyfikatorTypuEnd();
    Bryla::zapisz(o);
    o <<s<<std::endl;
}

void Stozek::wczytaj(std::istream& i)
{
}

