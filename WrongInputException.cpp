#include "WrongInputException.h"


WrongInputException::WrongInputException(void)
{
    std::cout<<"WrongInputException"<<std::endl;
}

WrongInputException::WrongInputException(const std::string why)
{
    std::cout<<"WrongInputException-proba zainicjalizowania obiektu ze zlymi wartosciami : "<<why<<std::endl;
}

const char* WrongInputException::what(void) const noexcept
{
    return why_.c_str();
}
