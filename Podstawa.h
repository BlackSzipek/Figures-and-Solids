#ifndef PODSTAWA_H_INCLUDED
#define PODSTAWA_H_INCLUDED
#include <iostream>
class Podstawa
{
protected:
    Podstawa()=default;
    virtual void zapisz(std::ostream& o) const
    {
        o << identyfikatorTypu() << std::endl;
    }
    virtual void wczytaj(std::istream& i)
    {
    }
public:
    virtual const char* identyfikatorTypu(void) const = 0;
    virtual const char* identyfikatorTypuEnd(void) const = 0;
    virtual double Pole()=0;
    virtual ~Podstawa();
    friend
    std::ostream& operator<<(std::ostream& o, Podstawa& p);

    friend
    std::istream& operator>>(std::istream& i, Podstawa& p);
};


#endif // PODSTAWA_H_INCLUDED
