#include "WrongDataException.h"

WrongDataException::WrongDataException(void)
{
    std::cout<<"WrongDataException"<<std::endl;
}

WrongDataException::WrongDataException(const std::string why)
{
    std::cout<<"WrongDataException-element o zlym formacie : "<<why<<std::endl;
}

const char* WrongDataException::what(void) const noexcept
{
    return why_.c_str();
}
