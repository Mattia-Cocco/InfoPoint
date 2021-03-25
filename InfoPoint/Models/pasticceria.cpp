#include "pasticceria.h"


Pasticceria::Pasticceria(std::string pastRating, std::string pastOra, std::string pastOraChiu, std::string pastNome, std::string pastCitta, std::string pastDesc, std::string address, string spec, bool Caff):
    Locale(pastRating,pastOra,pastOraChiu, pastNome, pastCitta, pastDesc,address), specialita(spec), caffetteria(Caff)
{}

Pasticceria::Pasticceria(const Pasticceria &p):
    Locale(p),
    specialita(p.getSpecialita()),
    caffetteria(p.getCaffetteria())
{}

std::string Pasticceria::getTipo() const
{
    return "Pasticceria";
}

string Pasticceria::getSpecialita() const{
    return specialita;
}

bool Pasticceria::getCaffetteria() const{
    return caffetteria;
}

string Pasticceria::getInfo() const{
    string p=Locale::getInfo();
    return p.append("\nSpecialità: "+(getSpecialita()))
            .append("\nCaffetteria: ").append(getCaffetteria()? "Si":"No");
}
