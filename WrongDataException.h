#ifndef WRONGDATAEXCEPTION_H_INCLUDED
#define WRONGDATAEXCEPTION_H_INCLUDED
#include <iostream>
#include <exception>

class WrongDataException : public std::exception
{
private:
    std::string why_="Znaleziono element w zlym formacie";
public:
    WrongDataException(void);
    WrongDataException(const std::string why);
    virtual const char* what(void) const noexcept;
    ~WrongDataException() {}
};

#endif // WRONGDATAEXCEPTION_H_INCLUDED
