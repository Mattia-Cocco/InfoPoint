#include "discobar.h"

Discobar::Discobar(std::string DBtRating, std::string DBOra, std::string DBChiusura, std::string DBNome, std::string DBCitta, std::string DBDesc,std::string DBaddress, bool DBposti, bool DBing, unsigned int DBP_ing, string DBCosto_drink):
    Locale(DBtRating, DBOra, DBChiusura, DBNome, DBCitta, DBDesc, DBaddress), Bar(DBtRating, DBOra, DBChiusura, DBNome, DBCitta, DBDesc, DBaddress, DBposti), Discoteca(DBtRating, DBOra, DBChiusura, DBNome, DBCitta, DBDesc, DBaddress, DBing, DBP_ing),
    costo_drink(DBCosto_drink) {}


Discobar::Discobar(const Discobar& DB):
    Locale(DB), Bar(DB), Discoteca(DB), costo_drink(DB.getCosto_drink()){}


string Discobar::getInfo() const{
  string b=Locale::getInfo();

    return b.append("\nPosti a sedere: ")
            .append((getPostiASedere()? "Si":"No"))
            .append("\nSi paga l'ingresso: ")
            .append((getIngresso()? "Si":"No"))
            .append(("\nPrezzo di ingresso: "+std::to_string(getP_ing())+" euro"))
            .append("\nI drink costano dai: "+getCosto_drink()+" euro");
}

std::string Discobar::getTipo() const{
    return "Discobar";
}


string Discobar::getCosto_drink() const{
    return costo_drink;
}



