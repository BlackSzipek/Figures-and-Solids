#include "VectorIsEmptyException.h"

    VectorIsEmptyException::VectorIsEmptyException(void)
    {
        std::cout<<"VectorIsEmptyException"<<std::endl;
    }
    VectorIsEmptyException::VectorIsEmptyException(const std::string why)
    {
        std::cout<<"VectorIsEmptyException"<<std::endl;
        std::string s=" ";
        why_=why_+s+why;
    }
    const char* VectorIsEmptyException::what(void) const noexcept
    {
        return why_.c_str();
    }
