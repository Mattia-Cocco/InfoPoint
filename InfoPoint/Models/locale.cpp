#include "locale.h"


//using namespace std;



Locale::Locale(string r,string oraA,string oraC, string n, string c,string desc, string address):
    rating(r),oraApertura(oraA),oraChiusura(oraC) ,nome(n),citta(c), descrizione(desc),indirizzo(address){}

Locale::Locale(const Locale &l):
    rating(l.getRating()),
    oraApertura(l.getOraApertura()),
    oraChiusura(l.getOraChiusura()),
    nome(l.getNome()),
    citta(l.getCitta()),
    descrizione(l.getDescrizione()),
    indirizzo(l.getIndirizzo()){}


void Locale::setnome(std::string lname)
{
    nome = lname;
}

void Locale::setCitta(std::string lcitta)
{
    citta= lcitta;
}

void Locale::setDescrizione(const std::string &lDesc)
{
    descrizione = lDesc;
}

void Locale::setIndirizzo(const std::string &value)
{
    indirizzo=value;
}

void Locale::setOraApertura(std::string lOraApertura)
{
    oraApertura = lOraApertura;
}

void Locale::setOraChiusura(std::string lOraChiusura)
{
    oraChiusura = lOraChiusura;
}

// implementazioni dei metodi getter
string Locale::getRating() const
{
    return rating;
}

std::string Locale::getDescrizione() const
{
    return descrizione;
}

std::string Locale::getNome() const
{
    return nome;
}

std::string Locale::getCitta() const
{
    return citta;
}

std::string  Locale::getOraApertura() const
{
    return oraApertura;
}

std::string  Locale::getOraChiusura() const
{
    return oraChiusura;
}

std::string Locale::getIndirizzo() const
{
    return indirizzo;
}

std::string Locale::getInfo() const
{
    string s="";
    return s.append("\nNome:  " +getNome())
             .append("\nTipo:  " +getTipo())
            .append("\nDescrizione:  "+ getDescrizione())
            .append("\nValutazione:  " + getRating())
            .append("\nApre alle:  " +  getOraApertura())
            .append("\nChiude alle: " + getOraChiusura())
            .append("\nCittà: "+  getCitta())
            .append("\nIndirizzo: "+  getIndirizzo());

}

std::ostream &operator <<(std::ostream &os,const Locale & l ){

    return os << "Nome: " << l.getNome() << "\nTipo locale: " << l.getTipo() << "\nDescrizione; " << l.getDescrizione() << "\n Valutazione: " << l.getRating()
                << "\n Apre alle: " << l.getOraApertura() << "\n Chiude alle : " << l.getOraChiusura() << "\n Città : " << l.getCitta()<<"\nIndirizzo: "<<l.getIndirizzo();
}


