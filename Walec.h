#ifndef WALEC_H_INCLUDED
#define WALEC_H_INCLUDED
#include "Bryla_Obrotowa.h"

class Walec : public Bryla_Obrotowa
{
protected:
    virtual void zapisz(std::ostream& o) const override;
    virtual void wczytaj(std::istream& i) override;
public:
    static constexpr const char* identyfikator_typu_ = "<walec>";
    /*virtual*/ const char* identyfikatorTypu(void) const override;
    static constexpr const char* identyfikator_typu_end_ = "</walec>";
    /*virtual*/ const char* identyfikatorTypuEnd(void) const override;
    Walec(std::shared_ptr<Kolo> k,double h);
    Walec(void)=default;
    virtual double Objetosc() override;
    ~Walec();
};


#endif // WALEC_H_INCLUDED
