#ifndef TROJKAT_H_INCLUDED
#define TROJKAT_H_INCLUDED
#include "Podstawa.h"

class Trojkat : public Podstawa
{
private:
    double a_;
    double h_;
protected:
    /*virtual*/
    void zapisz(std::ostream& o) const override;
    /*virtual*/ void wczytaj(std::istream& i) override;
public:
    static constexpr const char* identyfikator_typu_ = "<trojkat>";
    static constexpr const char* identyfikator_typu_end_ = "</trojkat>";
    /*virtual*/
    const char* identyfikatorTypu(void) const override;
    /*virtual*/ const char* identyfikatorTypuEnd(void) const override;
    Trojkat(double a, double h);
    Trojkat(void)=default;
    double Pole() override;
    ~Trojkat();
};

#endif // TROJKAT_H_INCLUDED
