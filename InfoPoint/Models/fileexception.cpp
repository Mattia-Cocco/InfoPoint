#include "fileexception.h"

FileException::FileException(std::string e):Excep(e){}


std::string FileException::getExcep() const
{
    return Excep;
}

void FileException::PrintError() const
{
    std::cout<<"si è verificato error :"<<getExcep();
}

