#ifndef WRONGINPUTEXCEPTION_H_INCLUDED
#define WRONGINPUTEXCEPTION_H_INCLUDED
#include <iostream>
#include <exception>

class WrongInputException : public std::exception
{
private:
    std::string why_="Podano zle dane";
public:
    WrongInputException(void);
    WrongInputException(const std::string why);
    virtual const char* what(void) const noexcept;
    ~WrongInputException() {}
};

#endif // WRONGINPUTEXCEPTION_H_INCLUDED
