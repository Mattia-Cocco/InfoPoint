#ifndef FILEEXCEPTION_H
#define FILEEXCEPTION_H
#include<iostream>

class FileException
{
    std::string Excep;
public:
    FileException(std::string);
    std::string getExcep()const;
    void PrintError()const;
};

#endif // FILEEXCEPTION_H
