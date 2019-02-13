#ifndef GRANIASTOSLUP_H_INCLUDED
#define GRANIASTOSLUP_H_INCLUDED
#include "Bryla.h"

class Graniastoslup : public Bryla
{
protected:
    virtual void zapisz(std::ostream& o) const override;
    virtual void wczytaj(std::istream& i) override;
public:
    static constexpr const char* identyfikator_typu_ = "<graniastoslup>";
    /*virtual*/ const char* identyfikatorTypu(void) const override;
    static constexpr const char* identyfikator_typu_end_ = "</graniastoslup>";
    /*virtual*/ const char* identyfikatorTypuEnd(void) const override;
    Graniastoslup(std::shared_ptr<Podstawa> p,double w);
    Graniastoslup(void)=default;
    double Objetosc() override;
    ~Graniastoslup();
};

#endif // GRANIASTOSLUP_H_INCLUDED
