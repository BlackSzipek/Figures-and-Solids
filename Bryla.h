#ifndef BRYLA_H_INCLUDED
#define BRYLA_H_INCLUDED
#include <memory>
#include "Podstawa.h"

class Bryla
{
protected:
    std::shared_ptr<Podstawa> p_;
    double h_;
protected:
    virtual void zapisz(std::ostream& o) const;
    virtual void wczytaj(std::istream& i);
    Bryla()=default;
public:
    Bryla(std::shared_ptr <Podstawa> p,double h);
    virtual const char* identyfikatorTypu(void) const = 0;
    virtual const char* identyfikatorTypuEnd(void) const = 0;
    virtual double Objetosc()=0;
    virtual ~Bryla();
    friend
    std::ostream& operator<<(std::ostream& o, Bryla& b);

    friend
    std::istream& operator>>(std::istream& i, Bryla& b);
};

#endif // BRYLA_H_INCLUDED
