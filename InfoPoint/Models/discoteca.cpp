#include "discoteca.h"



Discoteca::Discoteca(std::string discoRating, std::string discoOra, std::string discoOraChiu, std::string discoNome, std::string discoCitta, std::string discoDesc,std::string address,bool entry, unsigned int p_ing):
    Locale(discoRating,discoOra, discoOraChiu,discoNome,discoCitta, discoDesc,address),ingresso(entry), prezzo_ingresso(p_ing)
{
    if(ingresso==false)
        prezzo_ingresso=0;
}

Discoteca::Discoteca(const Discoteca&d):
    Locale(d),
    ingresso(d.getIngresso())
{

}

std::string Discoteca::getTipo() const
{
    return "Discoteca";
}

bool Discoteca::getIngresso() const
{
    return ingresso;
}

unsigned int Discoteca::getP_ing() const{
    return prezzo_ingresso;
}

string Discoteca::getInfo() const
{
    string s=Locale::getInfo();
    return s.append("\nIngresso a pagamento: ")
       .append((getIngresso()? "Si":"No"))
       .append(("\nPrezzo di ingresso: "+std::to_string(getP_ing())));

}
