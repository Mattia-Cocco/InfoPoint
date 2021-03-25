#ifndef Pasticceria_H
#define Pasticceria_H
#include "locale.h"


class Pasticceria: public Locale
{
private:
    string specialita;
    bool caffetteria;
public:
    Pasticceria(string="", string="",string="",string="",string="",string="",string="", string="", bool=false);
    Pasticceria(const Pasticceria&);

    virtual ~Pasticceria() override=default;
    virtual string getTipo()const override;
    virtual string getInfo() const override ;

    string getSpecialita()const;
    bool getCaffetteria()const;


};

#endif // Pasticceria_H
