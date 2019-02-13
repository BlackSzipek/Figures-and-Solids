#ifndef VECTORISEMPTYEXCEPTION_H_INCLUDED
#define VECTORISEMPTYEXCEPTION_H_INCLUDED
#include <exception>
#include <iostream>

class VectorIsEmptyException
{
private:
    std::string why_="Podany wektor jest pusty";
public:
    VectorIsEmptyException(void);
    VectorIsEmptyException(const std::string why);
    virtual const char* what(void) const noexcept;
    ~VectorIsEmptyException() {}

};


#endif // VECTORISEMPTYEXCEPTION_H_INCLUDED
