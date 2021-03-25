#include "bar.h"



Bar::Bar(std::string bartRating, std::string barOra, std::string barChiusura, std::string barNome, std::string BarCitta, std::string barDesc, std::string address, bool posti):
    Locale(bartRating, barOra, barChiusura, barNome, BarCitta,barDesc,address), postiASedere(posti)
{}

Bar::Bar(const Bar &b):
    Locale (b),
    postiASedere(b.getPostiASedere()){}

std::string Bar::getTipo() const
{
    return"Bar";
}

bool Bar::getPostiASedere() const
{
    return postiASedere;
}


string Bar::getInfo() const {
    string s=Locale::getInfo();
    return s.append("\nPosti a sedere: ")
            .append((getPostiASedere()? "Si":"No"));

}

