#ifndef STOZEK_H_INCLUDED
#define STOZEK_H_INCLUDED
#include "Bryla_Obrotowa.h"
#include "Kolo.h"
#include "Podstawa.h"

class Stozek : public Bryla_Obrotowa
{
protected:
    virtual void zapisz(std::ostream& o) const override;
    virtual void wczytaj(std::istream& i) override;
public:
    static constexpr const char* identyfikator_typu_ = "<stozek>";
    /*virtual*/ const char* identyfikatorTypu(void) const override;
    static constexpr const char* identyfikator_typu_end_ = "</stozek>";
    /*virtual*/ const char* identyfikatorTypuEnd(void) const override;
    Stozek(std::shared_ptr<Kolo> k,double h);
    Stozek(void)=default;
    virtual double Objetosc() override;
    ~Stozek();
};


#endif // STOZEK_H_INCLUDED
