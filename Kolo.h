#ifndef KOLO_H_INCLUDED
#define KOLO_H_INCLUDED
#include "Podstawa.h"
#define pi 3.14

class Kolo : public Podstawa
{
private:
    double r_;
protected:
    /*virtual*/
    void zapisz(std::ostream& o) const override;
    /*virtual*/ void wczytaj(std::istream& i) override;
public:
    static constexpr const char* identyfikator_typu_ = "<kolo>";
    static constexpr const char* identyfikator_typu_end_ = "</kolo>";
    /*virtual*/
    const char* identyfikatorTypu(void) const override;
    /*virtual*/ const char* identyfikatorTypuEnd(void) const override;
    Kolo(double r);
    Kolo(void)=default;
    double Pole() override;
    ~Kolo();
};

#endif // KOLO_H_INCLUDED
