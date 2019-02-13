#include "Ostroslup.h"
#include "WrongInputException.h"

Ostroslup::Ostroslup(std::shared_ptr<Podstawa> p,double w) : Bryla(p,w)
{
    if(p==0 || w==0)
        throw WrongInputException();
}
/*virtual*/ const char* Ostroslup::identyfikatorTypu(void) const
{
    return identyfikator_typu_;
}
const char* Ostroslup::identyfikatorTypuEnd(void) const
{
    return identyfikator_typu_end_;
}
double Ostroslup::Objetosc()
{
    return (p_->Pole()*h_)/3;
}
void Ostroslup::zapisz(std::ostream& o) const
{
    const char* s=identyfikatorTypuEnd();
    Bryla::zapisz(o);
    o <<s<<std::endl;
}

void Ostroslup::wczytaj(std::istream& i)
{
    Bryla::wczytaj(i);
}
Ostroslup::~Ostroslup() {}
