#include "Bryla_Obrotowa.h"
#include "WrongInputException.h"

Bryla_Obrotowa::Bryla_Obrotowa(std::shared_ptr <Kolo> k,double h) : Bryla(k,h)
{
    if(k==0 || h==0)
        throw WrongInputException();
}
Bryla_Obrotowa::~Bryla_Obrotowa() {}
