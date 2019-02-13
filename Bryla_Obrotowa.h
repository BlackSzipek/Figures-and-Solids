#ifndef BRYLA_OBROTOWA_H_INCLUDED
#define BRYLA_OBROTOWA_H_INCLUDED
#include "Bryla.h"
#include "Kolo.h"
#include "Podstawa.h"

class Bryla_Obrotowa : public Bryla
{
protected:
    virtual void zapisz(std::ostream& o) const
    {
    }
    virtual void wczytaj(std::istream& i)
    {
    }
    Bryla_Obrotowa(void)=default;
public:
    Bryla_Obrotowa(std::shared_ptr <Kolo> k,double h);
    virtual double Objetosc()=0;
    virtual ~Bryla_Obrotowa();
};

#endif // BRYLA_OBROTOWA_H_INCLUDED
