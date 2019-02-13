#ifndef OSTROSLUP_H_INCLUDED
#define OSTROSLUP_H_INCLUDED
#include "Bryla.h"

class Ostroslup : public Bryla
{
protected:
    virtual void zapisz(std::ostream& o) const override;
    virtual void wczytaj(std::istream& i) override;
public:
    static constexpr const char* identyfikator_typu_ = "<ostroslup>";
    /*virtual*/ const char* identyfikatorTypu(void) const override;
    static constexpr const char* identyfikator_typu_end_ = "</ostroslup>";
    /*virtual*/ const char* identyfikatorTypuEnd(void) const override;
    Ostroslup(std::shared_ptr<Podstawa> p,double w);
    Ostroslup(void)=default;
    double Objetosc() override;
    ~Ostroslup();
};

#endif // OSTROSLUP_H_INCLUDED
