#include "ristoranti.h"



Ristorante::Ristorante(std::string Ristorating, std::string RistoOraApertura, std::string RistoraChiusura, std::string Ristnome, std::string Ristocitta, std::string RistoDesc,std::string address, bool feeCoperto):
    Locale(Ristorating,RistoOraApertura,RistoraChiusura,Ristnome,Ristocitta,RistoDesc, address),coperto(feeCoperto)
{

}

Ristorante::Ristorante(const Ristorante&r):
    Locale(r),
    coperto(r.getCoperto())
{}


std::string Ristorante::getTipo() const
{
    return "Ristorante";
}

bool Ristorante::getCoperto() const
{

    return coperto;
}


string Ristorante::getInfo() const
{
    string s=Locale::getInfo();
    return s.append("\nCoperto: ")
       .append((getCoperto()? "Si":"No"));

}


