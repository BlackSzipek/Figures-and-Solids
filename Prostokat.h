#ifndef PROSTOKAT_H_INCLUDED
#define PROSTOKAT_H_INCLUDED
#include "Podstawa.h"

class Prostokat : public Podstawa
{
private:
    double a_;
    double b_;
protected:
    /*virtual*/
    void zapisz(std::ostream& o) const override;
    /*virtual*/ void wczytaj(std::istream& i) override;
public:
    static constexpr const char* identyfikator_typu_ = "<prostokat>";
    static constexpr const char* identyfikator_typu_end_ = "</prostokat>";
    /*virtual*/
    const char* identyfikatorTypu(void) const override;
    /*virtual*/ const char* identyfikatorTypuEnd(void) const override;
    Prostokat(double a, double b);
    Prostokat(void)=default;
    double Pole() override;
    ~Prostokat();
};

#endif // PROSTOKAT_H_INCLUDED
