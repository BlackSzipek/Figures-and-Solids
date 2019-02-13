#include "FileNotFoundException.h"

    FileNotFoundException::FileNotFoundException(void)
    {
        std::cout<<"FileNotFoundException"<<std::endl;
    }
    FileNotFoundException::FileNotFoundException(const std::string why)
    {
        std::cout<<"FileNotFoundException"<<std::endl;
        std::string s=" ";
        why_=why_+s+why;
    }
    const char* FileNotFoundException::what(void) const noexcept
    {
        return why_.c_str();
    }
