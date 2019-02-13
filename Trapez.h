#ifndef TRAPEZ_H_INCLUDED
#define TRAPEZ_H_INCLUDED
#include "Podstawa.h"

class Trapez : public Podstawa
{
private:
    double a_;
    double b_;
    double h_;
protected:
    /*virtual*/
    void zapisz(std::ostream& o) const override;
    /*virtual*/ void wczytaj(std::istream& i) override;
public:
    static constexpr const char* identyfikator_typu_ = "<trapez>";
    static constexpr const char* identyfikator_typu_end_ = "</trapez>";
    /*virtual*/
    const char* identyfikatorTypu(void) const override;
    /*virtual*/ const char* identyfikatorTypuEnd(void) const override;
    Trapez(double a, double b,double h);
    Trapez(void)=default;
    double Pole() override;
    ~Trapez();
};

#endif // TRAPEZ_H_INCLUDED
