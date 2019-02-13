#ifndef FILENOTFOUNDEXCEPTION_H_INCLUDED
#define FILENOTFOUNDEXCEPTION_H_INCLUDED
#include <exception>
#include <iostream>

class FileNotFoundException : public std::exception
{
private:
    std::string why_="Nie znaleziono pliku";
public:
    FileNotFoundException(void);
    FileNotFoundException(const std::string why);
    virtual const char* what(void) const noexcept;
    ~FileNotFoundException() {}

};


#endif // FILENOTFOUNDEXCEPTION_H_INCLUDED
