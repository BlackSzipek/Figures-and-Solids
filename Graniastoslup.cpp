#include "Graniastoslup.h"
#include "WrongInputException.h"

Graniastoslup::Graniastoslup(std::shared_ptr<Podstawa> p,double w) : Bryla(p,w)
{
    if(p==0 || w==0)
        throw WrongInputException();
}

/*virtual*/ const char* Graniastoslup::identyfikatorTypu(void) const
{
    return identyfikator_typu_;
}
void Graniastoslup::zapisz(std::ostream& o) const
{
    const char* s=identyfikatorTypuEnd();
    Bryla::zapisz(o);
    o <<s<<std::endl;
}

void Graniastoslup::wczytaj(std::istream& i)
{
}

const char* Graniastoslup::identyfikatorTypuEnd(void) const
{
    return identyfikator_typu_end_;
}
double Graniastoslup::Objetosc()
{
    return p_->Pole()*h_;
}
Graniastoslup::~Graniastoslup() {}
