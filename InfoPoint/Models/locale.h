#ifndef LOCATION_H
#define LOCATION_H
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>


using std::string;
class Locale{
private:

    string rating;
    string oraApertura;
    string oraChiusura;
    string nome;
    string citta;
    string descrizione;
    string indirizzo;

public:
    Locale(string="", string="",string="",string="",string="",string="", string="");
    Locale(const Locale&);


    // metodi getter
    string getRating() const;
    string getDescrizione() const;
    string getNome() const;
    string getCitta() const;
    string getOraApertura() const;
    string getOraChiusura() const;
    string getIndirizzo() const;


    // Metodi setter
    void setnome(string);
    void setCitta(string);
    void setDescrizione(const string &value);
    void setIndirizzo(const string &value);
    void setOraApertura(string );
    void setOraChiusura(string );

    virtual string getInfo() const;

    // metodo virtuale puro
    virtual string getTipo()const=0;


    //Distruttore virtuale
    virtual ~Locale()=default;

};

 std::ostream& operator<<(std::ostream& , const Locale& );
#endif
