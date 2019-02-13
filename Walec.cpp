#include "Walec.h"
#include "WrongInputException.h"

Walec::Walec(std::shared_ptr<Kolo> k,double h):Bryla_Obrotowa(k,h)
{
    if(k==0 || h==0)
        throw WrongInputException();
}
/*virtual*/ const char* Walec::identyfikatorTypu(void) const
{
    return identyfikator_typu_;
}
const char* Walec::identyfikatorTypuEnd(void) const
{
    return identyfikator_typu_end_;
}
double Walec::Objetosc()
{
    return p_->Pole()*h_;
}
Walec::~Walec() {}

void Walec::zapisz(std::ostream& o) const
{
    const char* s=identyfikatorTypuEnd();
    Bryla::zapisz(o);
    o <<s<<std::endl;
}

void Walec::wczytaj(std::istream& i)
{
}
